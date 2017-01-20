#include "include/data.h"

static QMutex data_mutex;

static rc_data_telltWarn_t tw_data;

int set_data(rc_msg_t msg)
{
    int result = -1;
    data_mutex.lock();
    tw_data.telltaleWarnText = msg.msg_data.tellt_warn_data;
    result  = 0;	/*mark here add it to msg_queue*/
    data_mutex.unlock();
    return result;
}


int get_data( void *data)
{
    int result = -1;
    data_mutex.lock();
    *((rc_data_telltWarn_t *)data) = tw_data;
    result  = 0;
    data_mutex.unlock();
    return result;
}

