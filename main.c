#include "function.h"

int main(int argc, char* argv[])
{
    char* program = Validate(&argc, argv);

    while(*program != 0) {
        printf("%c ", *(program++));
    }

    return 0;
}