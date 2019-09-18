#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
    
}queue;
typedef struct Node{
    struct Node* data;
    int data;
}Node*

typedef struct AdjList{
    Node* head;    
}AdjList;

typedef struct graph{
    int v;
    AdjList* Adj;
    int* visited;
    int* level;
}graph;

graph* create_graph(int ver) {
    graph* g = (graph*) malloc(sizeof(graph));
    g->v = ver;
    g->AdjList = (AdjList*)malloc(ver*sizeof(AdjList));
    g->visited = (int*) malloc(ver*sizeof(int));
    g->level = (int*) malloc(ver*sizeof(int));
    for(int i=0; i<ver;i++) {
        g->visited[i] =0;
        g->level[i] = 0;
    }
    return g;
}

void add_edge(graph*g, int i, int j) {
    
}

queue* create_queue(int cap) {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front =0;
    q->rear = cap-1;
    q->size=0;
    q->capacity = cap;
    q->arr= (int*) malloc(cap*sizeof(queue));
    return q;
}


int main() {
	//code
	return 0;
}
