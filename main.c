#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rf(char name[]){
    FILE* f;
    if((f = fopen(name, "rb")) == NULL){
        printf("Error opening file %s", name);
        char* err = "fuck";
        return err;
    }
    fseek(f, 0L, SEEK_END);
    long size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    char* buf = (char*)malloc(sizeof(char) * size);
    fread(buf, 1, size, f);
    fclose(f);
    return buf;
}

int fw(char name[], char text[]){
    FILE *fp;
    if((fp= fopen(name, "w"))==NULL)
    {
        printf("Error opening file %s", name);
        return 0;
    }
    fputs(text, fp);
    fclose(fp);
    return 0;
}

long fl(char name[]){
    FILE * pFile;
    long size;

    pFile = fopen(name, "rb");
    if (!pFile){
        printf("Error opening file %s", name);
        return -1;
    }
    else{
        fseek (pFile, 0, SEEK_END);
        size = ftell(pFile);
        fclose(pFile);
        return size;
    }
}

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
