#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rta.h"

int main(){
    FILE * infile;
    infile = fopen("data.txt", "r");
    Process arr[100];
    generateProcesses(infile, arr);

    return 0;
}
