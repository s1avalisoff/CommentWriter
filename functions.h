#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED

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

#endif // FUNCTIONS_INCLUDED
