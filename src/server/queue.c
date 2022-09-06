#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"



// create new queue
struct BufferQueue queueCreate(int bufferSize){
    struct BufferQueue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    q.bufferSize = bufferSize;
    return q;
}



// takes a buffer and insert it at end
int queuePush(struct BufferQueue* q,char *message){

    /*
        ErrorCode: 
            0 -> successfully pushed
            -1 -> mem allocation failed
    */

    int bufferSize = q->bufferSize;

    if (q->head==NULL){

        // init head
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        if (node==NULL){
            return -1;
        }
        node->message = (char *) malloc(sizeof(char)*bufferSize);
        node->next = NULL;
        strcpy(node->message,message);  


        q->head = node;
        q->tail = node;
        q->size = 1;

        return 0;

    }

    struct Node *tail = q->tail;

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode==NULL){
        return -1;
    }
    newNode->message = (char *) malloc(sizeof(char)*bufferSize);
    newNode->next = NULL;
    strcpy(newNode->message,message);  

    tail->next = newNode;

    q->tail = newNode;
    q->size = q->size+1;

    return 0;
}


char* queuePop(struct BufferQueue *q){

    /*
        returns malloced char* make sure to free it
    */

    // take the head out and then make head->next = head

    struct Node* head = q->head;
    q->head = q->head->next;
    q->size = q->size-1;
    char* message = head->message;

    free(head);

    return message;
}



void queueDisplay(struct BufferQueue *q){

    struct Node *temp = q->head;

    while(temp!=NULL){
        printf("%s -> ",temp->message);
        temp = temp->next;
    }
    printf("NULL\n");
}
