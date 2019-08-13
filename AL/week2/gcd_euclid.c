#include<stdio.h>

int gcd(int m, int n) {
	int opCount = 0;
	while (n != 0) {
		opCount++;
		int rem = m % n;
		m = n;
		n = rem;
	}
	printf("OpCount is %d\n", opCount);
	return m;
}

int main(int argc, char const *argv[])
{
	int num1;
	int num2;
	printf("Enter 2 nums: ");
	scanf("%d%d", &num1, &num2);
	printf("GCD is: %d\n", gcd(num1, num2));
	return 0;
}