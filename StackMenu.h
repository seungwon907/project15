#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef char* stackElement;

typedef struct arrayStack {
    stackElement* data;
    int top;
    int size;
} ArrayStack;

ArrayStack* createArrayStack(int size);
void destroyArrayStack(ArrayStack* s);
int pushArrayStack(ArrayStack* s, stackElement item);
stackElement popArrayStack(ArrayStack* s);
int emptyArrayStack(ArrayStack* s);
int fullArrayStack(ArrayStack* s);
void printArrayStack(ArrayStack* s);
stackElement peakArrayStack(ArrayStack* s);

#endif 
