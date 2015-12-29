#ifndef STACK_
#define STACK_
#include "Interpretation.h"
typedef struct stackNode* dvar;
struct stackNode {
    Variable v;
    int dlvl;
    dvar next;
};

typedef struct Stack {
    dvar header;
}stack;

stack createEmptyStack();
void push(stack s, Variable v, int dlevel);
int pop(stack s);
int getTop(stack s);    //See the decision level of the top Variable

#endif
