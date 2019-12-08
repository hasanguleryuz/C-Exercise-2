//Hasan Güleryüz - 240201029

#include "BstStackApp.h"
//Create new array that contains random number for tasks.
int *createArray(){

    static int array[10];//create a array.

    for(int i = 0; i < 10; i++){
        array[i] = rand() % 4 +1;//Adding numbers from 1 to 4
    }

    return array;
}
//This function control input is invalid or valid.
int checkInput(){
    //input = valid result.
    //tempChar = invalid result.
    //result scanf.
    int input, tempChar, result;
    result = scanf("%d", &input);
    while(result!=1){
        while((tempChar=getchar()) != EOF && tempChar != '\n');
        printf("Invalid input... Please enter a number: ");
        result = scanf("%d", &input);
    }
    return input;
}
//Back step function.
void backStep(Node *node, Stack *stack,int numberOfStep){
    if(numberOfStep == 0){
        return;
    }
    else{
        //if stack is empty, no task.
        if(isEmpty(stack)){
            printf("There is no task to be undone \n");
            printf("\n");
            return;
        }
        else{
            //Task that number of 1 equals insert so delete value.
            if(stack->task[stack->top] == 1){
                deleteNode(node,stack->values[stack->top],0);
                printf("inserted value %d is deleted \n",stack->values[stack->top]);
                inorder(node);
                printf("\n");
            }
            //Task that number of 2 equals insert so insert value.
            else if(stack->task[stack->top] == 2){
                insert(node,stack->values[stack->top]);
                printf("deleted value %d is inserted \n",stack->values[stack->top]);
                inorder(node);
                printf("\n");
            }
            pop(stack);
        }
    }
    numberOfStep = numberOfStep - 1;
    backStep(node,stack,numberOfStep);
}
//Run tasks.
void runTask(Node *node, Stack *stack){
    int *array = createArray();//create random tasks.
    int value,task;//create value, task.
    for(int i = 0; i < 10; i++){
        task = *(array+i);
        if(task == 1){
            printf("task->insert : \n");
            value = checkInput();
            insert(node,value);
            push(stack,1,value);
            printf("The value:%d is inserted \n",value);
            inorder(node);
            printf("\n");
            printf("\n");

        }
        else if(task == 2){
            printf("task->delete : \n");
            value = checkInput();
            if(search(node,value)){
                deleteNode(node,value,0);
                push(stack,2,value);
                printf("The value:%d is deleted \n",value);
                inorder(node);
                printf("\n");
                printf("\n");
            }
            else{
                printf("searched %d is not found \n",value);
                printf("\n");
            }
        }
        else if(task == 3){
            printf("task->min  \n");
            printf("minval %d is found \n",minValueNode(node)->data);
            printf("\n");
        }
        else if(task == 4){
            printf("task->search : \n");
            value = checkInput();
            if(search(node,value)){
                printf("searched %d is found \n",value);
                printf("\n");
            }
            else{
                printf("searched %d is not found \n", value);
                printf("\n");
            }
        }
    }
}