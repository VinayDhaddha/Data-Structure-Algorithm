// https://www.interviewbit.com/problems/implement-strstr/
// Time complexity=O(N)
//Space complexity =O(1)


// test case :i/p A= abcdefghivinay   B=vinay
//     o/p =8
int Solution::strStr(const string A, const string B) {
    int i=0,j=0,index=-1;
    if((A.size()==0)||(B.size()==0))// if any of string of Aor B is NULL return 0
        return 0;
    while((i<A.size())&&(j<B.size())){// if both of A or B are not NULL then loop to traverse A string
        if(A[i]==B[j]){ // if A[i]== first character of string B which we finding
            index=i;            //index stores index value of B[0] in A which we use later if this was our req. ans 
            while((i<A.size())&&(j<B.size())&&(A[i]==B[j])){ // checking wheather it was the right string or not
                i++;
                j++;
                
            }
            if(j==B.size()){ // j==B.size() only when we got ou ans
                return index;  // so returning index of A from where string starts of B
            }
            else{   // it was not the required string
                j=0;            // iterator of B also start pointing to index=0
                i=index+1;      // i start from (index+1) because may be our soln starting character left behind because of previous while loop
                index=-1;       // index=-1 to refind the string B
            }
        }
        else{
            i++;    // if A[i]!=B[j] then incementing in the string A iterator
        }
    }
    return index; // return index if we got the string otherwise return -1;
}

