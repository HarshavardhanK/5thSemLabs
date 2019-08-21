#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int start, int vertices, int* visited, int mat[4][4]) {

    printf("PUSH %d \n", start);
    
    visited[start] = 1;

    for(int i = 0; i < vertices; i++) {

        if(!visited[i] && mat[start][i] == 1)
            dfs(i, vertices, visited, mat);
    }

    printf("POP %d \n", start);
}

int main(int argc, char** argv) {

    int* vertices = (int*) malloc(sizeof(int) * 4);
    memset(vertices, 0, 4 * sizeof(vertices[0]));

    int graph[][4] = {{0,1,1,1}, {1,0,1,0}, {1,1,0,1}, {1,0,1,0}};

    dfs(0, 4, vertices, graph);

    return 0;


}