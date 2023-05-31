#ifndef BQGRAPHICSVIEW_H
#define BQGRAPHICSVIEW_H
#include <QFileDialog>

#include <QGraphicsView>
#include <QMouseEvent>

class BQGraphicsView : public QGraphicsView
{
public:
    BQGraphicsView(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    void mid();
    void showshp();
};

#endif // BQGRAPHICSVIEW_H
