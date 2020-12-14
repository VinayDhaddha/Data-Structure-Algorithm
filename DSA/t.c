#include<stdio.h>
int main(){
int x=1,y=1,z=1,f;
f=++x||++y&&++z;
printf("%d %d %d %d",f,x,y,z);
return 0;
}
