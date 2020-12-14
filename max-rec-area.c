//#include <stdio.h>
//#include<math.h>
//#include<stdlib.h>
//struct node{
//    struct node* prev;
//    int index;
//    struct node* next;
//};
//int top=-1,i=0;
//struct node* head=NULL;
//struct node* ptr=NULL;
//void push(int* arr,int val){
//    if(head==NULL){
//        head=(struct node*)malloc(sizeof(struct node));
//        head->index=i;
//        ptr=head;
//    }
//    else{
//       struct node* newnode=(struct node*)malloc(sizeof(struct node));
//       newnode->prev=ptr;
//       ptr->next=newnode;
//       newnode->index=i;
//       ptr=newnode;
//    }
//    top=i;
//}
//int isempty(){
//    if(top==-1)
//        return 1;
//    else
//        return 0;
//}
//void pop(){
//    if(ptr->prev==NULL){
//        top=-1;
//        head=NULL;
//    }
//    else{
//        top=ptr->index;
//        ptr=ptr->prev;
//        ptr->next=NULL;
//    }
//}
//int max_rect_area(int* arr,int n){
//    //printf("\n---------------yes---------\n");
//    int area=0,max_area=-1;
//    int flag=0;
//    while(i<n){
//        if((isempty()==1)||(arr[top]<=arr[i])){
//            push(arr,i);
//            printf("\n---------------yes---------\n");
//            i++;
//        }
//        else{
//            int current=top;
//            pop();
//            while(arr[current]>=arr[i]){
//                if(isempty()==0){
//                    area=arr[current]*(i-top-1);
//                    printf("\n ONE----%d--------\n",area);
//                }
//                else{
//                    area=arr[current]*i;
//                    printf("\n-TWO---%d--------\n",area);
//                    flag=1;
//                }
//                if(area>max_area)
//                    max_area=area;
//                if(flag==1){
//                    flag=0;
//                    break;
//                }
//
//                current=top;
//                pop();
//            }
//        }
//    }
//    if(isempty==0){
//        int current=top;
//        pop();
//        while(1){
//            if(isempty()==0){
//                area=arr[current]*(i-top-1);
//                printf("\n IN----%d--------\n",area);
//            }
//            else{
//                area=arr[current]*i;
//                printf("\n IN----%d--------\n",area);
//                flag=1;
//            }
//            if(area>max_area)
//                max_area=area;
//            if(flag==1){
//                flag=0;
//                break;
//            }
//
//            current=top;
//            pop();
//        }
//    }
//    return max_area;
//}
//int main() {
//	int t,n,j,max;
//	scanf("%d",&t);
//	while(t--){
//	    scanf("%d",&n);
//	    int arr[n];
//	    for(j=0;j<n;j++){
//	        scanf("%d",&arr[j]);
//	    }
//	    max=max_rect_area(arr,n);
//	    printf("%d\n",max);
//	}
//	return 0;
//}
#include<math.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int index;
    struct node* next;
};
int top,i;
struct node* head=NULL;
struct node* ptr=NULL;
void push(int* arr,int val){
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->index=i;
        ptr=head;
    }
    else{
       struct node* newnode=(struct node*)malloc(sizeof(struct node));
       newnode->prev=ptr;
       ptr->next=newnode;
       newnode->index=i;
       ptr=newnode;
    }
    top=i;
}
int isempty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void pop(){
    if(ptr->prev==NULL){
        top=-1;
        head=NULL;
        ptr=NULL;
    }
    else{
        ptr=ptr->prev;
        top=ptr->index;
        ptr->next=NULL;
    }
}
int max_rect_area(int* arr,int n){
    i=0;
    top=-1;
    head=ptr=NULL;
    //printf("\n---------------yes---------\n");
    int area=0,max_area=-1;
    int flag=0;
    while(i<n){
        if((isempty()==1)||(arr[top]<=arr[i])){
            push(arr,i);
            i++;
            //printf("\n-----top=%d----i=%d------yes---------\n",top,i);
        }
        else{
            int current=top;
            while(arr[current]>=arr[i]){
                pop();
                if(isempty()==0){
                    area=arr[current]*(i-top-1);
                    //printf("\n ONE----TOP=%d--%d--------\n",top,area);
                }
                else{
                    area=arr[current]*i;
                   // printf("\n-TWO--TOP=%d--%d--------\n",top,area);
                    flag=1;
                }
                if(area>max_area)
                    max_area=area;
                if(flag==1){
                    flag=0;
                    break;
                }
                current=top;
            }
        }
    }
    if(isempty()==0){
        int current=top;
        pop();
        while(1){
            if(isempty()==0){
                area=arr[current]*(i-top-1);
               // printf("\n IN----%d--------\n",area);
            }
            else{
                area=arr[current]*i;
                //printf("\n IN----%d--------\n",area);
                flag=1;
            }
            if(area>max_area)
                max_area=area;
            if(flag==1){
                flag=0;
                break;
            }

            current=top;
            pop();
        }
    }
    return max_area;
}
int main() {
	int t,n,j,max;
	scanf("%d",&t);
	while(t>0){
	    scanf("%d",&n);
	    int* arr=(int*)malloc(n*sizeof(int));
	    for(j=0;j<n;j++){
	        scanf("%d",&arr[j]);
	    }
	    max=max_rect_area(arr,n);
	    printf("%d\n",max);
	    t--;
	}
	return 0;
}

