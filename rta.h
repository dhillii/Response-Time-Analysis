#ifndef RTA_H
#define RTA_H

#include <stdbool.h>

typedef struct{
    char * p_name;
    int period;
    int c_time;
    int priority;
} Process;


void calculateResponseTimes(Process task_set[]);
bool isSchedulable(Process task_set[]);


#endif