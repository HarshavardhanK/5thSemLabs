#include <stdio.h>
#include <stdlib.h>
int mat[7][7] = {
                    { 0, 1, 1, 1 ,1,0,0}, 
                    { 1, 0, 0, 1 ,0,0,0}, 
                    { 1, 0, 0, 0 ,0,0,1}, 
                    { 1, 0, 0, 0 ,0,1,0},
                    { 1, 0, 0, 0, 0,0,1},
                    { 0, 0, 0, 1, 0,0,0},
                    { 0, 0, 1, 0, 1,0,0},
                   }; 

int n=7;
int V[50];


void dfs(int i)
{
    printf("%c\n",(i+65));
    
    for(int i=0;i<n;i++)
    {
        V[i]=1;
        for(int j=0;j<n;j++)
        {

            if(!V[j] && mat[i][j]==1)
            {
            
                V[j]=1;
                printf("%c\n",(j+65));
           
            }
        }

    }
   
}






int main()
{


    for(int k=0;k<n;k++)
    {
        V[k]=0;
    }

    dfs(0);
    return 0;
}