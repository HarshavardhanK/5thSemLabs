#include <stdio.h>
#include <stdlib.h>
int mat[7][7] = {
                    { 0, 1, 1, 1 ,1,0,0}, 
                    { 1, 0, 0, 1 ,0,1,0}, 
                    { 1, 0, 0, 0 ,1,0,1}, 
                    { 1, 1, 0, 0 ,0,1,0},
                    { 1, 0, 1, 0, 0,0,1},
                    { 0, 1, 0, 1, 0,0,0},
                    { 0, 0, 1, 0, 1,0,0},
                   }; 

int n=7;
int V[50];


void bfs(int start) {

    V[start] = 1;

    printf("%c ", start + 97);

    for(int i = start; i < n; i++) {

        int set_start = 1;

        for(int j =0; j < n; j++) {

            if(!V[j] && mat[i][j] == 1) {

                V[j] = 1;
                printf("%c ", j + 97);

                if(set_start == 1) {
                    start = j;
                    set_start = 0;
                }
                

             }

        }

        
    }

    printf("\n");
}





int main()
{


     for(int k=0;k<n;k++)
    {
        V[k]=0;
    }

    bfs(2);
    return 0;
}