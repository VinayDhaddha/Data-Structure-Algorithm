// Time Complexity = O(n^2)
// Space complexity= O(n)
int Solution::threeSumClosest(vector<int> &A, int B) {
    int i=0,start,end,diff=INT_MAX,min1;
    long long int temp;
    if(A.size()<3)  // if less 3 int present in vector not able to perform task then return 1000000000
        return 1000000000;
    sort(A.begin(),A.end());//// sorting in vector helps to change  iterator values 
    for(i=0;i<(A.size()-2);i++){// loop till A.size()-2 index .'i' is rightmost iterator out of 3 thats why till A.size()-2 
    // once we checked for A[i] int then no need to include int present at index from index 0 to i-1;
        if(A[i]==A[i-1]) {   // already we checked for A[i] element so no need
            continue;
        }
        start=i+1;//just next int from i 
        end=A.size()-1; // last of i.e largest int of vector
        while(end>start){//  keeping fix 'i' changing end and start  iterator
            long long int sum=(long long int)A[i]+(long long int)A[start]+(long long int)A[end];
            // important to use long long int at each 
            temp=abs(sum-B);// give absolute difference to find (nearest )least value of temp means sum is much nearer to B
            if(temp<diff){// storing minimum absolute difference(temp) sum into min1 and temp in diff for further use
                diff=temp;
                min1=sum;
            }
            if(sum>B){  // if (sum>B) end-- helps to decrease sum value to reach closure to sum
                end--;
            }
            else
                start++;// if (sum>B) start helps to increase sum value to reach closure to sum
        }
    }
    return min1;// return minimum absolute difference sum 
}

