// Addition of two numbers stored in linklist 
// Time complexity =O(m+n) , where m,n are the size of linklist
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* h1=NULL;
struct node* t1=NULL;
struct node* h2=NULL;
struct node* t2=NULL;
struct node* h3=NULL;
struct node* t3=NULL;
struct node* new=NULL;
struct node *ptr,*ptr1,*ptr2;
int flag1=0,flag2=0,num,num1,num2,output=0;
void create(int inp){
	if(flag1==0){
		new=(struct node*)malloc(sizeof(struct node));
		new->data=inp;
		h3=new;
		t3=new;
		flag1=1;
		h3->next=NULL;
		t3->next=NULL;
	}
	else{
		new=(struct node*)malloc(sizeof(struct node));
		new->data=inp;
		t3->next=new;
		t3=new;
		t3->next=NULL;
	}	
}
void create_sum(int inp){
	if(flag2==0){
		new=(struct node*)malloc(sizeof(struct node));
		new->data=inp;
		t3=new;
		h3=new;
		flag2=1;
		t3->next=h3->next=NULL;
	}
	else{
		new=(struct node*)malloc(sizeof(struct node));
		new->data=inp;
		new->next=h3;
		h3=new;
	}
	
}
void show(){
	ptr=h3;
	while(ptr!=NULL){
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}
void addition(){
	int carry=0;
	ptr1=h1;
	ptr2=h2;
	while((ptr1!=NULL)||(ptr2!=NULL)){
		num=ptr1->data+ptr2->data+carry;
		carry=num/10;
		num=num%10;
		create_sum(num);
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	if(ptr2==NULL){
		while(ptr1!=NULL){
			num=ptr1->data+carry;
			carry=num/10;
			num=num%10;
			create_sum(num);
			ptr1=ptr1->next;
		}
	}
	else if(ptr1==NULL){
		while(ptr2!=NULL){
			num=ptr2->data+carry;
			carry=num/10;
			num=num%10;
			create_sum(num);
			ptr2=ptr2->next;
		}
	}
	if(carry!=0){
		num=carry;
		create_sum(num);
	}
}
int main(){
	struct node* ptr_sum;
	int inp;
	printf("Addition of TWO no. using linklist\n");
	printf("Enter 1st number:");
	scanf("%d",&num1);
	printf("Enter 2nd number:");
	scanf("%d",&num2);
	num=num1;
	while(num!=0){
		inp=num%10;
		num=num/10;
		create(inp);
	}
	h1=h3;
	t1=t3;
	flag1=0;
	num=num2;
	while(num!=0){
		inp=num%10;
		num=num/10;
		create(inp);
	}
	h2=h3;
	t2=t3;
	addition();
	ptr_sum=h3;
	printf("SUM = ");
	show();
	return 0;
}
