#include "function.h"

char* Validate(int* argc, char** argv)
{
    FILE* fptr;
    if(*argc < 2) {
        fputs("No command-line arguments!\n", stderr);
        exit(1);
    }
    else if(*argc > 2) {
        fputs("Too many command-line arguments!\n", stderr);
        exit(2);
    }

    // printf("Reading file %s\n", argv[1]);
    if((fptr = fopen(argv[1], "r")) == NULL) {
        fputs("Cannot open file!\n", stderr);
        exit(3);
    }
    fseek(fptr, 0L, SEEK_END);
    int file_size = ftell(fptr);
    // printf("%d\n", file_size);
    fseek(fptr, 0L, SEEK_SET);

    char* tab = malloc(file_size * sizeof(char));
    if(!tab) {
        fclose(fptr);
        fputs("Cannot allocate memory!\n", stderr);
        exit(4);
    }

    if(fread(tab, file_size, 1, fptr) != 1) {
        fclose(fptr);
        free(tab);
        fputs("Cannot read file!\n", stderr);
        exit(4);
    }

    tab[file_size] = 0;
    fclose(fptr);

    // printf("%s\n", tab);
    return tab;
}

void SkipForward(char** program)
{
    int i = 0;
    while(**program != 0) {
        (*program)++;
        // printf("-%c\n", **program);
        if((**program) == '[')
            i++;
        else if((**program) == ']') {
            if(i > 0)
                i--;
            else
                break;
        }
    }
    return;
}

void SkipBack(char** program, char* limit)
{
    int i = 0;
    while(*program != limit) {
        (*program)--;
        // printf("-%c\n", **program);
        if((**program) == ']')
            i++;
        else if((**program) == '[') {
            if(i > 0)
                i--;
            else
                break;
        }
    }
    return;
}