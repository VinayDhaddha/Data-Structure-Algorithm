// https://www.interviewbit.com/problems/minimum-parantheses/
// time complexity: O(N)
// Space complexity: O(1)
int Solution::solve(string A) {
    int open=0,i=0,count=0;
    for(i=0;A[i]!='\0';i++){// loop till string end
        if(A[i]=='(') // if open bracket
            open++;    // open stores no. of open brackets
        else 
            open--;  // if A[i]==')' open-- > 0  implies we get open and close bracket pair 
        if(open<0){  // if open-- < 0 implies '('(open bracket) before i index with it we can pair this
            count++;    // count count's no. of close bracket not get maches with open bracket
            open=0;     // open = 0  helps to restart counting of '(' and ')' brackets
        }
    }
    return count+abs(open);  // returning sum of unmatched closing and open bracket  
}

