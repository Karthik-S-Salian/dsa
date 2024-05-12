#include<vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
{
        auto prefix = -1;

        for(auto letter = 0; letter < strs[0].length(); ++letter)
        {
            for(auto size  = 0; size < strs.size() - 1; ++size)
            {
                if(strs[size][letter] != strs[size + 1][letter])
                {
                    prefix = letter;
                    break;
                }
            }

            if(prefix != -1)
            {
                break;
            }
        }

        return strs[0].substr(0, prefix);
    }
};