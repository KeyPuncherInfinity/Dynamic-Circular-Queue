/*
This file contains the actual implementation of the Circular Queue using Circular Linked List
"LinkList.h" contains all the necessary functions so as to make this file cleaner and easier to understand

There will be 3 new functions in this file : 

1. void enQueue(int)
=> This function accepts an integer data as an argument
=> Adds the data at the end of the list using the function addToList() that is made following the basic Circular Linked List algorithms

2. int deQueue()
=> This function first checks if the queue is empty or not
   + If the queue is empty, displays the appropriate error message
   + If not empty, it uses the removeNode() function to remove and return the data pointed at by front
   This function is also made using the basic Linked List implementations

3. void display()
=> Only function that uses Circular Linked List Logic to display all the data stored in the different nodes
 
*/

#include "LinkList.h"
/*
This header file already has the NODE *front and NODE *rear declared and initialized
These are the pointers that will be used throughout the code to refer to the Queue
*/

void enQueue(int);

int deQueue();

void display();


int main(){

    int choice,data;

    while(1){

        printf("Enter your choice\n");
        printf("1. Enter into Queue \n");
        printf("2. Delete from Queue \n");
        printf("3. Display Queue \n");
        printf("4. Exit \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to store in the Queue\n");
                scanf("%d",&data);
                enQueue(data);
            break;

            case 2:
                data = deQueue();
                printf("The element removed from the Queues is : %d\n",data);
            break;

            case 3:
                display();
            break;
            
            case 4:
                return 0;
            break;

        } //end switch

    } //end while

    return 0; 
}

void enQueue(int data){

    // simply take the data and use the Circular Singly Linked List algorithm to append the data at the end of the list
    // Here we already have a function available to do so

    addToList(data);

}


int deQueue(){

    int data;

    //First check if the List is empty or not
    if(rear == NULL){
        printf("The Queue is Empty\n");
        return NULL;
    }

    else{
    /*
    Executes if the list isn't empty. First calls the function removeNode()
    This function uses the basic algorithm to remove a node from the beginning of a Ciruclar Linked List
    */

        if(rear == front){
        // Executes if the last data is removed and sets the Queue pointers to NULL
            data = removeNode();
            rear = front = NULL;
        }
        else{
        // Executes only if the data removed is not last
            data = removeNode();
        }
        

        return data;
    } //end else

}

void display(){

    NODE *travelNode;

    if(rear == NULL){
        printf("The Queue is empty\n");
    }

    else{
    // if queue is not full, we print data in each node using a do-while loop 

        travelNode = front;
        do{
            printf("%d ",travelNode->data);
            travelNode = travelNode->next;

        }while(travelNode != front); 

        /*
        Due to the condition an exit controlled loop is necessary
        Since an entry controlled loop would exit right from the start as travelNode initializes with front
        and the loop exits when travelNode points at front again
        */

       printf("\n");
    } //end else

}