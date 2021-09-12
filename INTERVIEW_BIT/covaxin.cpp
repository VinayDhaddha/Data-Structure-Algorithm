#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long long int AP(unsigned long long int x,unsigned long long int y,unsigned long long int i){
    return ((i+1)*(2*x+y*i))/2;    
}
unsigned long long int counting(unsigned long long int x,unsigned long long int a,unsigned long long int b,unsigned long long int c,unsigned long long int d){
    unsigned long long int f1=a,f2=c,count=0,max=0,i=0,j=0,sum1,sum2;
        // cout<<"yes2"<<endl;
        sum1=AP(a,b,i);
        sum2=AP(c,d,j);
        //  cout<<"yes3"<<endl;
        vector<int> v1,v2;
        while((sum1<=x)||(sum2<=x)){
            if(sum1<=x){
                v1.push_back(sum1);
                i++;
                sum1=AP(a,b,i);
            }
            if(sum2<=x){
                v2.push_back(sum2);
                j++;
                sum2=AP(c,d,j);
            }
        }
        //  cout<<"yes4"<<endl;
        if(i>max){
            max=i;
        }
        if(j>max){
            max=j;
        }
        if(i!=0)
            i--;
        if(j!=0)
            j--;
        // cout<<"yes5"<<endl;
        while(i>0){
            unsigned long long int temp=x-v1[i];
            auto low =lower_bound(v2.begin(), v2.end(), temp);
            unsigned long long int index=low-v2.begin();
            if(v2[index]!=temp){
                index--;
            }
            count=i+index+2;
            if(count>max){
                max=count;
            }
            if(i==0){
                break;
            }
            i--;
            // cout<<i<<endl;
        }
        // cout<<"yes"<<endl;
        return max;
}
int main() {
    unsigned long long int t,x,a,b,c,d,p,q,r,s,t1,m;
    scanf("%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",&t,&x,&a,&b,&c,&d,&p,&q,&r,&s,&t1,&m);
    while(t>0){
        // cout<<"yes1"<<endl;
        unsigned long long int count=counting(x,a,b,c,d);
        // cout<<"yes"<<endl;
        printf("%llu\n",count);
        t--;
        if(t==0){
            break;
        }
        a=((a+count*t1)%m)+p;
        b=((b+count*t1)%m) +q;
        c=((c+count*t1)%m) +r;
        d=((d+count*t1)%m)+s;
    }
    return 0;
}
/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long long int AP(unsigned long long int x,unsigned long long int y,unsigned long long int i){
    return ((i+1)*(2*x+y*i))/2;    
}
unsigned long long int counting(unsigned long long int x,unsigned long long int a,unsigned long long int b,unsigned long long int c,unsigned long long int d){
    unsigned long long int f1=a,f2=c,count=0,max=0,i=0,j=0,sum1,sum2;
        sum1=AP(a,b,i);
        sum2=AP(c,d,j);
        vector<int> v1,v2;
        while((sum1<=x)||(sum2<=x)){
            if(sum1<=x){
                v1.push_back(sum1);
                i++;
                sum1=AP(a,b,i);
            }
            if(sum2<=x){
                v2.push_back(sum2);
                j++;
                sum2=AP(c,d,j);
            }
        }
        i--;
        j--;
        while(i>=0){
            unsigned long long int temp=x-v1[i];
            auto low =lower_bound(v2.begin(), v2.end(), temp);
            unsigned long long int index=low-v2.begin();
            if(v2[index]!=temp){
                index--;
            }
            count=i+index+2;
            if(count>max){
                max=count;
            }
            i--;
        }
        return max;
}
int main() {
    unsigned long long int t,x,a,b,c,d,p,q,r,s,t1,m;
    scanf("%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",&t,&x,&a,&b,&c,&d,&p,&q,&r,&s,&t1,&m);
    while(t>0){
        unsigned long long int count=counting(x,a,b,c,d);
        // cout<<"yes"<<endl;
        printf("%llu\n",count);
        t--;
        if(t==0){
            break;
        }
        a=((a+count*t1)%m)+p;
        b=((b+count*t1)%m) +q;
        c=((c+count*t1)%m) +r;
        d=((d+count*t1)%m)+s;
    }
    return 0;
}*/







// CPP program to count max heaps with n distinct keys
#include <iostream>
using namespace std;
 
#define MAXN 105 // maximum value of n here
 
// dp[i] = number of max heaps for i distinct integers
int dp[MAXN];
 
// nck[i][j] = number of ways to choose j elements
//             form i elements, no order */
int nck[MAXN][MAXN];
 
// log2[i] = floor of logarithm of base 2 of i
int log2[MAXN];
 
// to calculate nCk
int choose(int n, int k)
{
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
 
    if (nck[n][k] != -1)
        return nck[n][k];
 
    int answer = choose(n - 1, k - 1) + choose(n - 1, k);
    nck[n][k] = answer;
    return answer;
}
 
// calculate l for give value of n
int getLeft(int n)
{
    if (n == 1)
        return 0;
 
    int h = log2[n];
 
    // max number of elements that can be present in the
    // hth level of any heap
    int numh = (1 << h); //(2 ^ h)
 
    // number of elements that are actually present in
    // last level(hth level)
    // (2^h - 1)
    int last = n - ((1 << h) - 1);
 
    // if more than half-filled
    if (last >= (numh / 2))
        return (1 << h) - 1; // (2^h) - 1
    else
        return (1 << h) - 1 - ((numh / 2) - last);
}
 
// find maximum number of heaps for n
int numberOfHeaps(int n)
{
    if (n <= 1)
        return 1;
 
    if (dp[n] != -1)
        return dp[n];
 
    int left = getLeft(n);
    int ans = (choose(n - 1, left) * numberOfHeaps(left)) *
                             (numberOfHeaps(n - 1 - left));
    dp[n] = ans;
    return ans;
}
 
// function to initialize arrays
int solve(int n)
{
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
 
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            nck[i][j] = -1;
 
    int currLog2 = -1;
    int currPower2 = 1;
 
    // for each power of two find logarithm
    for (int i = 1; i <= n; i++) {
        if (currPower2 == i) {
            currLog2++;
            currPower2 *= 2;
        }
        log2[i] = currLog2;
    }
 
    return numberOfHeaps(n);
}
 
// driver function
int main()
{
    int n = 10;
    cout << solve(n) << endl;
    return 0;
}


