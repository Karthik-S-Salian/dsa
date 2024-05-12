#include <vector> 
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(char& c : s) {
            switch(c){
                case '{':
                case '[':
                case '(':
                    stack.push_back(c);
                    break;
                case '}':
                    if (stack.empty() || stack.back()!='{')
                        return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || stack.back()!='[')
                        return false;
                    stack.pop_back();
                    break;
                case ')':
                    if (stack.empty() || stack.back()!='(')
                        return false;
                    stack.pop_back();
                    break;
            }
        }
        if (stack.empty())
            return true;
        return false;
    }
};