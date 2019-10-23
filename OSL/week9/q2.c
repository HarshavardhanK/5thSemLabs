#include <stdio.h>
#include <stdlib.h>

int less(int one[],int two[]){
	for(int i=0;i<3;i++)
		if(one[i]>two[i])
			return -1;
	return 1;	
}

void detection(int request[][3],int alloc[][3],int available[],int n){
	int finish[10]={1};
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			if(alloc[i][j]!=0)
				finish[i]=-1;
	int work[3];
	for(int i=0;i<3;i++)
		work[i]=available[i];

	while(1){
		int flag=0;
		
		for(int i=0;i<n;i++){
			int flag2=1;
		
			if(less(request[i],work)==1 && finish[i]==-1){
				flag=1;
				
				printf("\nP%d\n",i);

				
				for(int j=0;j<3;j++)
					work[j]+=alloc[i][j];
				for(int j=0;j<3;j++)
					printf("%d\t",work[j]);
				printf("\n");
				finish[i]=1;
				break;
			}
		}	
		if(flag==0)
		break;
	}

	int res=1;
	
	for(int i=0;i<n;i++){
		if(finish[i]==-1){ 
			printf("P%d deadlocked\n",i);
			res=0;
		}
	}		
	if(res)
		printf("Not deadlocked");
}	



int main(){
	int alloc[10][3],request[10][3];
	int available[3]={0,0,0};
	int n;

	printf("Number of processes:");
	scanf("%d",&n);
	printf("Enter allocation and request matrix:");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int x;
			scanf("%d",&x);
			alloc[i][j]=x;
			
		}
		for(int j=0;j<3;j++)
			scanf("%d",&request[i][j]);
		
	}

	printf("\n\tAllocation\tRequest\n");
	printf("\tA  B  C\t\t");
	printf("A  B  C\n");
	
	for(int i=0;i<n;i++){
		printf("P%d\t",i);
		for(int j=0;j<3;j++)
			printf("%d  ",alloc[i][j]);
		printf("\t");
		for(int j=0;j<3;j++)
			printf("%d  ",request[i][j]);
		printf("\n");
		
	}
	printf("\n");
	
	
	for(int j=0;j<3;j++)
		printf("%d  ",available[j]);

	detection(request,alloc,available,n);
	
	request[2][2]++;

	detection(request,alloc,available,n);
}