#ifndef FUNCTION_BRAINFUCK
#define FUNCTION_BRAINFUCK

#include <stdio.h>
#include <stdlib.h>

char* Validate(int* argc, char** argv);
void SkipForward(char** program);
void SkipBack(char** program, char* limit);

#endif