#include<stdio.h>
#include<math.h>
int index1=-1;
int flag=0;
int binary_search(int* arr,int l,int r,int num){
  if(l<=r){
    int mid=l+floor((r-l)/2);
    if((l==r)&&(flag==1)&&(arr[l]==num)){
      index1=l;
      return index1;
    }
    else if(arr[mid]==num){
      flag=1;
      index1=mid;
      return binary_search(arr,l,mid-1,num);
    }
    else if(arr[mid]>num)
      return binary_search(arr,l,mid-1,num);
    else if(arr[mid]<num)
      return binary_search(arr,mid+1,r,num);
  }
  else if(flag==1)
  	return index1;
  else 
  	return -1;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i,num;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    printf("enter number to find its first occurence:");
    scanf("%d",&num);
    index1=-1;
    flag=0;
    int index=binary_search(arr,0,n-1,num);
    if(index==-1){
      printf("\nNOT FOUND\n");
    }
    else
      printf("\n%d\n",index);
  }
  return 0;
}

