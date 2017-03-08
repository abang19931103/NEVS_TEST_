#include "include/rwidget.h"

RWidget::RWidget(QWidget *parent) : QWidget(parent)
{
    RLayout=new QVBoxLayout(this);
    int i;
    for(i=0;i<4;i++)
    {
        RLabel[i]=new TestLable;
        RLabel[i]->setText("Right Label\t"+QString::number(i));
        RLayout->addWidget(RLabel[i]);
        Labeldata[i]=0;
    }
    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明


}

void RWidget::Update_LWiaget_data(int *RLabel_data)
{
    int i;
    for(i=0;i<4;i++)
    {
        RLabel[i]->setText("Right Label\t"+QString::number(RLabel_data[i+4]));
    }
}

