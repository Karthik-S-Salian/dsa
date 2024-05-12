class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        m,n = len(haystack),len(needle)

        
        # i=0
        # while(i<m-n+1):
        #     for c in needle:
        #         if(c != haystack[i]):
        #             break
        #         i+=1
        #     else:
        #         return i-n
        #     i+=1
        # return -1

        for i in range(m-n+1):
            if(needle == haystack[i:i+n]):
                return i
        return -1
