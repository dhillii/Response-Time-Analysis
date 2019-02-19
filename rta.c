#include "rta.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


void generateProcesses(FILE * infile, Process *task_set){
    char buf [256];
    int index = 0;
    //Read file line by line until completion
    while(fgets(buf,256,infile)){
        int inner_index = 0;
        int p_values[3];
        Process newProcess;
        char * pid;
        char * token = strtok(buf, " ");
        pid = token;
        // newProcess.p_name = pid;
        // printf(newProcess.p_name);
        while (token != NULL) { 
            token = strtok(NULL, "  ");
            p_values[inner_index] = atoi(token);
            inner_index++; 
        } 
        newProcess.period = p_values[0];
        newProcess.c_time = p_values[1];
        newProcess.priority = p_values[2];
        task_set[index] = newProcess;
        index++;   
    }

}
void calculateResponseTimes(Process * task_set){

}