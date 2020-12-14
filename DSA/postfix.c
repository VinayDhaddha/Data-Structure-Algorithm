#include <stdio.h>
#include<string.h>
//#include<conio.h>
char arr[1000];
void reverse(){
    int size=sizeof(arr);
    //printf("----%d----",size);
    char rev[size];
    int i;
    for(i=0;i<=size;i++){
        if(arr[size-i]=='(')
            rev[i]=')';
        else if(arr[size-i]==')')
            rev[i]='(';
        else
            rev[i]=arr[size-i];
    }
    rev[i]='\0';
    strcpy(arr,rev);
    return ;
}
int main() {
	int t;
	scanf("%d\n",&t);
	gets(arr);
  fflush(stdlib);
	reverse();
	puts(arr);
	//postfix(arr);
	return 0;
}
