// https://www.interviewbit.com/problems/remove-consecutive-characters/
// time complexity=O(N)
// Space complexity=O(N)
string Solution::solve(string A, int B) {
int n =A.size();// size of string A
string s = "";// string in which we store our ans
int i=0,j=0;
while(i<n)// iterator i from 0 to A.size()
{
    string temp = ""; // temparay strin helps to store similar continuos character untill we find that there count =B 
    int j=i;
    while(j<n && A[i]==A[j])// iterates till char is same 
    {
        temp+=A[j]; // storing in temp string (same continuous character )
        j++;
    }
    if(temp.size()!=B)  // if temp.size()== B no need to store these continuous character or vice versa 
        s += temp; // appending when temp.size()!=B  and storing in string s  (required ans)
    i=j;
}
return s;  // returning string with required ans
}
