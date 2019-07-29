/*
Header file containing only the Singly Linked List functions

1. struct node* createNode(int);
=> Creates a node with the data passed as argument 
=> Returns the address of the node

2. struct node* addToList(int);
=> Adds the passed data to the end of the Linked List

3. int removeNode()
=> Removes the Last node of the List
=> Returns the data removed
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;
//Basic structure definition
//of singly linked list

NODE *front = NULL,*rear = NULL;
/*
front and rear are the pointers used to point to the first and last data of the queue respectively
When the queue is empty, both front and rear will point to NULL
Dynamic Queues won't be full in this implementaion
*/



NODE* createNode(int);

void addToList(int);

int removeNode(NODE*);


NODE* createNode(int data){

    NODE *newnode;

    newnode = (NODE*)malloc(sizeof(NODE)); 

    newnode->next = newnode; // Initialize address with self; Useful for lists containing only one node
    newnode->data = data;
    
    return newnode;
}

void addToList(int data){

    NODE *newnode;
    // newnode will be added at the end of list

    newnode = createNode(data);

    if(rear == NULL){
    // Check if there exists a node in the list
    // Points front to the node if this is the first node
    // Also points rear to the node

        front = newnode;
        rear = newnode;

    } //end if

    else{
    // Executes if there is atleast one node in the list
    // Adds the newnode at the end of the list
    // rear points to this newly added node

        rear->next = newnode;
        rear = newnode;
        newnode->next = front; // Since the last node points to first node in Circular Linked List


    } //end else

}

int removeNode(){

    NODE *tempNode,*travelNode;
    int data;
    // data will contain the data of the node that front is pointing to
    // tempNode will hope the node to be deleted for the free() function
    // travelNode will be used to traverse the List
    data = front->data;

    tempNode = front;
    front = front->next;

    rear->next = front; //Since the last node of Circular Linked List points to the first node

    free(tempNode);

    return data;
}