class Solution:
    def countBits(self, n: int) -> list[int]:
        l=[0,1]
        i=2
        offset =1

        while len(l)<=n:
            for k in range(1,offset):
                l.append(l[k]+1)
                if len(l)>n:
                    break

            offset*=2
            l.append(1)
        
        return l[:n+1]


    def counting_bits_best(self, n: int) -> list[int]:
        res = [0] * (n+1)
        for i in range(n+1):
            res[i] = res[i>>1] + (i&1)
        return res
        