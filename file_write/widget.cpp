#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int Big2Little(int a)         //转换数据位序
{
    char* pt = (char*)&a;
    int b;
    char* pt0 = (char*)&b;
    pt0[0] = pt[3];
    pt0[1] = pt[2];
    pt0[2] = pt[1];
    pt0[3] = pt[0];
    return b;
}

class Geometry
{
public:
    virtual string toWKT() = 0;
};

class PolyLine :public Geometry
{
public:
    vector<vector<double>> m_Parts;
public:
    string toWKT() {
        ostringstream ret;

        if (m_Parts.size() == 1)
        {
            ret << "LINESTRING(" << setiosflags(ios_base::fixed);
            for (int i = 0; i < m_Parts[0].size(); i += 2)
            {
                ret << m_Parts[0][i] << " " << m_Parts[0][i + 1];
                if (i < m_Parts[0].size() - 2)
                    ret << ",";
            }
            ret << ")";
        }
        return ret.str();
    }
};

class Polygon :public Geometry
{
public:
    vector<vector<double>> m_Parts;
public:
    string toWKT() {
        ostringstream ret;

        if (m_Parts.size() == 1)
        {
            ret << "POLYGONSTRING(" << setiosflags(ios_base::fixed);
            for (int i = 0; i < m_Parts[0].size(); i += 2)
            {
                ret << m_Parts[0][i] << " " << m_Parts[0][i + 1];
                if (i < m_Parts[0].size() - 2)
                    ret << ",";
            }
            ret << ")";
        }
        return ret.str();
    }
};
class Point :public Geometry
{
public:
    vector<vector<double>> m_Parts;
public:
    string toWKT() {
        ostringstream ret;

        if (m_Parts.size() == 1)
        {
            ret << "POINTSTRING(" << setiosflags(ios_base::fixed);
            for (int i = 0; i < m_Parts[0].size(); i += 2)
            {
                ret << m_Parts[0][i] << "," << m_Parts[0][i + 1];
            }
            ret << ")";
        }
        return ret.str();
    }
};

class GeoFormat
{
public:
    virtual int GetShapeType() = 0;
    virtual int GetShape(PolyLine* pt) = 0;
    virtual int GetShape(Polygon* pt) = 0;
    virtual int GetShape(Point* pt) = 0;
};

class ShapeFile :public GeoFormat
{
public:
    ShapeFile(const char* fname)
    {
        m_ifs.open(fname, ios_base::binary);
        m_pos = 100;
    }

    int GetShapeType()
    {
        if (!m_ifs)return -1;
        m_ifs.seekg(32, ios_base::beg);
        int type;
        m_ifs.read((char*)&type, 4);
        return type;
    }

    virtual int GetShape(PolyLine* pt)
    {
        m_ifs.seekg(m_pos + 4);
        int len;
        m_ifs.read((char*)&len, 4);
        len = Big2Little(len) * 2;
        char* ptBuf = new char[len];
        m_ifs.read(ptBuf, len);

        int partNum = *(int*)(ptBuf + 36);
        int pointNum = *(int*)(ptBuf + 40);
        int* start = (int*)(ptBuf + 44);
        double* pnts = (double*)(ptBuf + 44 + partNum * 4);

        for (int i = 0; i < partNum; i++)
        {
            int end = (i == partNum - 1) ? pointNum : start[i + 1];
            vector<double> tmp;
            for (int j = start[i]; j < end; j++)
            {
                tmp.push_back(pnts[2 * j]);
                tmp.push_back(pnts[2 * j + 1]);
            }
            pt->m_Parts.push_back(tmp);
        }

        delete[]ptBuf;
        return 1;
    }
    virtual int GetShape(Polygon* pt)
    {
        return 0;
    }
    virtual int GetShape(Point* pt)
    {
        return 0;
    }
private:
    ifstream m_ifs;
    int	m_pos;
};

class TextFile :public GeoFormat
{
private:
    ifstream m_ifs;
    int	m_pos;

public:
    TextFile(const char* fname)
    {
        m_ifs.open(fname, ios_base::binary);
    }

    int GetShapeType()
    {
        if (!m_ifs) return -1;
        m_ifs.seekg(32, ios_base::beg);
        int type;
        m_ifs.read((char*)&type, 4);
        return type;
    }

    virtual int GetShape(PolyLine* pt)
    {
        return 0;
    }
    virtual int GetShape(Polygon* pt)
    {
        return 0;
    }
    virtual int GetShape(Point* pt)
    {
        return 0;
    }
};

class Geodata
{
public:
    Geodata(const char* fname);
    int GetShapeType() const;

    Geometry* GetShape();
    bool Next();

private:
    GeoFormat* m_file;
    PolyLine   m_curPolyLine;
    Point m_curPoint;
    Polygon   m_curPolygon;
};

Geodata::Geodata(const char* fname)
{
    string str = fname;
    if (str.rfind(".shp") >= 0)
        m_file = new ShapeFile(fname);
    else
        m_file = new TextFile(fname);
}

int Geodata::GetShapeType() const
{
    return m_file->GetShapeType();
}

Geometry* Geodata::GetShape()
{
    if (m_file->GetShapeType() == 3)
    {
        m_file->GetShape(&m_curPolyLine);
        return &m_curPolyLine;
    }
    else if(m_file->GetShapeType() == 1)
    {
        m_file->GetShape(&m_curPoint);
        return &m_curPoint;
    }
    else if (m_file->GetShapeType() == 5)
    {
        m_file->GetShape(&m_curPolygon);
        return &m_curPolygon;
    }
}

bool Geodata::Next()
{
    //m_file->Next();
    return false;
}

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    static QString path;

    Geodata gd("E:\\Qt\\line.shp");
    //Geodata gd("geometry_data.txt");
    gd.GetShapeType();

    do {
        Geometry* pt = gd.GetShape();

        string szWrite=pt->toWKT();
        QString qstWrite = QString::fromStdString(szWrite);
        QByteArray baWrite = qstWrite.toUtf8();

        //string szWrite=pt->toWKT();
        //QByteArray baWrite = szWrite.c_str();
        //szWrite = baWrite .toStdString();

        ui->textEdit->setText(baWrite);

        //gd.FreeShape(pt);
    } while (gd.Next());

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

        // QFile默认支持的格式是 utf-8
        QFile file(path); //参数就是读取文件的路径

        //进行写文件
        file.open(QIODevice::Append); //用读写方式进行写
        file.write("new data!!!");

        file.close();
    });
}

widget::~widget()
{
    delete ui;
}

