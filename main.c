#include "function.h"

#define WS_SIZE 1000

int main(int argc, char* argv[])
{
    char *program = Validate(&argc, argv), *limit = program;
    char *working_space = calloc(WS_SIZE, sizeof(char)),
         *ptr = working_space;

    while(*program != 0) {
        // printf("%c ", *(program));
        switch(*program) {
        case '+':
            (*ptr)++;
            break;
        case '-':
            (*ptr)--;
            break;
        case '.':
            printf("%c", *ptr);
            break;
        case ',':
            scanf("%c", ptr);
            break;
        case '>':
            if(ptr != working_space + WS_SIZE - 1)
                ptr++;
            break;
        case '<':
            if(ptr != working_space)
                ptr--;
            break;
        case '[':
            if(!(*ptr)) {
                // printf("Skip forward!\n");
                // printf("ss %c\n", *program);
                SkipForward(&program);
                // printf("se %c\n", *program);
            }
            break;
        case ']':
            // Skip back to opening bracket
            // printf("Skip back!\n");
            // printf("ss %c\n", *program);
            SkipBack(&program, limit);
            program--;
            // printf("se %c\n", *program);
            // scanf("LOL:%c");
            break;
        case ' ':
        case '\n':
        case '\t':
            break;
        default:
            printf("'%c'", *program);
        }
        program++;
    }

    return 0;
}