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

typedef struct stek
{
        int value1;
        struct stek *next;
        struct stek *PREV;
}stek;


stek * head=NULL;
stek *tail=NULL;


int isEmptyStek()
{
        if (head==NULL && tail==NULL)
                return 1;
        else
                return 0;
}


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

void pushBack( int a)
{
        if (isEmptyStek()!=0)
        {
                stek *ptr = (stek*) malloc(sizeof(stek));
                ptr->value1 = a;
                head= ptr;
                tail = ptr;
                ptr->next = NULL;
                ptr->PREV= NULL;
        }
        else
	{
                stek *ptr = (stek*) malloc (sizeof(stek));
                ptr->value1 = a;
                ptr->next = NULL;
                ptr->PREV = tail;
                tail->next = ptr;
                tail=ptr;
                if (tail==NULL)
                        head=ptr;
                if (ptr==NULL)
                        exit(1);
	}
}

int popNum()
{
	int z;
        if (isEmptyStek() == 0)
        {
                stek  *ptr = tail;
                if (ptr==head)
                {
                                head=NULL;
                                tail=NULL;
				z=ptr->value1;
                                free(ptr);
                                return z;
                }
                else
                {
                        ptr->PREV->next=NULL;
                        tail= ptr->PREV;
			z=ptr->value1;
                        free(ptr);
                        return z;
               }
        }
        else
                return 0;
}

abc *poisk(int a)
{
	abc *ptr=kor;
	while(ptr!=NULL)
	{
		if (ptr->key==a)
			return ptr;
		if (ptr->key>a)
			ptr=ptr->left;
		else ptr=ptr->right;
	}
}


int s()
{
	if (isEmpty==0)
		exit(1);
	else
	{
		int k;
        	abc *ptr=kor;
		pushBack(ptr->key);
		while(isEmptyStek()!=1)
		{
			k=popNum();
			ptr=poisk(k);
                	if (ptr->right!=NULL)
				pushBack(ptr->right->key);
                	if (ptr->left!=NULL)
				pushBack(ptr->left->key);
			if (isEmptyStek()!=1)	
				printf("%d ", ptr->value);
			else printf("%d", ptr->value);
		}	
		printf("\n");
	}
}

int main()
{
        scanf("%d", &n);
                for(int i=0; i<n; i++)
                {
                        scanf("%d", &a);
                        scanf("%d", &b);
                        push(a,b);
                }
	s();
        return 0;
}

