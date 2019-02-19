#include "rta.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
    int arr_length = sizeof(task_set)-1;
    for(int i = arr_length -1; i>=0; i--){
        int prev = -1; float acc = 0; int curr = 0;
        if(i == arr_length-1){
            task_set[i].r_time = task_set[i].c_time;
        }
        else{
            while(curr < task_set[i].period && curr != prev){
                prev = curr; acc = curr; curr = 0;
                for(int j = i + 1; j < arr_length; j++){
                    curr += ceil(acc/task_set[j].period) * task_set[j].c_time;
                }
                curr += task_set[i].c_time;
            }
            task_set[i].r_time = curr;
            curr = 0; prev = -1;
        }
    }
}

bool isSchedulable(Process * task_set){
    int arr_length = sizeof(task_set)-1;
    for(int i = arr_length -1; i>=0; i--){
        if(task_set[i].r_time > task_set[i].period){
            return false;
        }
    }
    return true;
}

void displayTaskSet(Process * task_set){
    int arr_length = sizeof(task_set)-1;
    printf("id\tT\tC\tP\tR\n");
    printf("..................................\n");
    for(int i = 0; i<=arr_length -1; i++){
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, task_set[i].period, task_set[i].c_time, task_set[i].priority, task_set[i].r_time);
    }
    if(isSchedulable(task_set)){
        printf("\nThis set of tasks IS Schedulable by by a fixed priority scheduler!\n");
    }
    else{
        printf("\nThis set of tasks is NOT Schedulable by a fixed priority scheduler!!\n");
    }
}