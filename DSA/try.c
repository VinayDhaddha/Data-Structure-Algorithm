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
void infix_rec(struct node* temp){
	if(temp==NULL)
		return;
	infix_rec(temp->lc);
	printf("--->%d",temp->data);
	infix_rec(temp->rc);
}
void infix_using_stack(struct node* temp){
	while(1){

		if(temp->lc!=NULL){
			push(temp);
			temp=temp->lc;
		}
		else{
			if(temp->rc!=NULL){
				printf("--->%d",temp->data);
				temp=temp->rc;
			}
			else{
				//while(1)
				while((temp->rc==NULL)&&(top>=0)){
					printf("--->%d",temp->data);
//					if((top==-1)&&(temp->data==NULL))
//						break;
					temp=pop();
				}
				printf("--->%d",temp->data);
				temp=temp->rc;
			}
		}
		if((top==-1)&&(temp==NULL))
			break;
		//temp=pop();

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
	infix_rec(root);
	printf("\n USING STACK :: ");
	infix_using_stack(root);
	return 0;
}
