//Hasan Güleryüz - 240201029

#include "BinarySearchTree.h"

//Create a node.
Node* createNode(int value){
    Node *newNode = malloc(sizeof(Node));////Create a memory for nodes..
    newNode->data = value;
    newNode->left = NULL;//Left node initialization.
    newNode->right = NULL;//Right node initialization.
}
//Print inorder.
void inorder(Node *root){
    if(root == NULL){//Base step.
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}
//Insert node.
Node* insert(Node* root, int data){
    Node *prev = root;//Previous node.
    Node *current = root;//Current node.

    Node *newNode;//Create new node wit use data.
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    //if root is null, new node equal root.
    if(root == NULL){
        root = newNode;
    }
    else{
        while (current != NULL){//searching place for new node.
            if(data < current->data){
                prev = current;
                current = current->left;
            }
            else{
                prev = current;
                current = current->right;
            }
        }
        //Data smaller than data of previous node.
        if(prev->data > data){
            prev->left = newNode;
        }
        //Data bigger that data of previous node.
        else if(prev->data < data){
            prev->right = newNode;
        }
        else{
            printf("The number: %d is consist.",data);
            return NULL;
        }
    }
    return newNode;

}
//Search data.
int search(Node* root, int data){
    if(root == NULL){
        return 0;
    }
    if(root->data == data){ 
        return 1;
    }
    if(data < root->data){
        return search(root->left,data);
    }
    if(data > root->data){
        return search(root->right,data);
    }
}
//Find min value node
Node *minValueNode(Node* node){
    //Base step.
    if(node == NULL){
        return node;
    }
    //find left node
    else{
        if(node->left == NULL){
            return node;
        } else{
            minValueNode(node->left);
        }
    }
}
//Find max value node.
Node * maxValueNode(Node* node){
    //Base step.
    if(node == NULL){
        return node;
    }
    //find right node.
    else{
        if(node->right == NULL){
            return node;
        } else{
            maxValueNode(node->right);
        }
    }
}//Delete node.
Node* deleteNode(Node* root, int data,int control){
    //Base step.
    if(root == NULL){
        return root;
    }
    //Check the root node left or right NULL. Because node to delete is root and right or left is NULL Root data change the correct data of node.
    // The fucntion, root understands that with the number of control
    //If control equal 0, node is root. If control equal 1 is not root.
    if(data == root->data && control == 0){
        if(root->left == NULL){
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data,1);
            return root;
        }
        else if(root->right == NULL){
            Node *temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data,1);
            return root;
        }
    }
    //Searching correct place.
    if(data < root->data){
        root->left = deleteNode(root->left,data,1);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right,data,1);
    }
        //Add node to correct place.
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data,1);
    }
    return root;
}