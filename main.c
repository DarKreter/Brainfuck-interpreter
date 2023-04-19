#include <stdio.h>
#include <stdlib.h>

char* Validate(int* argc, char** argv);

int main(int argc, char* argv[])
{
    Validate(&argc, argv);
    return 0;
}

char* Validate(int* argc, char** argv)
{
    FILE *fptr;
    if(*argc < 2)
    {
        printf("No command-line arguments!\n");
        exit(1);
    }
    else if(*argc > 2)
    {
        printf("Too many command-line arguments!\n");
        exit(2);
    }

    // printf("Reading file %s\n", argv[1]);
    if ((fptr = fopen(argv[1],"r")) == NULL)
    {
        printf("Cannot open file!");
        exit(3);
    }
    fseek(fptr, 0L, SEEK_END);
    int sz = ftell(fptr);
    printf("%d\n", sz);
    fseek(fptr, 0L, SEEK_SET);

    char* tab = malloc(1000 * sizeof(char));
    fscanf(fptr,"%s", tab);

    fclose(fptr);

    printf("%s", tab);
    return tab;
}