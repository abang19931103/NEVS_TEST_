#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>
#include "common.h"
#include "testlabel.h"
#include "worker.h"
#include "test_def.h"
class LWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LWidget(QWidget *parent = 0);

    TestLable * LLabel[4];
    TestLable *FPSLabel;
    QVBoxLayout *LLayout;
    int Labeldata[4];
    int Show_FPS;

    QString m_current_fps;

    void Calc_Fps(void);
signals:

public slots:
    void Update_LWiaget_data(int * LLabel_data);

};

#endif // LWIDGET_H
