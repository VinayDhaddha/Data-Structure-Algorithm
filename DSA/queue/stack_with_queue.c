#include<stdio.h>
struct node{
	int data;
	struct node* next;
};
int i;
struct node* front1=NULL;
struct node* temp=NULL;
struct node* front2=NULL;
struct node* rear1=NULL;
struct node* rear2=NULL;
struct node* q1=NULL;
struct node* q1=NULL;
void enqueue(int inp){
	if(front1==NULL){
		q1=(struct node*)malloc(sizeof(struct node));
		q1->data=inp;
		front1=q1;
		rear1=q1;
	}
	else{
		q1=(struct node*)malloc(sizeof(struct node));
		q1->data=inp;
		rear1=q1;
	}
	
}
int main(){
	int n;
	printf("enter inputs\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&inp);
		enqueue(inp);
	}
		
}
