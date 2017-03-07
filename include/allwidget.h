#ifndef ALLWIDGET_H
#define ALLWIDGET_H

#include <QObject>
#include <QWidget>
#include "common.h"
#include "needleitem.h"
#include "dashitem.h"
#include "midlabel.h"
#include "lwidget.h"
#include "rwidget.h"
#include "data.h"

class allwidget : public QWidget
{
    Q_OBJECT
public:
    explicit allwidget(QWidget *parent = 0);
    QGraphicsScene *scene;
    NeedleItem *Needleitem;
    DashItem *Dashitem;
    BackgroundItem *Backgrounditem;
    /*
    CenterLabel *SpeedLabel;
    QGraphicsWidget *GraSpeedLabel;

    LWidget *lwidget;
    QGraphicsWidget *Gralwidget;

    RWidget *rwidget;
    QGraphicsWidget *Grarwidget;
    */
    QGraphicsView *view;



signals:
    void changLabelText(int *LabelText);
public slots:

private:

    QThread *Lthread;
    Worker  *worker;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // ALLWIDGET_H
