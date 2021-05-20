// https://www.interviewbit.com/problems/amazing-subarrays/
// Time complexity: O(N)
// Space complexity: O(1)
int Solution::solve(string A) {
    int i=0,count=0,l=0,mod=10003;
    for(i=0;A[i]!='\0';i++){ // loop for finding length of  string A
        l++;
    }
    for(i=0;A[i]!='\0';i++){// loop for checking whether A[i]==vowel alphabet or not 
        if((A[i]=='A')||(A[i]=='E')||(A[i]=='I')||(A[i]=='O')||(A[i]=='U')||(A[i]=='a')||(A[i]=='e')||(A[i]=='i')||(A[i]=='o')||(A[i]=='u'))
            count+=l-i;     //if we find a vowel then sizeof_string - index of vowel will give us no. of possible subaaray starting with vowel 
    }
    return count%mod;  // taking modulus as per given in question 
}

