// single linklist with Pairwise swap
// Time complexity =O(n)
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* header;
struct node* ptr=NULL;
struct node* q=NULL;
struct node* prev=NULL;
int n,count,del,flag=0,before_val=0,value=0;
void input();
void show();
void delete();
void insert();
void pairswap();
int main(){
	count=0;
	printf("Enter no. of nodes:- ");
	scanf("%d",&n);
	if(n==0){
		printf("you should have to takes nodes atleast 1 node");
		return 0;
	}
	if(n!=0){
		header=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&(header->data));
		ptr=header;
		count++;
	}
	input();
	printf("Entered list is :-\n");
	show();
	//printf("\nl NOW deleting req. value;\nEnter NODE VALUE which u want to delete (<n) :-");
	//scanf("%d",&del);
	//delete(del);
	//show();
	//printf("NOW INSERTING req. value;\nEnter VALUE & before_value of insertion which u want to delete (<n) :-");
	//scanf("%d%d",&value,&before_val);void show(){
	/*if(header==NULL){
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
	insert();
	show();
	printf("\n now we r REVERSING LIST \n");
	reverse();
	show();*/
	//middle();
	pairswap();
	printf("pairswap Entered list is :-\n");
	show();
	return 0;
}
void input(){
	while(count<n){
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&(q->data));
		ptr->next=q;
		ptr=q;
		ptr->next=NULL;
		count++;
	}
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
void delete(){
	count=0;
	ptr=header;
	if(del>(n-1)){
		printf("error OUT OF NODES\n");
	}
	else if(header==NULL){
		printf("\n list is already empty \n");
	}
	else{
		while(count<n){
			if(ptr->data==del){
				if(header->data==del){
					header=header->next;
					flag=1;
					break;
				}
				else{
					prev->next=ptr->next;
					flag=1;
					break;
				}
			}	
			prev=ptr;
			ptr=ptr->next;	
			count++;
		}
		if(flag!=1){
			printf("\nNO. not present\n");
		}		
	}
}
void insert(){
	ptr=header;
	if(header==NULL){
		printf("list is empty");
	}
	else{
		while(ptr->data!=before_val){
			ptr=ptr->next;
			if(ptr->next==NULL){
				printf("NOT ABLE AS PER REQ.");
				return;
			}
		}
		q=(struct node*)malloc(sizeof(struct node));
		q->data=value;
		q->next=ptr->next;
		ptr->next=q;
		ptr=q;
	} 
}
void reverse(){
	struct node* prev;
	struct node* nxt;
	ptr=header;
	if(header->next==NULL)
		printf("single element present in list");
	else{
		while(ptr->next!=NULL){
			if(ptr==header){
				nxt=ptr->next;
				ptr->next=NULL;
				prev=ptr;
				ptr=nxt;
			}
			else{
				nxt=ptr->next;
				ptr->next=prev;
				prev=ptr;
				ptr=nxt;
			}
		}
	}
	ptr->next=prev;
	header=ptr;
}
void middle(){
	struct node *p1,*p2;
	p1=p2=header;
	if(header==NULL){
		printf("\n list is empty\n");
		return ;
	}
	else if(header->next==NULL){
		printf("\nmiddle is %d\n",header->data);
	}
	else{
		while((p2!=NULL)&&(p2->next!=NULL)){
			p1=p1->next;
			p2=p2->next->next;
		}
		printf("\n middle is %d \n",p1->data);
		return;
	}
}
void pairswap(){
	printf("\n -------------------------------------->>>>>.yes\n");
	struct node *p1,*p2,*p3;
	if((header==NULL)||(header->next==NULL)){
		printf("\n swappig not req.\n");
		return;
	}
	p1=header;
	p2=p1->next;
	p3=p2->next;
	header=p2;
	while(1){
		//temp=p2->next;
		p2->next=p1;
		if((p3==NULL)||((p3->next)==NULL)){
			p1->next=p3;
			break;
		}
		else{
			p1->next=p3->next;
			p1=p3;
			p2=p1->next;
			p3=p2->next;
			//p2->next=temp;
		}
	}
}



