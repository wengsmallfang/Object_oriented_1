#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QString>

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    static QString path;


    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){

        //显示打开文件窗口
        path = QFileDialog::getOpenFileName(this, "打开文件","/home/xcl/qt");//返回一个文件的路径

        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);//在lineEdit显示路径

        //编码格式类
        //QTextCodec * codec = QTextCodec::codecForName("gbk");//如果文件格式为GBK,需要做格式转码

        //读取内容 放入到 textEdit中
        // QFile默认支持的格式是 utf-8
        QFile file(path); //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);//只读模式

        //第一种方式
       // QByteArray array = file.readAll();//全部读出　，返回值为 QByteArray

        //第二种方式
        QByteArray array;
        while( !file.atEnd())//判断是否读到文件尾
        {
            array += file.readLine(); //按行读，追加
        }

        //将读取到的数据 放入textEdit中,显示出来
        ui->textEdit->setText(array);//类型隐式转换
        //ui->textEdit->setText( codec->toUnicode(array)  );//格式转码

        file.close();

    });


    //写文件
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){

        //显示打开文件窗口
        path = QFileDialog::getOpenFileName(this, "打开文件","/home/xcl/qt");//返回一个文件的路径

        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);//在lineEdit显示路径

        //编码格式类
        //QTextCodec * codec = QTextCodec::codecForName("gbk");//如果文件格式为GBK,需要做格式转码

        //读取内容 放入到 textEdit中
        // QFile默认支持的格式是 utf-8
        QFile file(path); //参数就是读取文件的路径

        //进行写文件
        file.open(QIODevice::ReadWrite); //用读写方式进行写
        file.write("new data!!!");
        //读取内容 放入到 textEdit中
        // QFile默认支持的格式是 utf-8

        //第一种方式
       // QByteArray array = file.readAll();//全部读出　，返回值为 QByteArray

        //第二种方式
        QByteArray array;
        while( !file.atEnd())//判断是否读到文件尾
        {
            array += file.readLine(); //按行读，追加
        }

        //将读取到的数据 放入textEdit中,显示出来
        ui->textEdit->setText(array);//类型隐式转换
        //ui->textEdit->setText( codec->toUnicode(array)  );//格式转码

        file.close();
    });
}

widget::~widget()
{
    delete ui;
}

