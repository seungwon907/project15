#include "StackMenu.h"

ArrayStack* createArrayStack(int size) {
    ArrayStack* re = (ArrayStack*)malloc(sizeof(ArrayStack));
    re->data = (stackElement*)malloc(sizeof(stackElement) * size);
    re->top = -1;
    re->size = size;
    return re;
}

void destroyArrayStack(ArrayStack* s) {
    free(s->data);
    free(s);
}

int emptyArrayStack(ArrayStack* s) {
    return s->top == -1;
}

int fullArrayStack(ArrayStack* s) {
    return s->top == s->size - 1;
}

int pushArrayStack(ArrayStack* s, stackElement item) {
    if (fullArrayStack(s)) {
        return 0; 
    }
    s->top++;
    s->data[s->top] = item;
    return 1;
}

stackElement popArrayStack(ArrayStack* s) {
    if (emptyArrayStack(s)) {
        return NULL; 
    }
    stackElement temp = s->data[s->top];
    s->top--;
    return temp;
}

void printArrayStack(ArrayStack* s) {
    printf("Stack:\n");
    printf("Size: %d, Top: %d\n", s->size, s->top);
    for (int i = 0; i <= s->top; i++) {
        printf("[%d] %s\n", i, s->data[i]);
    }
}

stackElement peakArrayStack(ArrayStack* s) {
    if (emptyArrayStack(s)) {
        return NULL; 
    }
    return s->data[s->top];
}
