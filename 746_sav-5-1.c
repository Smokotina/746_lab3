#include <stdio.h>
#include <stdlib.h>

int n, a, b;

typedef struct abc
{
	int value;
	int key;
	struct abc *right;
	struct abc *left;
}abc;


abc *kor =NULL;

int isEmpty()
{
	if (kor==NULL)
		return 0 ;
	else 
		return 1;
}


int push ( int a, int b)
{
if (isEmpty()== 1)
{
	abc *ptr=kor;
	abc *prev=ptr;
	abc *ptr1= (abc*) malloc(sizeof(abc));	
	while (ptr!=NULL)
	{
		if(ptr->key==a)
		{
			ptr->value=b;
			exit(1);
		}
		prev=ptr;
		if (ptr->key<a)
			ptr=ptr->right;
		else ptr=ptr->left;
	}
	ptr1->right=NULL;
	ptr1->left=NULL;
	ptr1->key=a;
	ptr1->value=b;
	if (prev->key<a)
		prev->right=ptr1;
	else prev->left=ptr1;
	
}
else
{
       	abc *ptr1= (abc*) malloc(sizeof(abc));
       	kor=ptr1;
	ptr1->right=NULL;
	ptr1->left=NULL;
	ptr1->value=b;
	ptr1->key=a;
}

}


int s( int a)
{
	int k=0;
	abc *ptr=kor;
	while(ptr!=NULL)
	{
		if (a==ptr->key)
		{
			printf("%d %d", k, ptr->value);
			printf("\n");
			return 1;
		}
		if (a>ptr->key)
                        ptr=ptr->right;
                else ptr=ptr->left;
		k++;
	}
	printf("-1\n");
}

int main()
{
	scanf("%d", &n);

                for(int i=0; i<n; i++)
                {
                        scanf("%d", &a);
			scanf("%d", &b);
                        push(a, b);
                }
               
        
	for(int i=0; i<3; i++)
                {
                        scanf("%d", &a);
                        s(a);
                }

	return 0;
}

