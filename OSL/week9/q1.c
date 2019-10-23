#include <stdio.h>
#include <stdlib.h>

int less(int one[],int two[]){
	for(int i=0;i<3;i++)
		if(one[i]>two[i])
			return -1;
	return 1;	
}

int bankers(int need[][3],int alloc[][3],int work[],int n){
	int finish[10];
	for(int i=0;i<10;i++)
		finish[i]=-1;
	while(1){
		int flag=0;
		
		//printf("\n");
		for(int i=0;i<n;i++){
			int flag2=1;
			
			for(int j=0;j<3;j++)
				if(need[i][j]>work[j]){
					flag2=0;
					break;
				}
				
			if(flag2==1 && finish[i]==-1){
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
	
	for(int i=0;i<n;i++)
		if(finish[i]==-1)
			res=0;
	return res;
}	



int main(){
	int alloc[10][3],max[10][3],available[10][3],need[10][3];
	
	int resources[]={10,5,7},work[3];
	int n;
	for(int i=0;i<3;i++)
		work[i]=resources[i];
	printf("Number of processes:");
	scanf("%d",&n);
	printf("Enter allocation and max matrix:");
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int x;
			scanf("%d",&x);
			alloc[i][j]=x;
			work[j]-=x;
		}
		for(int j=0;j<3;j++)
			scanf("%d",&max[i][j]);
		for(int j=0;j<3;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	}

	printf("\n\tAllocation\tMax\t\tNeed\n");
	printf("\tA  B  C\t\t");
	printf("A  B  C\t\t");
	printf("A  B  C\n");
	for(int i=0;i<n;i++){
		printf("P%d\t",i);
		for(int j=0;j<3;j++)
			printf("%d  ",alloc[i][j]);
		printf("\t");
		for(int j=0;j<3;j++)
			printf("%d  ",max[i][j]);
		printf("\t");
		for(int j=0;j<3;j++)
			printf("%d  ",need[i][j]);
		printf("\n");
	}
	printf("\n");
	
	int restore[3];
	for(int i=0;i<3;i++)
		restore[i]=work[i];

	if(bankers(need,alloc,work,n)==0)
		printf("\nNot safe state");
	else 
		printf("\nSafe state");	

	
	
	int pno=-1,req[3];
	for(int i=0;i<3;i++)
		work[i]=restore[i];
	printf("Enter process:");
	scanf("%d",&pno);

	printf("Enter request:\n");
	for(int j=0;j<3;j++)
		scanf("%d",&req[j]);
		
	if(less(req,need[pno])){
		if(less(req,work)){
			for(int j=0;j<3;j++){
				work[j]-=req[j];
				alloc[pno][j]+=req[j];
				need[pno][j]-=req[j];
			}

		}
	}
	
	int res=bankers(need,alloc,work,n);
	printf("\n\n(%d %d %d) for P%d ",req[0],req[1],req[2],pno);
	if(res==0)
		printf("can't be granted");
	else printf("can be granted");


}
