#include "function.h"

#define WS_SIZE 1000

int main(int argc, char* argv[])
{
    // Check command-line arguments, read brainfuck program
    char *program = Validate(&argc, argv), *limit = program;
    // Allocate memory
    char *working_space = calloc(WS_SIZE, sizeof(char)),
         *ptr = working_space;
    char move_on = 1;

    // Execute each letter
    while(*program != 0) {
        // printf("%c ", *(program));
        switch(*program) {
        case '+':
            // Add 1 to memory cell
            (*ptr)++;
            break;
        case '-':
            // Substract 1 from memory cell
            (*ptr)--;
            break;
        case '.':
            // print pointed memory cell
            printf("%c", *ptr);
            break;
        case ',':
            // read to pointer memory cell
            scanf("%c", ptr);
            break;
        case '>':
            // Move to next cell
            // But only if we are not exceeding memory heap
            if(ptr != working_space + WS_SIZE - 1)
                ptr++;
            break;
        case '<':
            // move back
            // But not before start of allocated heap
            if(ptr != working_space)
                ptr--;
            break;
        case '[':
            // Check if pointed memory cell is 0
            // If it is 0 then skip to closing bracket
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
            // Do not increment over opening bracket to check
            // condition of the loop
            move_on = 0;
            // printf("se %c\n", *program);
            // scanf("LOL:%c");
            break;
        case ' ':
        case '\n':
        case '\t':
            break;
        default:
            printf("Unrecognized character: %c\n", *program);
        }
        if(move_on)
            program++;
        move_on = 1;
    }

    return 0;
}