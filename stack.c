#include "stack.h"

stack createEmptyStack()
{
    stack s;
    s.header=malloc(sizeof(struct stackNode));
    s.dlvl=-1;
    s.header->next=NULL;
    return s;
}

// push a variable to the stack with its decision level
void push(stack s, Variable v, int dlevel)
{
    dvar node=malloc(sizeof(struct stackNode));
    node->next=s.header->next;
    node->v=v;
    node->dlvl=dlevel;
    s.header->next=node;
}
// pop a variable from the stack
int pop(stack s)
{
    dvar temp=s.header->next;
    int var=temp.v;
    s.header->next=temp->next;
    free(temp);
    return var;
}

// get the decision level of the top variable in the stack
int getTop(stack s)
{
    return s.header->next.dlvl;
}
