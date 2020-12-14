#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int data)
{
struct node* node = (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}

void morrisPostorderTraversal(struct node *root){
	struct node *dummyRoot = newNode(0);
	dummyRoot->left = root;
	struct node *p = dummyRoot, *pred, *first, *middle, *last;
	while(p!=NULL){
	    if(p->left == NULL){
	        p = p->right;
	    }
			else{
	        pred = p->left;
	        while(pred->right!=NULL && pred->right != p){
	            pred = pred->right;
	        }
	        if(pred->right == NULL){
					    pred->right = p;
					   	p = p->left;
	        }
					else {
	            first = p;
	            middle = p->left;
	            while(middle!=p){
	                last = middle->right;
	                middle->right = first;
	                first = middle;
	                middle = last;
	            }

	            // visit the nodes from pred to p
	            // again reverse the right references from pred to p
	            first = p;
	            middle = pred;
	            while(middle!=p){

	                printf(" %d ",middle->data);
	                last = middle->right;
	                middle->right = first;
	                first = middle;
	                middle = last;
	            }

	            // remove the pred to node reference to restore the tree structure
	            pred->right = NULL;
	            p = p-> right;
	        }
	    }
	}
}
int main()
{
struct node *root = newNode(1);
root->left	 = newNode(2);
root->right	 = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->left->left->right = newNode(6);
root->left->left->right->right = newNode(7);
root->left->left->right->right->right = newNode(8);
morrisPostorderTraversal(root);
getchar();
return 0;
}
