#include <stdio.h>

#define VERTICES 4
#define INF 9999

void print_solution(int distance[][VERTICES]) {
    printf("Shortest distance matrix\n");

    for(int i =0; i < VERTICES; i++) {

        for(int j = 0; j < VERTICES; j++) {

            if(distance[i][j] != INF) {

                printf("%d\t", distance[i][j]);
            } else {
                printf("INF\t");
            }
        }

        printf("\n");

    }
        
}

void floyd_warshall(int graph[][VERTICES]) {

    int distance[VERTICES][VERTICES];

    for(int i = 0; i < VERTICES; i++) 
        for(int j = 0; j < VERTICES; j++) 
            distance[i][j] = graph[i][j];
        
    
    for(int k = 0; k < VERTICES; k++) {
        for(int i = 0; i < VERTICES; i++) {
            for(int j = 0; j < VERTICES; j++) {

                if(distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    print_solution(distance);
}

int main(int argc, char** argv) {

    int graph[VERTICES][VERTICES] = {{0, 5, INF, 10}, 
                                    {INF, 0,   3, INF}, 
                                    {INF, INF, 0,   1}, 
                                    {INF, INF, INF, 0}};


    floyd_warshall(graph);

    return 0; 
}