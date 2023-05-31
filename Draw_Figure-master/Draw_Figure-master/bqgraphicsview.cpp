#include "bqgraphicsview.h"

BQGraphicsView::BQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    // 隐藏水平/竖直滚动条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 设置场景范围
    setSceneRect(INT_MIN / 2, INT_MIN / 2, INT_MAX, INT_MAX);

    // 反锯齿
    setRenderHints(QPainter::Antialiasing);
}

void BQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}


//读取.shp文件
void BQGraphicsView::mid()
{
    //filename = QFileDialog::getOpenFileName(
                //this, "open shp file",
                //".",
                //"Image files (*.shp);;All files (*.*)");
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    showshp();
}

void BQGraphicsView::showshp()
{
    QPointF firstPoint;
    QPointF endPoint;

//MainWindow::trypos(1);
    CPLSetConfigOption("GDAL_FILENAME_IS_UTF8","NO" );//使GDAL支持中文
    OGRRegisterAll();
    //MainWindow::trypos(2);
    //打开数据
    GDALDataset *poDS ;
    //MainWindow::trypos(3);//定义一个图形数据集
    poDS = (GDALDataset *)GDALOpenEx(filename.toStdString().c_str(),GDAL_OF_VECTOR,nullptr,nullptr,nullptr);
    //MainWindow::trypos(4);
    //打开矢量数据并返回指针给数据集
    if (poDS == nullptr)
    {
//        ui->textEdit->append("Open Failed");
        exit(1);
    }
    OGRLayer *poLayer = poDS->GetLayer(0);
    //MainWindow::trypos(5);
    poLayer->GetExtent(envelope);
    //MainWindow::trypos(6);
//    poLayer->ResetReading();
    OGRFeature *poFeature;               //定义要素指针
    //MainWindow::trypos(7);
    while((poFeature = poLayer->GetNextFeature())!=nullptr)  //从图层中获取要素
    {
        OGRGeometry *poGeometry = poFeature->GetGeometryRef();   //从要素中获取几何图形
        //MainWindow::trypos(8);
        if (poGeometry!=nullptr)
        {
            switch (wkbFlatten(poGeometry->getGeometryType()))   //判别几何图形的类型
            {
            case wkbLineString:
                {
                //如果几何图形的类型为线状执行下面程序
                    OGRLineString *poLine = (OGRLineString*)poGeometry;
                    for(int i = 0;i<poLine->getNumPoints();i++)
                    {
                        double staX = poLine->getX(i);
                        double staY = poLine->getY(i);
                        TransformCoordinate(&staX,&staY);//坐标转换
                        if(i==0)
                        {
                            firstPoint.setX(staX);          //使用CDC类进行绘图
                            firstPoint.setY(staY);
//                                update();
                        }
                        else
                        {
                            endPoint.setX(staX);          //使用CDC类进行绘图
                            endPoint.setY(staY);
//                            repaint();
                            scene->addLine(firstPoint.x(),firstPoint.y(),endPoint.x(),endPoint.y());
                            firstPoint.setX(staX);          //使用CDC类进行绘图
                            firstPoint.setY(staY);
                        }
//                            if (i == poLine->getNumPoints() - 1)
//                            {
//                                break;
//                            }
                    }
                    OGRFeature::DestroyFeature( poFeature );
//                        ui->lineEdit->setText("12");
                    break;
                }

            case wkbPolygon:
            {
                OGRLineString *poLine = (OGRLineString*)poGeometry;
                for(int i = 0;i<poLine->getNumPoints();i++)
                {
                    double staX = poLine->getX(i);
                    double staY = poLine->getY(i);
                    TransformCoordinate(&staX,&staY);//坐标转换
//                                for (int i = 0; i < pointdb.Rows.Count; i++)
//                                {
//                                    if (i == pointdb.Rows.Count - 1)
//                                    {
//                                        graphics.DrawLine(new Pen(Color.Black, 1), (float)(pointdb.Rows[i][1]), (float)(pointdb.Rows[i][2]), dbstartp.X, dbstartp.Y);
//                                        break;
//                                    }
//                                    if (checkteam != (int)(pointdb.Rows[i + 1][0]))
//                                    {
//                                        graphics.DrawLine(new Pen(Color.Black, 1), (float)(pointdb.Rows[i][1]), (float)(pointdb.Rows[i][2]), dbstartp.X, dbstartp.Y);
//                                        checkteam = (int)(pointdb.Rows[i + 1][0]);
//                                        dbstartp.X = (float)(pointdb.Rows[i + 1][1]);
//                                        dbstartp.Y = (float)(pointdb.Rows[i + 1][2]);
//                                        continue;
//                                    }
//                                    graphics.DrawLine(new Pen(Color.Black, 1), (float)(pointdb.Rows[i][1]), (float)(pointdb.Rows[i][2]), (float)(pointdb.Rows[i + 1][1]), (float)(pointdb.Rows[i + 1][2]));
//                                }
                }
                OGRFeature::DestroyFeature( poFeature );
                break;
            }
            }
        }

    }
    poLayer->ResetReading();
}

