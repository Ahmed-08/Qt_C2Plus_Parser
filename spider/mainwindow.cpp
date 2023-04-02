#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QStandardItemModel>

MainWindow::MainWindow(QMap<QString, QString> sites, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , listSites{std::move(sites)}
    , parse{new Parser(this->dataModel)}
{
    ui->setupUi(this);
    ui->pbtSearch->setStyleSheet("*{background-color: red}");
    ui->siteCombo->addItems(listSites.keys());
    ui->siteCombo->addItem("-");
    ui->siteCombo->setCurrentText("-");

    delete ui->parametersCombo->model();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtSearch_clicked()
{
    if(!ui->siteCombo->currentText().contains("-"))
    {
        ui->pbtSearch->setStyleSheet("*{background-color: green; color:white}");
        QPair addr(ui->siteCombo->currentText(), listSites[ui->siteCombo->currentText()]);
        this->parse->loadSite(addr);
        this->createTable();
        return;
    }
}

void MainWindow::createTable()
{
    if(ui->siteCombo->currentText().contains("avito"))
    {
        QVector<QString> head;
        head << "Состояние" << "Производитель" << "Модель"
             << "Разрешение экрана" << "Линейка процессора" << "Конфигурация накопителей"
             << "Видеокарта" << "Тип видеокарты" << "Цвет";

        delete ui->parametersCombo->model();
        QStandardItemModel *comboModel = new QStandardItemModel(this);

        int len = head.size();
        for(int i = 0; i < len; ++i)
        {
            QStandardItem *Item = new QStandardItem;
            Item->setText(head[i]);
            Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
            Item->setData(Qt::Unchecked, Qt::CheckStateRole);
            comboModel->insertRow(i, Item);
        }
        ui->parametersCombo->setModel(comboModel);

        this->model = new Model(dataModel.size(), head.size(), head, dataModel);

        ui->tableView->setModel(this->model);
        ui->tableView->setItemDelegate(new Delegate(this));
        ui->tableView->setMouseTracking(true);

        for(int i = 0; i < len; ++i){
            if(i != 0 && i != 3)
                ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
            else
                ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        }
        ui->tableView->setStyleSheet("QHeaderView::section {background-color:rgba(131,161,116, 0.5)}");
    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(ui->pbtSearch->styleSheet().contains("*{background-color: red}"))
        return;

    if(checked){
        for(int i = 0; i < 9; ++i){
            QModelIndex index = ui->parametersCombo->model()->index(i, 0);
            ui->tableView->setColumnHidden(i, !ui->parametersCombo->model()->data(index, Qt::CheckStateRole).toBool());
            ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }

        return;
    }
    for(int i = 0; i < 9; ++i){
        ui->tableView->setColumnHidden(i,false);
    }
}

