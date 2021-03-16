// Circular linklist with deletion
// Time compplexity  =  O(n)	
#include<stdio.h>
#include<stdlib.h>
struct node{
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
int main(){
	printf("enter no. of nodes: ");
	scanf("%d",&n);
	if(n==0){
		printf("you should have to takes nodes atleast 1 node");
		return 0;
	}
	header=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&(header->data));
	ptr=header;
	count++;
	input();
	printf("INPUTS are... \n");
	show();
	delete();
	show();
	/*deletelast();
	show();
	delete();
	show();
	insert();
	show();
	reverse();
	show();*/

	return 0;
}
void input(){
	while(count<n){
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&(q->data));
		ptr->next=q;
		ptr=q;
		count++;
	}
	ptr->next=header;
	last=ptr;
}
void show(){
	if(header==NULL){
		printf("\n list is empty\n ");
	}
	else{
		ptr=header;
		while(ptr->next!=header){
			printf("------>>%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("------>>%d ",ptr->data);
	}
}
void delete(){
	int del;
	ptr=header;
	struct node* prev;
	printf("\nenter VALUE u want to delelte\n");
	scanf("%d",&del);
	if(header==NULL){
		printf("list is already empty");
	}
	if((header->next==header)&&(header->data==del)){
		header=NULL;
		return ;
	}
	else if((header->next==header)&&(header->data!=del)){
		printf("\nVALUE not PRESENT \n");
		return ;
	}
	else if ((header->next!=header)&&(header->data==del)){
		struct node* ptr=header;
		while(ptr->next!=header){    /////////
			ptr=ptr->next;
		}
		ptr->next=header->next;
		header=header->next;	
	}
	else {
		int flag=1;
		struct node* ptr=header->next;	
		struct node* prev=header;
		while(ptr->data!=del){
			prev=ptr;
			ptr=ptr->next;
			if(ptr->next==header){
				flag=0;
				break;		
			}
		}
		if(flag==0)
			printf("\nvalue not found\n");
		else{
			prev->next=ptr->next;
		}
	}
	printf("\nafter DELETING \n");
}
