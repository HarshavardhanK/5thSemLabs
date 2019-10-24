//Harshavardhan K

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int min_distance(int dist[], int spt_set[], int V) {

    int min = INT_MAX;
    int min_index = -1;

    for(int v = 0; v < V; v++) {

        if(!spt_set[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[][8], int size, int source) {

    printf("Running Dijkstra\n");
    int dist[size];
    int found[size];

    for(int i = 0; i < size; i++) {
        dist[i] = graph[source][i];
        //printf("%d ", graph[source][i]);
        found[i] = 0;
    }

    dist[source] = 0;
    found[source] = 1;

    for(int i = 0; i < size - 2; i++) {
        int u = min_distance(dist, found, size);
        //printf("Min is %d at %d\n", u, i);
        found[u] = 1;

        for(int w = 0; w < size; w++) {

            if(!found[w]) {

                if(dist[u] + graph[u][w] < dist[w]) {
                    dist[w] = dist[u] + graph[u][w];
                    printf("%d\n", graph[u][w]);
                }
            }
        }
    }

    for(int i = 0; i < 8; i++)
        printf("%d ", dist[i]);
}

int main(int argc, char** argv) {


    int graph[][8] = {          {0, 10, 1, 100, 100, 100, 2, 100},
                                {10, 0, 100, 2, 100, 100, 3, 6},
                                {1, 100, 0, 100, 3, 100, 100, 100},
                                {100, 2, 100, 0, 100, 1, 100, 100},
                                {100, 100, 3, 100, 0, 9, 5, 100},
                                {100, 100, 100, 1, 9, 0, 100, 100},
                                {2, 3, 100, 100, 5, 100, 0, 100},
                                {100, 6, 100, 100, 100, 100, 100, 0}

                    };

    /*printf("Enter graph\n");

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            scanf("%d", &graph[i][j]);*/
    
    dijkstra(graph, 8, 0);

    
    
    printf("\n");
}