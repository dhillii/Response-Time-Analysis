#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rta.h"

// Sorts Processes by period
int cmp (const void * a, const void * b) {
    Process *ProcessA = (Process *)a;
    Process *ProcessB = (Process *)b;
    return ( ProcessA->priority - ProcessB->priority);
}

int main(){
    FILE * infile;
    infile = fopen("data.txt", "r");
    Process task_set[3]; 
    generateProcesses(infile, task_set);
    qsort(task_set, 3,  sizeof(Process), cmp);
    calculateResponseTimes(task_set);
    displayTaskSet(task_set);
    /*printf("%d\n", task_set[0].r_time);
    printf("%d\n", task_set[1].r_time);
    printf("%d\n", task_set[2].r_time);*/
    return 0;
}
