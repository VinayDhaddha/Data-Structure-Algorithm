// https://www.interviewbit.com/problems/palindrome-string/
// time complexity = O(N)
// Space complexity= O(1)
int Solution::isPalindrome(string A) {
    int i=0,j=A.size()-1,ascii,flag=1;
    while((i<=j)){
        while((j>=0)&&(((int)A[j]<48)||(((int)A[j]>57)&&((int)A[j]<65))||(((int)A[j]>90)&&((int)A[j]<97))||((int)A[j]>122))){
            j--; // skipping character other than alphanumeric
        }
        while(((i<=(A.size()-1)))&&(((int)A[i]<48)||(((int)A[i]>57)&&((int)A[i]<65))||(((int)A[i]>90)&&((int)A[i]<97))||((int)A[i]>122))){
            i++;  // skipping character other than alphanumeric
        }
        // printf("i=%d  j=%d\n",i,j);
        if(j<=i){    // till end no problem so return 1
            
            return 1; // result found return 1
        }
        if((45<=(int)A[i])&&((int)A[i]<=57)){  // checking  1<A[i]<9 or not
            if((int)A[i]==(int)A[j]){  // comparing A[i]==A[j]
                j--;
                i++;
            }
            else{
                return 0;  // not match return 0
                // printf("yess1");
            }
        }
        else if((65<=(int)A[i])&&((int)A[i]<=90)){ // checking  'A'<A[i]<'Z' or not
            if((65<=(int)A[j])&&((int)A[j]<=90)){ // checking  'A'<A[j]<'Z' or not
                if((int)A[j]==(int)A[i]){       // comparing A[i]==A[j]
                    j--;
                    i++;
                }
                else{
                    // printf("yess2");
                    return 0;                       // not match return 0
                }
            }
            else{
                ascii=65+(int)A[j]-97;  // 'a'<A[j]<'z' so storing its value to campare with  its upper case 
                if(ascii==(int)A[i]){
                    // printf("yess3   %c-%d  %c-%d\n",A[i],i,A[j],j);
                    j--;
                    i++;
                }
                else{
                    // printf("yess3");
                    return 0;                 // not match return 0
                }
            }
        }
        else if((97<=(int)A[i])&&((int)A[i]<=122)){ // checking  'a'<A[i]<'z' or not
            if((97<=(int)A[j])&&((int)A[j]<=122)){  // checking  'a'<A[j]<'z' or not
                if((int)A[j]==(int)A[i]){
                //   /  printf("yess4   %c-%d  %c-%d\n",A[i],i,A[j],j);
                    j--;
                    i++;
                }
                else{
                    // printf("yess4   %d  %d",ascii,((int)A[i]));
                    return 0;                    // not match return 0
                }                
            }
            else{
                ascii=97+(int)A[j]-65; // 'A'<A[j]<'Z' so storing its value to campare with  its upper case 
                if(ascii==(int)A[i]){
                    // printf("yess5   %c-%d  %c-%d",A[i],i,A[j]);
                    j--;
                    i++;
                }
                else{
                    // printf("yess5   %c  %c",A[i],A[j]);
                    return 0;            // not match return 0
                }
            }
        }
        else{
            i++;
        }
    }
}


// look on complete solution

// bool alphaNumeric(char ch)
// {
//     if( (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int Solution::isPalindrome(string A) 
// {
//     bool palin = true;
//     int start = 0;
//     int end = A.size();
    
//     while(start < end)
//     {
//         while( start < end && !alphaNumeric(A[start]))
//         {
//             start++;
//         }
        
//         while( start < end && !alphaNumeric(A[end]))
//         {
//             end--;
//         }
        
//         if(start < end)
//         {
//             char ch1 = A[start];
//             char ch2 = A[end];
            
//             if(ch1 >= 'A' && ch1 <= 'Z')
//             {
//                 ch1 = ch1 + ('a' - 'A');
//             }

//             if(ch2 >= 'A' && ch2 <= 'Z')
//             {
//                 ch2 = ch2 + ('a' - 'A');
//             }
            
//             if(ch1 != ch2)
//             {
//                 palin = false;
//                 break;
//             }
//             start++;
//             end--;

//         }
//     }

//     return palin;
// }


