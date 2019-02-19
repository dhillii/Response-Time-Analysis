#ifndef RTA_H
#define RTA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char * p_name;
    int period;
    int c_time;
    int priority;
    int r_time;
} Process;

void generateProcesses(FILE * infile, Process *task_set);
void calculateResponseTimes(Process task_set[]);
bool isSchedulable(Process task_set[]);
void displayTaskSet(Process task_set[]);


#endif