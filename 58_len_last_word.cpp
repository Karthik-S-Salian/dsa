#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 1;
        bool is_prvs_space = true;

        for(int i =0 ;i<10e4 ; i++){
            if(s[i]=='\0')
                return count;
            if(s[i]==' ')
                is_prvs_space = true;
            else{
                if(is_prvs_space){
                    is_prvs_space=false;
                    count=0;
                }
                count++;
            }
            
        }
        return count;     
    }
};