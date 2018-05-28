#include <stdio.h>
#include <stdlib.h>

int n, num;

typedef struct abc
{
	int value;
	struct abc *next;
	struct abc *prev;
}abc;

int size=1;
abc * head=NULL;
abc *tail=NULL;

int init( int per)
{
	abc *ptr = (abc*) malloc(sizeof(abc));
	ptr->value = per;
	head= ptr;
	tail = ptr;
	ptr->next = NULL;
	ptr->prev= NULL;	
}

int isEmpty()
{
	if (head==NULL && tail==NULL)
		return 1;
	else
		return 0;
}

void pushBack( int per)
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
}

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

int deleteNum(int n, int size)
{
	int per=1;
	if (isEmpty() == 0)
	{
	if (size<n ||  n<1)
		exit(1);
	else{
		abc *ptr = head;
		while(per!=n)
		{
			ptr= ptr->next;
			per++;
		}
		if (ptr->prev==NULL || ptr->next==NULL)
		{
			if (ptr->prev==NULL)
			{
				ptr->next->prev=NULL;
				head=ptr->next;
				free(ptr);
			}
			else	
			{
				ptr->prev->next=NULL;
				tail= ptr->prev;
				free(ptr);
			}
		}
		else
		{
			ptr->prev->next=ptr->next;
			ptr->next->prev= ptr->prev;
			free(ptr);
	}	}
	}
}

int deleteZnach(int n, int size)
{
	if (isEmpty() == 0)
	{
		int k=0;
		abc *ptr = head;
		while (ptr->value != n)
		{
			ptr=ptr->next;
			k++;
			if (k>size)
				exit(1);
		}//Почему не выходит, если брать несущ элемент!?

		if(ptr->prev==NULL || ptr->next==NULL)
		{
			if (ptr->prev==NULL)
			{
				ptr->next->prev=NULL;
				head=ptr->next;
				free(ptr);
			}
			else
			{
				ptr->prev->next=NULL;
				tail=ptr->prev;
				free(ptr);
			}
		}
		else
		{
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);			
		}
	}
}


int pushPosle(int n, int num, int size)
{
if (size<n || n<1)
	exit(1);
else
{
	int per=1;
	abc *ptr= head;
	abc *ptr1= (abc*) malloc(sizeof(abc));
	while (per!= n)
	{
		ptr=ptr->next;
		per++;
	}
	if(ptr->next==NULL)
	{
		ptr1->value=num;
		ptr1->next=NULL;
		ptr1->prev = ptr;
		ptr->next=ptr1;
		tail=ptr1;
	}

	else
	{
		ptr1->value=num;
		ptr1->prev=ptr;
		ptr1->next=ptr->next;
		ptr->next->prev=ptr1;
		ptr->next=ptr1;
	}
}}

int pushDo(int n, int num, int size)
{
if (size<n || n<1)
	exit(1);
else{	
	int per=1;
	abc *ptr=head;
	abc *ptr1=(abc*) malloc (sizeof(abc));
	while (per!=n)
	{
		ptr=ptr->next;
		per++;
	}
	if( ptr->prev==NULL)
	{
		ptr1->value = num;
		ptr->prev=ptr1;
		head = ptr1;
		ptr1->next=ptr;
	}
	else
	{
		ptr1->value=num;
		ptr1->prev=ptr->prev;
		ptr->prev->next=ptr1;
		ptr->prev=ptr1;
		ptr1->next=ptr;
	}
}}

int main()
{
	//int sch=1;
	scanf("%d", &n);
	scanf("%d", &num);
	if (isEmpty() == 1)
	{	
		init(num);
		for(int i=1; i<n; i++)
		{		
			scanf("%d", &num);
			pushBack(num);
			size++;	
		}
		printabc();
	}
	scanf("%d", &num);
	deleteNum(num, size);
	size--;
	printabc();
	
	scanf("%d", &num);
	deleteZnach(num, size);
	size--;
	printabc();	
	
	scanf("%d %d", &n, &num);
	pushPosle(n, num, size);
	size++;
	printabc();

	scanf("%d%d", &n, &num);
	pushDo(n, num, size);
	size++;
	printabc();

	return 0;
}
