class Solution:
    def countAndSay(self, n: int) -> str:
        r= ["1"]
        for j in range(2,n+1):
            temp = [str(1),r[0]]
            for i,letter in enumerate(r[1:],start=1):
                if temp[len(temp)-1]==letter:
                    temp[len(temp)-2] =str(int(temp[len(temp)-2])+1)
                else:
                    temp.extend([str(1),letter]) 
            r = temp
        return "".join(r)