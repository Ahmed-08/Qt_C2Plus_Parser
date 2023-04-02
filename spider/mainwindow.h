#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "parser.h"
#include "model.h"
#include "delegate.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMap<QString, QString> sites, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbtSearch_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow          *ui;


    QMap<QString, QString>  listSites;

    Parser                  *parse;

    Model                   *model;

    QVector<QStringList>    dataModel;



    void createTable();
};
#endif // MAINWINDOW_H
