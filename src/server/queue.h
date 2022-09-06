#ifndef QUEUE_H
#define QUEUE_H

struct Node{
    char *message;
    struct Node *next; 
};

struct BufferQueue{
    struct Node *head;
    struct Node *tail;
    size_t size; 
    int bufferSize;
};

struct BufferQueue queueCreate(int bufferSize);



int queuePush(struct BufferQueue* q,char *message);

char* queuePop(struct BufferQueue *q);

void queueDisplay(struct BufferQueue *q);

#endif