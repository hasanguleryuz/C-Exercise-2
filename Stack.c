//Hasan Güleryüz - 240201029
#include "Stack.h"

//Create stack.
Stack* createStack(int capacity){
    Stack *newStack = malloc(sizeof(Stack));

    newStack->capacity = capacity;//Capacity.
    newStack->top = -1;//Initialization
    newStack->values = malloc(sizeof(Stack));//Create a memory for values.
    newStack->task = malloc(sizeof(Stack));//Create a memory for task.
    return newStack;
}
int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;//If capacity equal top, stack is full.
}

int isEmpty(Stack* stack){
    return stack->top == -1;//If top equal -1, stack is empty.
}


void push(Stack* stack, int t, int item){
    //if stack is full, will not push.
    if(isFull(stack)){
        printf("Stack is full \n");
        return;
    }

    stack->task[++stack->top] = t;//push new task.
    stack->values[stack->top] = item;//push new value.
}

int pop(Stack* stack){
    //if stack is empty, will not pop.
    if(isEmpty(stack)){
        printf(("Stack is empty \n"));
        return -1;
    }

    stack->task[stack->top--];//pop a task.
    return stack->values[stack->top];//pop a value.
}