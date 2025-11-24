#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct node{
    int info;
    struct node * link;
};


void addEdge(struct node **adjList,int src, int desc){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = desc;
    newNode->link = NULL;
    newNode->link = adjList[src];
    adjList[src] = newNode;

    //for undirected graph
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = src;
    newNode->link = NULL;
    newNode->link = adjList[desc];
    adjList[desc] = newNode;
}

void printGraph(struct node **adjList,int v){
    for(int i=0;i<v;i++){
        struct node *save = adjList[i];
        printf("Vertex %d:", i);
        while(save!=NULL){
            printf("%d->", save->info);
            save=save->link;
        }
        printf("NULL\n");
    }
}

void dfsUtil(struct node **adjList, int vertex, int *visited){
    visited[vertex]= 1;
    printf("%d", vertex);
    struct node *save = adjList[vertex];
    while(save!=NULL){
        if(!visited[save->info]){
            dfsUtil(adjList,save->info,visited);
        }
        save=save->link;
    }
}

void dfs(struct node **adjList, int startVertex, int v){
    int visited[MAX_VERTICES]={0};
    printf("DFS starting from vertex %d:",startVertex);
    dfsUtil(adjList,startVertex,visited);
    printf("\n");
}

void bfs(struct node **adjList, int startVertex, int v){
   int visited[MAX_VERTICES]={0};
   int queue[MAX_VERTICES];
   int front=0, rear=0;
   visited[startVertex] = 1;
   queue[rear++]= startVertex;

   printf("BFS is starting from vertex %d:", startVertex);
   while(front< rear){
    int currentVertex = queue[front++];
    printf("%d", currentVertex);

    struct node * save = adjList[currentVertex];
    while(save!=NULL){
        int adjVertex = save->info;

        if(!visited[adjVertex]){
            visited[adjVertex] = 1;
            queue[rear++] = adjVertex;
        }
        save = save->link;
    }
   }
   printf("\n");
}


int main(){
    int v=6;

    struct node * adjList[MAX_VERTICES] = {NULL};
    addEdge(adjList,0,1);
    addEdge(adjList,0,2);
    addEdge(adjList,1,3);
    addEdge(adjList,2,4);
    addEdge(adjList,3,4);
    addEdge(adjList,4,5);

    printGraph(adjList,v);

    dfs(adjList,0,v);
    bfs(adjList,0,v);
    return 0;
}