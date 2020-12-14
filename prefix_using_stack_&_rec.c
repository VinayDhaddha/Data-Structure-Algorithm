#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* rc;
	int data;	
	struct node* lc;
};
int top=-1;
//struct node* pre_pop=-1;
struct node* create(int inp){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=inp;
		temp->lc=temp->rc=NULL;
		return temp;
}
struct node* stack[10];
void push(struct node* ad){
	stack[++top]=ad;
}
struct node* pop(){
	return stack[top--];
}
void prefix_rec(struct node* temp){
	if(temp==NULL)
		return;
	printf("--->%d",temp->data);
	prefix_rec(temp->lc);
	prefix_rec(temp->rc);
}
void prefix_using_stack(struct node* temp){
	while(1){
	
		if((temp->lc!=NULL)||(temp->rc!=NULL)){
			printf("--->%d",temp->data);
			//push(temp);
			if(temp->rc!=NULL){
				push(temp->rc);
			}
			if(temp->lc!=NULL){
				push(temp->lc);
			}	
		}
		else{
			printf("--->%d",temp->data);
			//pre_pop=temp;
		}
		if(top==-1)
			break;
		temp=pop();

	}
}
int main(){
	struct node* root=NULL;
	root=create(10);
	root->lc=create(20);
	root->rc=create(30);
	root->lc->lc=create(40);
	root->lc->rc=create(50);
	root->rc->lc=create(60);
	root->rc->rc=create(70);
	root->lc->lc->lc=create(80);
	root->rc->rc->rc=create(100);
	printf("USING RECURSION :: ");
	prefix_rec(root);
	printf("\n USING STACK :: ");
	prefix_using_stack(root);
	return 0;
}
