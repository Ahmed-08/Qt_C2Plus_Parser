#ifndef PARSER_H
#define PARSER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTextCodec>
#include <QEventLoop>
#include <QTimer>


class Parser : public QObject
{
    Q_OBJECT
public:
    Parser(QVector<QStringList>& dt, QObject *parent=0);

    void loadSite(const QPair<QString, QString>& address);

signals:

    void finished(QNetworkReply* reply);

private slots:

    void replyFinished(QNetworkReply *reply);

private:
    QString                 page;

    QStringList             ref;

    QVector<QStringList>&   dtModel;

    QPair<QString, QString> site;

    QNetworkAccessManager   *manager;

    void getMainContent();

    void getReferencesAvito();

    void parsePageElement();
};

#endif // PARSER_H
