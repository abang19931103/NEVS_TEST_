#include "include/lwidget.h"
#include "include/data.h"


LWidget::LWidget(QWidget *parent) : QWidget(parent)
{

    LLayout=new QVBoxLayout(this);
    int i;
    for(i=0;i<4;i++)
    {
        LLabel[i]=new TestLable;
        LLabel[i]->setText("Left Label\t"+QString::number(i));
        LLayout->addWidget(LLabel[i]);
        Labeldata[i]=0;
    }
    FPSLabel=new TestLable;
    FPSLabel->setText("FPS: counting fps...");
    LLayout->addWidget(FPSLabel);
    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明
}


void LWidget::Calc_Fps()
{
    /*
    static QTime time;
    static int frames = 0;
    static bool started = false;
    if (!started || time.elapsed() > 1000) {
        qreal fps = frames * 1000. / time.elapsed();
        if (fps == 0)
            m_current_fps = "counting fps...";
        else
            m_current_fps = QString::fromLatin1("%3 ").arg((int) qRound(fps));

        time.start();
        started = true;
        frames = 0;

    } else {
        ++frames;

    }
    */
    /*
    static  QString tmp="";
    static float framesPerSecond=0.0f;//fps的数值
    static float frames    = 0.0f;       // 用于存储渲染的帧数
    static float lastTime   = 0.0f;       // 前一秒的时刻
    float currentTime =  glutGet(GLUT_ELAPSED_TIME)* 0.001f;//程序运行的时间
    ++frames;
    if( currentTime - lastTime > 1.0f )//，每秒刷新一次
    {
        framesPerSecond=frames;
        tmp.setNum(framesPerSecond);
        lastTime = currentTime;
        frames= 0;
    }
    */

    static QTime Time;
    static int frame=0;
    static int fps;
    static bool started = false;

    if (!started || (Time.elapsed()) > 1000) {
        fps = frame*1000.0/(Time.elapsed());
        if(fps==0)
            FPSLabel->setText("FPS: counting fps...");
        FPSLabel->setText("FPS: "+QString::number(fps));
        frame = 0;
        Time.restart();
        started = true;
    }
    frame++;
}

void LWidget::Update_LWiaget_data(int *LLabel_data)
{
    int i;
    for(i=0;i<4;i++)
    {
        LLabel[i]->setText("Left Label\t"+QString::number(LLabel_data[i]));
    }


    Calc_Fps();
    //FPSLabel->setText("FPS: "+m_current_fps);

}


