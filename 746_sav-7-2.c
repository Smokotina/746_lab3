#include <stdio.h>
#include <stdlib.h>
void shell(int n, int a[])
{
	int s;
	for (int i=n/2; i>0; i=i/2)
	{
		for (int j=i; j<n; j++)
		{
			for(int k=j-i; k>=0; k=k-i)
			{
				if (a[k+i]<=a[k])
				{
					s=a[k];
					a[k]=a[k+i];
					a[k+i]=s;
				}else break;
			}
		}
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
	shell(n,a);
	for(int i=0; i<n; i++)
	{
		printf("%d ", (a[i]));
	}
	printf("\n");
	return 0;
}
