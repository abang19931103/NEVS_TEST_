#include "include/allwidget.h"



int main(int argc,char * argv[])
{
    QApplication app(argc,argv);



    allwidget w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    //w.setWindowOpacity(1);
    //w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    return app.exec();
}
