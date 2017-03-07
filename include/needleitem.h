#ifndef MYITEM_H
#define MYITEM_H
#include "common.h"
#include "data.h"

class NeedleItem : public QGraphicsObject
{

public:
    NeedleItem(QGraphicsItem *paren=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);

    int stdRand;
    int m_frames;
    QTime m_time;
    qreal m_instantaneousFrequency;
    QElapsedTimer m_instantaneousElapsed;
    QPropertyAnimation *animation ;
protected:
    void timerEvent(QTimerEvent *);
};

#endif // MYITEM_H
