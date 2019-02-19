#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rta.h"

void generateProcesses(FILE * infile, Process *task_set);

int main(){
    FILE * infile;
    infile = fopen("data.txt", "r");
    Process arr[100];
    generateProcesses(infile, arr);
    printf("%d\n", arr[0].period);
    printf("%d\n", arr[0].c_time);
    printf("%d\n", arr[0].priority);
    return 0;
}

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