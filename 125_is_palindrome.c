#include<stdbool.h>

bool isPalindrome(char* s) {
    int j=0;

    for(int i=0;s[i]!='\0';i++){
        if('A'<=s[i] && s[i]<='Z'){
            s[j]=s[i]+32;
            j++;
        }   
        else if('a'<=s[i] && s[i]<='z'){
            s[j]=s[i];
            j++;
        }else if('0'<=s[i] && s[i]<='9'){
            s[j]=s[i];
            j++;
        }
    }

    for(int i=0;i<j/2;i++){
        if(s[i]!=s[j-i-1])
            return 0;
    }
    return 1;
}