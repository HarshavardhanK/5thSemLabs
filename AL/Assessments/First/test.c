#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;

    int*arr;
};

typedef struct Queue Q;

Q* init_q(int size) {

    Q* q = (Q*) malloc(sizeof(Q));
    q->rear = 0;
    q->front = 0;

    q->arr = (int*) malloc(sizeof(int) * size);

    return q;


}

int is_empty(Q* q) {

    if(q->front == q->rear || q->front == 0)
        return 1;
    
    return 0;
}

int dequeue(Q* q) {
    if(!is_empty(q)) {
        return q->arr[q->front++];
    }

    return -1;
}

int enqueue(Q* q, int x) {

    q->arr[q->rear++] = x;
}

#define SIZE 4

int dfs_visited[SIZE];
int bfs_visited[SIZE];
int cost[SIZE][SIZE];

void init() {

    for(int i = 0; i < SIZE; i++) {

        dfs_visited[i] = 0;
        bfs_visited[i] = 0;

        for(int j = 0; j < SIZE; j++) {
            
            cost[i][j] = 0;
        }
    }
        
            
}

void all_dfs(Q* q, int start, int graph[SIZE][SIZE]) {

    dfs_visited[start] = 1;
    printf("%c-> ", start + 97);

    enqueue(q, start);

    for(int i = 0; i < SIZE; i++) {

        if(!dfs_visited[i] && graph[start][i] != 0) {
            cost[start][i] += graph[start][i];

            while(!is_empty(q)) {

                int node = dequeue(q);

                if(node != -1) {

                    for(int i = 0; i < SIZE; i++) {

                        if(!bfs_visited[i] && graph[node][i] != 0) {
                            all_dfs(q, i, graph);
                        }
                    }
                }
            }


        }
    }
}

void take_input(int graph[SIZE][SIZE], int size) {

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            scanf("%d", &graph[i][j]);

}

int main() {

    Q* q;
    q = init_q(4);

    int size;
    printf("Enter size: \n");
    scanf("%d\n", &size);

    int graph[SIZE][SIZE];

    take_input(graph, 4);

   
}