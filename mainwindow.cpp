#include "mainwindow.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("Point");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //不显示第二列
    //model->removeColumn(1);

    //查询整张表
    model->select();

    ui->tableView->setModel(model);

    //设置视图不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //开启事务
        model->database().transaction();
        if (model->submitAll())
        {
            //提交事务
            model->database().commit();
        }
        else
        {
            //回滚事务
            model->database().rollback();
            QMessageBox::warning(this, tr("TableView"), tr("数据库错误: %1").arg(model->lastError().text()));
        }
}


void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}


void MainWindow::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit->text();

    //根据序号进行筛选
    model->setFilter(QString("tolineid = %1").arg(id));

    //显示结果
    model->select();
}


void MainWindow::on_pushButton_8_clicked()
{
    //设置要查询的表
    model->setTable("Point");
    //执行查询操作
    model->select();
}


void MainWindow::on_pushButton_6_clicked()
{
    model->setSort(0, Qt::AscendingOrder);

    model->select();
}


void MainWindow::on_pushButton_7_clicked()
{
    model->setSort(0, Qt::DescendingOrder);

    model->select();
}


void MainWindow::on_pushButton_4_clicked()
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
    model->removeRow(curRow);

    int ret = QMessageBox::warning(this, "delete this line", "Are you sure to delete thia line?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        //删除该行 提交到数据库
        model->submitAll();
    }
    else
    {
        //不删除  撤销操作
        model->revertAll();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    //获取表的行数
    int row = model->rowCount();

    //int id = 18;
    //添加一行
    model->insertRow(row);

    //model->setData(model->index(row, 0), 5);
    //model->setData(model->index(row, 1), 3.5);

    //提交
    //model->submitAll();
}

