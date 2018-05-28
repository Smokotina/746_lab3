#include <stdio.h>
int main()
{
	int x,n,s,k;
	k=0;
	s=0;
	scanf("%d",&n);
	do
	{
		scanf("%d", &x);
		s=s+x;
		k=k+1;
	}
	while (k<n);
	printf("%d\n",s);
	return 0;
}
