// double linklist with delete ,insertion after which value,reverse
// Time complexity =O(n)
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* header;
struct node* ptr=NULL;
struct node* q=NULL;
struct node* last=NULL;
int n,count;
void input();
void show();
void delete();
void insert();
void reverse();
int main(){
	printf("enter no. of nodes: ");
	scanf("%d",&n);
	if(n==0){
		printf("you should have to take atleast 1 node");
		return 0;
	}
	header=(struct node*)malloc(sizeof(struct node));
	header->prev=NULL;
	scanf("%d",&(header->data));
	ptr=header;
	count++;
	input();
	printf("INPUTS are... \n");
	show();
	/*deletefirst();
	show();
	deletelast();
	show();*/
	delete();
	show();
	insert();
	show();
	reverse();
	show();

	return 0;
}
void input(){
	while(count<n){
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&(q->data));
		ptr->next=q;
		q->prev=ptr;
		ptr=q;
		ptr->next=NULL;
		count++;
	}
	last=ptr;
}
void show(){
	if(header==NULL){
		printf("list is empty");
	}
	else{
		ptr=header;
		while(ptr!=NULL){
			printf("------>>%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}
/*void deletefirst(){
	ptr=header;
	if(ptr->next==NULL){
		printf("\n after DELETING FIRST VALUE NOW LIST IS EMPTY \n");
		header=NULL;
		return;
	}
	ptr=ptr->next;
	ptr->prev=NULL;
	header=ptr;
	printf("\n after DELETING FIRST VALUE OF LIST... \n");
}
void deletelast(){
	printf("\n after DELETING FIRST VALUE OF LIST... \n");
	ptr=header;
	if(header==NULL){
		return;
	}
	else if(header->next==NULL){
		header=NULL;
		last=NULL;
		return;
	}
	else{
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		last=ptr->prev;
	}
	return;
}*/
void delete(){
	struct node* temp;
	ptr=header;
	int del;
	if(header==NULL){
		return;
	}
	printf("\n enter VALUE u want to delete:- ");
	scanf("%d",&del);
	if(header->data==del){
		ptr=ptr->next;
		ptr->prev=NULL;
		header=ptr;
		return;
    }
    else if(last->data==del){
    	last->prev->next=NULL;    	
    	return ;
    }
	while(ptr->data!=del){
		ptr=ptr->next;
		if(ptr==NULL){
			printf("Number NOT FOUND!!!\n");
			return ;
		}
	}
	temp=ptr->next;
	ptr->prev->next=temp;
	temp->prev=ptr->prev;
	ptr=temp;
	printf("AFTER deleting %d from linklist",del);
}
void reverse(){
	struct node* temp=NULL;
	ptr=header;
	while(ptr!=last){	
		temp=ptr->next;
		ptr->next=ptr->prev;
		ptr->prev=temp;
		ptr=temp;
	}
	temp=ptr->next;
	ptr->next=ptr->prev;
	ptr->prev=temp;
	ptr=temp;
	temp=header;
	header=last;
	last=temp;
	printf("\n after REVERSING LIST \n");
}
void insert(){
	printf("\n------->enter VALUE U want to insert and BEFORE_VALUE als\n");
	struct node* temp;
	int inp,b_inp;
	scanf("%d%d",&inp,&b_inp);
	if(header==NULL)
		return;
	else if((header->next==NULL)&&(header->data==b_inp)){
		q=(struct node*)malloc(sizeof(struct node));
		q->data=inp;
		q->prev=header;
		q->next=NULL;
	}
	else if((header->next==NULL)&&(header->data!=b_inp)){
		printf("\n not fount BFORE VALUE of INSERT VALUE \n");
		return;
	}
	 if((last->data)==b_inp){
		q=(struct node*)malloc(sizeof(struct node));
		q->data=inp;
		q->prev=last;
		q->next=NULL;
		last->next=q;
		last=q;
		printf("\nlist with INSERTED VALUE\n");
	}
	else{
		ptr=header;
		while(ptr->data!=b_inp){
			ptr=ptr->next;
		}
		if(ptr==last){
			q=(struct node*)malloc(sizeof(struct node));
			q->data=inp;
			q->prev=ptr;
			q->next=NULL;
		}
		else{
			q=(struct node*)malloc(sizeof(struct node));
			temp=ptr->next;
			ptr->next=q;
			q->prev=ptr;
			ptr=temp;
			temp->prev=q;
			q->next=temp;
			q->data=inp;
		}
		printf("\nlist with INSERTED VALUE\n");
	}
}
