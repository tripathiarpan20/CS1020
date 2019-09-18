#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

typedef struct stack{
    Node* head;
    int capacity;
    int size;
}stack;


void push(stack* s, int x) {
    if(s->size == s->capacity) {
        printf("Stack Overflow\n");
        return;
    }
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    if(s->head==NULL) s->head = temp;
    else{
        temp->next = s->head;
        s->head = temp;
    }
    s->size++;
    return;
}

int pop(stack* s) {
    if(s->size==0) {
        printf("Stack Empty\n");
        return -10000;
    }
    int ret = s->head->data;
    s->head = s->head->next;
    s->size--;
    return ret;
}

int empty(stack* s) {
    if(s->size==0) return 1;
    else return 0;
}

void main() {
    stack s;
    s.capacity = 1;
    push(&s,10);
    push(&s,20);
    push(&s,30);
    printf("\n");
    while(!empty(&s)) {
        printf("%d\n",pop(&s));
    }
    return;
}
