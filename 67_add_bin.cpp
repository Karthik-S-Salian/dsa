#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    char carry = '0';
    string ans="";
    int m = a.length()-1,n = b.length()-1;

    for(;m>=0 || n>=0;m--,n--)
    {
        
        char x='0',y='0';
        if(n>=0)
            y=b[n];
        if(m>=0)
            x=a[m];

        ans = char(x^y^carry)+ans;
        carry = (x&y)|(((x^y)+48)&carry);
         
    }
    if(carry=='1')
        ans = carry+ans;
    return ans;
    }};