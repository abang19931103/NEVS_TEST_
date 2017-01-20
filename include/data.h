#ifndef DATA_H
#define DATA_H

#include "common.h"
#include "test_def.h"

typedef struct
{
    /* warning status */
    telltWarn_data_t telltaleWarnText;
//	warntext_data_t warning_text;
} rc_data_telltWarn_t;

int set_data(rc_msg_t msg);

int get_data(void *data);



#endif // DATA_H
