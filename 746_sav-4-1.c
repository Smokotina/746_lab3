#include <stdio.h>
#include <stdlib.h>

int n,num;
typedef struct abc
{
        int value;
        struct abc *next;
        struct abc *prev;
}abc;


abc * head=NULL;
abc *tail=NULL;

 
int isEmpty()
{
        if (head==NULL && tail==NULL)
                return 1;
        else
                return 0;
}


void pushBack( int per)
{
	if (isEmpty()!=0)
	{		
		abc *ptr = (abc*) malloc(sizeof(abc));
        	ptr->value = per;
        	head= ptr;
        	tail = ptr;
        	ptr->next = NULL;
	        ptr->prev= NULL;
	}
	else
{
        	abc *ptr = (abc*) malloc (sizeof(abc));
        	ptr->value = per;
        	ptr->next = NULL;
        	ptr->prev = tail;
        	tail->next = ptr;
        	tail=ptr;
       		if (tail==NULL)
                	head=ptr;
        	if (ptr==NULL)
  	        	exit(1);
}}


void printabc()
{
        abc *ptr = head;
        while(ptr!=NULL)
        {
                printf("%d", ptr->value);
                ptr = ptr->next;
                printf(" ");
        }
        printf("\n");
}

int popNum()
{       
        if (isEmpty() == 0)
        {
                abc *ptr = tail;
		printf("%d\n", ptr->value);
                if (ptr==head)
                {
                                head=NULL;
				tail=NULL;
                                free(ptr);
				return 1;
                }
                else
                {
                        ptr->prev->next=NULL;
                        tail= ptr->prev;
                        free(ptr);
			return 1;
 	       }    
        }
	else
		return 0;
}

int top()
{
if (isEmpty() == 0)
        {
                abc *ptr = tail;
                printf("%d\n", ptr->value);
        }
else
        return 0;
}


int main()
{
	scanf("%d", &n);
                for(int i=0; i<n; i++)
                {
                        scanf("%d", &num);
                        pushBack(num);
                }
                printabc();

	for(int i=0; i<=n; i++)
	{     
        	top();
		popNum();
        	printabc();
	}
return 0;

}
