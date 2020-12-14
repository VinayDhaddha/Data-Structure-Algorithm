    for(i=0;i<n;i++){
        area1=0;
        l=i-1;
        r=i+1;
        area1=arr[i];
        while((l>=0)&&(arr[l]>=arr[i])){
            area1+=arr[i];
            l--;
        }
        while((r<n)&&(arr[r]>=arr[i])){
            area1+=arr[i];
            r++;
        }
        area[i]=area1;
    }
    int max=0;
    for(i=0;i<n;i++){
        if(area[i]>max)
            max=area[i];
    }
    return max;
}
int main() {
	int t,n,i,max;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    int arr[n];
	    for(i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    max=max_rec_area(arr,n);
	    printf("%d\n",max);
	}
	return 0;
}







