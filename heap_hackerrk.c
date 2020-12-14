#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int i=1;
void swap(long* arr,int i1,int i2){
    int t=arr[i1];
    arr[i1]=arr[i2];
    arr[i2]=t;
}
void minheapify(long* arr,int j){
    int s1=j*2;
    int s2=j*2+1;
    int min;
    if((s1<i)&&(s2<i)){
        if((arr[s1]<arr[j])||(arr[s2]<arr[j])){
            if(arr[s1]<=arr[s2])
                min=s1;
            else
                min=s2;
            swap(arr,j,min);
            minheapify(arr,min);
        }
    }
    else if(s1<i){
        if((arr[s1]<arr[j])){
            swap(arr,j,s1);
            minheapify(arr,s1);
        }
    }

}
void build_min(long* arr,int inp){
    int j,i1,i2;
    arr[i]=inp;
    int start=floor(i/2);
    i++;
    for(j=i-1;j>1;j--){
        int index=floor(j/2);
        if(arr[j]<arr[index]){
            swap(arr,index,j);
            minheapify(arr,j);
        }
    }
//    for(j=1;j<i;j++){
//         printf("\narray ");
//         printf("%d----%ld\n",j,arr[j]);
//     }
}
void delete_node(long* arr,long del){
    int j=1,index;

    for(j=1;j<i;j++){
        if(arr[j]==del){
            index=j;
            break;
        }
    }
    swap(arr,index,i-1);
    i--;
    minheapify(arr,index);
    int start=floor(i/2);
    for(j=index;j>1;j--){
        int index1=floor(j/2);
        if(arr[j]<arr[index1]){
            swap(arr,index1,j);
            minheapify(arr,j);
        }
    }
    // printf("\n-%ld-----------------delete------------------%ld\n",arr[index],del);
    // for(j=1;j<i;j++){
    // printf("\narray ");
    // printf("%d----%ld\n",j,arr[j]);
    // }
}
int main() {

    long arr[100001],inp,del;
    int q,indx=0;
    scanf("%d",&q);
    while(q--){
        int opr;
        scanf("%d",&opr);
        switch(opr){
            case 1://printf("INSERT\n");
                    scanf("%ld",&inp);
                    build_min(arr,inp);
                    break;
            case 2://printf("delete\n");
                    scanf("%ld",&del);
                   delete_node(arr,del);
                   break;
            case 3: //printf("min- value\n");
                    printf("%ld\n",arr[1]);
                    break;
            default:printf("INVALID INPUT\n");
        }
    }
    return 0;
}
