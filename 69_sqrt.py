class Solution:
    def mySqrt(self, x: int) -> int:
        beg=1
        end = x//2+1

        if(x==1): return x

        while(beg<end):
            mid = (beg+end)//2

            pvs_sqr = (mid)*(mid)
            next_sqr = (mid+1)*(mid+1)

            if(pvs_sqr == x):
                return mid

            if(pvs_sqr<x):
                if(next_sqr>x):
                    return mid
                else:
                    beg = mid+1
                
            if(next_sqr>x):
                if(pvs_sqr<x):
                    return mid
                else:
                    end = mid
        
        return 0