#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDateTime>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getDataFromFile(QStringList buf);



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList filters = {"*.sql"};
    QDir dir;
    int count = 0;
    QFileInfoList list;
};
#endif // MAINWINDOW_H
