from math import ceil

class Solution(object):
    def minEatingSpeed(self, piles, h):
        l,r = 1, max(piles)
        res = r

        while(l<=r):
            time = 0
            k = l + (r-l)//2
            for pile in piles:
                time +=ceil(float(pile)/k)
            if(time<=h):
                res =k
                r = k-1
            else:
                l=k+1
        return res 