#include "parser.h"

Parser::Parser(QVector<QStringList>& dt, QObject *parent)
    : QObject{parent}
    , dtModel{dt}
{
    this->manager = new QNetworkAccessManager(this);
    connect(this->manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void Parser::loadSite(const QPair<QString, QString>& address)
{
    this->site = std::move(address);
    if(!this->site.first.contains("-"))
    {
        QNetworkReply *reply = this->manager->get(QNetworkRequest(QUrl(QString(site.second))));
        QEventLoop loop;

        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

        loop.exec();
    }
}

void Parser::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray content = reply->readAll();
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        this->page = codec->toUnicode(content.data());

        if(reply->url() == QUrl(site.second))
        {
            this->getMainContent();
        }
        else{
            this->parsePageElement();
        }
    }else{
        qDebug() << reply->error();
    }

    reply->deleteLater();
}

void Parser::getMainContent()
{
    if(this->site.first.contains("avito"))
    {
        int start   = page.indexOf("<div class=\"items-items-kAJAg\" data-marker=\"catalog-serp\">");
        int end     = page.indexOf("<div class=\"js-pages pagination-pagination-_FSNE\">", start);
        this->page  = page.mid(start, end-start);
        this->getReferencesAvito();
    }
}

void Parser::getReferencesAvito()
{
    QString strStart = "<a class=\"iva-item-sliderLink-uLz1v\" itemProp=\"url\" href=";
    int len = strStart.size()+1;
    QString strEnd   = "target=\"_blank\" title=";
    int start   = page.indexOf(strStart);
    int end     = page.indexOf(strEnd, start+len);

    while(start != -1)
    {
        QString reference = QString("https://www.avito.ru") + page.mid(start + len, end-start-len-2);
        this->ref.push_back(reference);
        start = end;
        start   = page.indexOf(strStart, start);
        end     = page.indexOf(strEnd, start+len);
    }

    int size = ref.size();
    for(int i = 0; i < size; ++i)
    {
        QNetworkReply *reply = this->manager->get(QNetworkRequest(QUrl(ref[i])));
        QEventLoop loop;
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
    }
}

void Parser::parsePageElement()
{

    int start = this->page.indexOf(R"(<div data-marker="item-view/item-params" class="">)");
    int len = QString(R"(<div data-marker="item-view/item-params" class="">)").size();

    int end   = this->page.indexOf("<div class=\"params-specification-__5qD\">", start+len);
    QString content = this->page.mid(start+len, end-start-len);

    QStringList d;
    start = content.indexOf("<span class=\"desktop-3a1zuq\">");
    len = QString(R"(<!-- -->: </span>)").size();
    int lenEnd = QString(R"(</li>)").size();
    while(true){
        start = content.indexOf(R"(<!-- -->: </span>)", start);
        if(start == -1)
            break;

        end = content.indexOf(R"(</li>)", start);
        QString tmp = content.mid(start+len, end-start-len);
        if(tmp.contains(R"(<a href)")){
            int s = tmp.indexOf(">");
            int e   = tmp.indexOf("</a>", s);
            d.push_back(tmp.mid(s+1, e-s-1));
            start = end;
            continue;
        }
        d.push_back(tmp);
        start = end+lenEnd;
    }

    if(d.size() == 9)
        this->dtModel.push_back(d);
}
