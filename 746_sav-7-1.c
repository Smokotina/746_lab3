#include <stdio.h>
#include <stdlib.h>
 
void rasch(int n,int a[])
{
	double fact=1.2473309;
	int s, k;
	for (;;)
	{
		s=fact;
		int flag=0;
		for (int i=0; i<n-s; i++) 
		{
			int j = i+s;
			if (a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
				flag=1;
			}
		}
		if (!flag && s==1) break;
	}
}


int main ()
{
	int n;
	int *a;
	scanf("%d", &n);
	a=(int *)calloc(n, sizeof(int));
	for (int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	rasch(n,a);
	for(int i = 0;i < n;i++)
	{
		printf("%d ", (a[i]));
	}
	printf("\n");
	return 0;
}
