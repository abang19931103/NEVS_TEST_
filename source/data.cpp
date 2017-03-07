#include "include/data.h"
static rc_data_telltWarn_t tw_data;
static int FPS_data;
void rc_data_mutex_init()
{
    char result;
    if((result = pthread_mutexattr_init(&attr)) != 0)
    {
        qDebug()<<" ### create mutex attribute fail";
    }
    else{
        pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
        result=pthread_mutex_init(&d_tw_mutex,&attr);
        if(result !=0)
        {
            qDebug()<<"Create d_tw_mutex have error!";
        }
        else
        {
            qDebug()<<"Create d_tw_mutex have success!";

        }

        result=pthread_mutex_init(&FPS_mutex,&attr);
        if(result !=0)
        {
            qDebug()<<"Create FPS_mutex have error!";
        }
        else
        {
            qDebug()<<"Create FPS_mutex have success!";

        }
    }

}



int set_data(rc_msg_t msg)
{
    int result = -1;
    pthread_mutex_lock(&d_tw_mutex);
    tw_data.telltaleWarnText = msg.msg_data.tellt_warn_data;
    result  = 0;	/*mark here add it to msg_queue*/
    pthread_mutex_unlock(&d_tw_mutex);
    return result;
}


int get_data( void *data)
{
    int result = -1;
    pthread_mutex_lock(&d_tw_mutex);
    *((rc_data_telltWarn_t *)data) = tw_data;
    result  = 0;
    pthread_mutex_unlock(&d_tw_mutex);
    return result;
}



int set_FPS(int data)
{
    int result = -1;
    pthread_mutex_lock(&FPS_mutex);
    FPS_data=data;
    result  = 0;
    pthread_mutex_unlock(&FPS_mutex);
    return result;
}

int get_FPS(void *data)
{
    int result = -1;
    pthread_mutex_lock(&FPS_mutex);
    //FPS_data=data;
    *((int *)data) = FPS_data;
    result  = 0;
    pthread_mutex_unlock(&FPS_mutex);
    return result;
}
