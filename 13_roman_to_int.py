# Online Python compiler (interpreter) to run Python online.
class Solution:
    def romanToInt(self, s: str) -> int:
        rt = {
            "0":0,
            "I"        :     1,
            "V"        :     5,
            "X"      :       10,
            "L"      :       50,
            "C"      :       100,
            "D"      :       500,
            "M"      :       1000
        }
        
        ans= 0
        s=s+"0"

        for i in range(len(s)-1):
            x= rt[s[i]]
            if(x<rt[s[i+1]]):
                x=-x
            ans = ans + x
        
        return ans
            