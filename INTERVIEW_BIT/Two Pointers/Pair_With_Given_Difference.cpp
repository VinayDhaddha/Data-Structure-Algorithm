//  	https://www.interviewbit.com/problems/pair-with-given-difference/
// Time complexity = O(2n)=O(n)
//  Space complexity=O(n)=constant
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end()); // sorting in vector helps to change  iterator values by (A[j]-A[i])>=<B
    int i,j;// initializing iterator
    i=0,j=1;// moving in one direction iterator helped alot otherwise for -ve val of B if i=0, j=A.size()-1. A[j]-A[i]  is always >=0 so no always wrong o/p 
    for(;(i<A.size())&&(j<A.size());){// loop
        if((i!=j)&&((A[j]-A[i])==B)){// for 2 different values of vector difference be =B
             printf("%d %d ",i,j);
            return 1;  // 2 integer diff =B (founded)
        }
        else{
            if((A[j]-A[i])>B){// if greater the difference increment in 'i' to decrease overall value and vice-versa
                i++;
                // if(i==j)    // error if we  uses it then always A[j]>=A[i]
                //     j++;
            }
            else{
                j++;
            }
        }
    }
    printf("%d %d ",i,j);
    return 0;// not founded
}

