// https://www.interviewbit.com/problems/length-of-last-word/
// time complexity=O(n)
// space complexity=O(1)
int Solution::lengthOfLastWord(const string A) {
    int l=0,i=0; // l= lenght , i=iterator
    int start=-1; // showing index of last word starting alphabet
    while(A[i]!='\0'){// iterating till string end
        if(A[i]==' '){ // if A[i]=' ' i.e spaces after which next word start or string end
           while((A[i]!='\0')&&(A[i]==' ')) // loop while next word start or string ends
                i++;
            if(A[i]=='\0')// if string ends break out of for loop 
                break;
            else{       // else start of next word it may or may not be last 
                start=i;
            }
        }
        if(start==-1) // first time initializing start 
            start=i;
        i++;   // increment in iterator
    }
    if(start==-1)  // if start ==-1 implies empty string shows 
        l=0;        // last word length =0 
    else{          // finding length of last word from string 
        while((A[start]!='\0')&&(A[start]!=' ')){
            l++;
            start++;
        }
    }
    return l;   // return length of last word
}

