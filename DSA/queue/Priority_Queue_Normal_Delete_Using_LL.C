#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct
{
	node *start;
}head;
void insert(head *t,int ele)
{
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=ele;
	p->next=NULL;
	if(t->start==NULL)
		t->start=p;
	else
	{
		q=t->start;
		if(q->data<ele)
		{
			p->next=q;
			t->start=p;
		}
		else
		{
			while(q->next->data>ele && q->next!=NULL)
				q=q->next;
			p->next=q->next;
			q->next=p;
		}
	}
}
void display(head *t)
{
	node *q;
	if(t->start==NULL)
	{
		printf("LL Empty\n");
		return;
	}
	q=t->start;
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
}
int deletebeg(head *t)
{
	node *p;
	if(t->start==NULL)
	{
		printf("LL Empty\n");
		return -1;
	}
	p=t->start;
	t->start=t->start->next;
	return (p->data);
}
int main()
{
	head x;
	//clrscr();
	int ch,ele;
	x.start=NULL;
	while(1)
	{
		printf("Enter choice 1:Insert 2:Delete 3:Display 4:Exit\n");
		scanf("%d",&ch);
		if(ch==4)
			break;
		switch(ch)
		{
			case 1: printf("Enter element to insert\n");
				scanf("%d",&ele);
				insert(&x,ele);
				display(&x);
				break;


			case 2: if(x.start==NULL)
					printf("Queue Empty\n");
				else
				{
					ele=deletebeg(&x);
					printf("Deleted element=%d\n",ele);
					display(&x);
				}
				break;
			case 3: display(&x);
				break;

			default:printf("Invalid choice\n");
		}
	}
	return 0;
}
