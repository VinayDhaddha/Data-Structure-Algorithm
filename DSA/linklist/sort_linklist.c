// sorting of linklist 
// Time complexity =O(n^2), where n is no. of inputs
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node *header,*ptr;
int n,count=0;
void create();
void show();
int main(){
	printf("enter no. of node req. for linklist\n");
	scanf("%d",&n);
	printf("Enter values :\n");
	while(count<n){
		create();
		count++;
	}
	show();
	return 0;
}
void create(){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&(temp->data));
	if((header==NULL)||((header->data)>(temp->data))){
		//printf("----------------------->>>>>>>>>>>>>>yes1\n");
		temp->next=header;
		header=temp;
		return;		
	}
	else{
		struct node *temp1=header;
		struct node *temp2;
		while(1){
			//printf("----------------------->>>>>>>>>>>>>>yes2\n");
			//printf("----------------------->>>>>>>>>>>>>>yes2\n");
			if(((temp1->data)<(temp->data))&&(temp1->next==NULL)){
				//printf("----------------------->>>>>>>>>>>>>>yes3\n");
				temp1->next=temp;
				temp->next=NULL;
				return;		
			}
			else if(((temp1->data)<(temp->data))&&((temp1->next->data)>(temp->data))){
				//printf("----------------------->>>>>>>>>>>>>>yes4\n");
				temp2=temp1->next;
				temp1->next=temp;
				temp->next=temp2;
				return;
			}
			temp1=temp1->next;
		}
		
	}
}
void show(){
	ptr=header;
	while(ptr!=NULL){
		printf("%d   ",ptr->data);
		ptr=ptr->next;
	}
	
}
