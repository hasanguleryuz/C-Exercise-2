//Hasan Güleryüz - 240201029
#include "BstStackApp.h"
int main() {
    Stack *newStack = createStack(50);
    //Create BST.
    Node *newNode = createNode(30);
    Node *root = newNode;
    insert(root,10);
    insert(root,25);
    insert(root, 50);
    insert(root,35);

    inorder(root);
    printf("\n");
    //Run task
    runTask(root,newStack);
    //Back step.
    int steps;
    printf("How many steps go back : ");
    steps = checkInput();
    backStep(root,newStack,steps);
}