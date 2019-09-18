#include <stdio.h>
#include <stdlib.h>

int a[10], mat[10][10], min=50, opcount=0;

int swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void permute(int b[], int n, int i, int j) {
	
	if((i<n) && (j<n)) {	
		
		int temp=0;
		swap(&b[i], &b[j]);

		if(n==1) {
			opcount++;
			for(int k=0;k<4;k++)
				temp+=mat[k][a[k]-1];
			if(min>temp)
				min=temp;
		}
		permute(&b[1],n-1,0,0);
		swap(&b[i],&b[j]);
		permute(b,n,i,j+1);
	}
}

int main () {

	int n;

	printf("Enter number of person: ");
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		a[i]=i+1;

	printf("Enter the jobs:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);

	printf("Entered cost matrix is : \n");
	
	for(int i=0;i<n;i++)
	printf(" job%d",i+1);

	printf("\n");

	for(int i=0;i<n;i++) {
		printf("Person%d: ",i+1);

		for(int j=0;j<n;j++)
			printf(" %d	",mat[i][j]);

		printf("\n");
	}

	permute(a,n,0,0);

	printf("Minimum value is : %d\n",min);
	printf("Opcount is : %d\n",opcount);

	return 0;
}            