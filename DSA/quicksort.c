#include<stdio.h>
int a[100];
int roughsort(int* a,int f,int l){
	int i,t;
	int curserON=f;
	for(i=f;i<l;i++){
		if(a[i]<=a[l]){
			t=a[curserON];
			a[curserON]=a[i];
			a[i]=t;
			curserON++;
		}
	}
	t=a[curserON];
	a[curserON]=a[l];
	a[l]=t;
	return curserON;
}
void quicksort(int* a,int f,int l){
	int pindex=0;
	if(f<l){
		printf("--->f=%d,l=%d\n",f,l);
		pindex=roughsort(a,f,l);
		quicksort(a,f,pindex-1);
		quicksort(a,pindex+1,l);
		
	}
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("----. first %d    ",n-1);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("  %d ",a[i]);
	}
	return 0;
}

