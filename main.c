#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv){
    long cs, ms, size;
    cs = fl(argv[1]);
    ms = fl(argv[2]);
    size = cs + ms;
    printf("Total symbols: %ld, comment symbols: %ld, message symbols: %ld", size, cs, ms);
    char* comment = rf(argv[1]);
    char* text = rf(argv[2]);
    char res[size];
    strcpy(res, comment);
    strcat(res, "\n");
    strcat(res, text);
    if(argv[3] != NULL){
        fw(argv[3], res);
    }
    else{
        fw(argv[2], res);
    }
    free(comment);
    free(text);
    return 0;
}
