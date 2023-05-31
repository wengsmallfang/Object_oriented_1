#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>


//SQLServer数据库登录设置
QSqlDatabase *dbSQLServer;
//主机名称
QString hostNameSQLServer   = "LAPTOP-D1MIH2P6";
//数据库名称
QString dbNameSQLServer     = "graphic";
//用户名
QString dbUserNameSQLServer = "sa";
//密码
QString dbPasswordSQLServer = "wf143145";

//连接到SQLServer
bool Connect_toSQLServer()
{
    dbSQLServer=new QSqlDatabase;
    *dbSQLServer=QSqlDatabase::addDatabase("QODBC");
    dbSQLServer->setHostName(hostNameSQLServer);//主机名称
    dbSQLServer->setDatabaseName(dbNameSQLServer);//数据库名称
    if(dbSQLServer->open(dbUserNameSQLServer,dbPasswordSQLServer))//用户名、密码
        return true;
    else{
        QSqlError lastError=dbSQLServer->lastError();
        qDebug()<<lastError.driverText();
        return false;
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(Connect_toSQLServer())
        qDebug()<<"连接数据库成功！";
    else
        qDebug()<<"连接数据库失败！";

    //QSqlQuery query;
    //query.exec("insert into Point values(1,7,6.0)");
    //query.exec("insert into Point values(2,3.4,9.6)");

    delete dbSQLServer;
    dbSQLServer=NULL;

    MainWindow w;
    w.show();
    return a.exec();
}
