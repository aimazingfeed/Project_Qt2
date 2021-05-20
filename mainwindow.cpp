#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDateTime>
#include <QFileInfoList>
#include <QtAlgorithms>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("L:/Projects/TextAnalizator/analizatorDB2.db");
//    db.setDatabaseName("L:/Projects/Project_Qt1/Qt_db.db");
    db.setUserName("root");

    if (!db.open()) {
        qDebug() << db.lastError().text();
        return;
    } else {
        qDebug() << "Success";
    }

    dir.setPath("L:/Projects/TextAnalizator/scripts");
//    dir.setPath("L:/Projects/Project_Qt1");
    dir.setNameFilters(filters);
    list = dir.entryInfoList(QDir::Files,QDir::Name);
    qDebug() << "list size " << list.size();
    for (auto i:list)
    {
        qDebug() << i;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::getDataFromFile(QStringList buf) {



QString str="";

    for (auto i:buf) {
        QFile file(i);
        if ((file.exists())&&(file.open(QIODevice::ReadOnly))) {

            while(!file.atEnd()) {
                str=str+file.readLine();
            }
        file.close();
        }
    }
    return str;



}

void MainWindow::on_pushButton_clicked()
{
    QStringList buf;
    for (size_t i = 0;i<list.size(); ++i) {
        buf.push_back((list[i].absoluteFilePath()));
    }
    QSqlQueryModel* query = new QSqlQueryModel;

    QString v = getDataFromFile(buf);
    QStringList vlist = v.split('"');
    for (auto i:vlist) {
    query->setQuery(i);
    }
}

