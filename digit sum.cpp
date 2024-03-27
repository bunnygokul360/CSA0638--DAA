#include<stdio.h>
int main()
{
	int a,d,i,sum=0,rem=0;
	printf("Enter the number : ");
	scanf("%d",&a);
	d=a;
	while(a!=0)
	{
		rem=a%10;
		sum+=rem;
		a=a/10;
	}
	printf("The sum of digits %d are: %d",d,sum);
}

