#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
    
}queue;

queue* create_queue(int cap) {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front =0;
    q->rear = cap-1;
    q->size=0;
    q->capacity = cap;
    q->arr= (int*) malloc(cap*sizeof(queue));
    return q;
}

void enqueue(queue* q, int x) {
    if(q->size==q->capacity) {
        printf("queue full\n");
        return;
    }
    else {
        q->rear = (q->rear+1) % q->capacity;
        q->arr[q->rear] = x;
        q->size++;
        return;
    }
    
}

int dequeue(queue* q) {
    if(q->size==0) {
        printf("queue empty\n");
        return -1000;
    }
    else {
        int ret = q->arr[q->front];
        q->front = (q->front +1) % q->capacity;
        q->size--;
        return ret;
    }
}

int main() {
    int cap = 2;
	queue* q = create_queue(cap);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	printf("\n");
	while(q->size>0) {
	    printf("%d\n",dequeue(q));
	}
	return 0;
}
