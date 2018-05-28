#include <stdio.h>
int main()
{
	int n,k,p,x;
	k=0;
	p=1;
	scanf("%d", &n);
	do
	{
		k++;
		scanf("%d", &x);
		p=p*(x-k);
	}		
	while (k<n);
	printf("%d\n", p);
	return 0;
}
