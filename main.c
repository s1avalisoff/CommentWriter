#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void add(char arg1[], char arg2[], char arg3[]){
    long cs, ms, size;
    cs = fl(arg1);
    ms = fl(arg2);
    if(cs < 0 || ms < 0){
        printf("Error: one of files not exists!");
        return;
    }
    size = cs + ms;
    printf("Total symbols: %ld, comment symbols: %ld, message symbols: %ld", size, cs, ms);
    char* comment = rf(arg1);
    char* text = rf(arg2);
    char res[size];
    strcpy(res, comment);
    strcat(res, "\n");
    strcat(res, text);
    if(arg3 != NULL){
        fw(arg3, res);
    }
    else{
        fw(arg2, res);
    }
    free(comment);
    free(text);
}

void license(){
    printf("MIT License\n\n");
    printf("Copyright (c) 2021 s1avalisoff\n\n");
    printf("Permission is hereby granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files (the \"Software\"), to deal\nin the Software without restriction, including without limitation the rights\nto use, copy, modify, merge, publish, distribute, sublicense, and/or sell\ncopies of the Software, and to permit persons to whom the Software is\nfurnished to do so, subject to the following conditions:\n\n");
    printf("The above copyright notice and this permission notice shall be included in all\ncopies or substantial portions of the Software.\n\n");
    printf("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\nAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\nOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\nSOFTWARE.\n");
}

void help(){
    printf("Usage:\n\n");
    printf("-a(or --add) for add\n");
    printf("-a(or --add) [name of file with start text] [name of file with end text] [name of file for writing result](last is optional, if not specified, recording will be made to the file specified in the second argument)\n\n");
    printf("-l(or --license) for license text\n\n");
    printf("-h(or --help) for displaying help message\n");
}

int main(int argc, char **argv){
    if(strcmp(argv[1], "--add") == 0 || strcmp(argv[1], "-a") == 0){
        add(argv[2], argv[3], argv[4]);
    }
    else if(strcmp(argv[1], "--license") == 0 || strcmp(argv[1], "-l") == 0){
        license();
    }
    else if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
        help();
    }
    else{
        printf("Unknown command \"%s\". Use \"--help\" for help.\n", argv[1]);
    }
    return 0;
}
