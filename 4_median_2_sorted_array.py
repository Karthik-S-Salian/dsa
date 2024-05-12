class Solution:
    def findMedianSortedArrays(self, l1: list[int], l2: list[int]) -> float:
        m = len(l1)
        n = len(l2)
        
        i=0
        j=0
        k=0
        r1 = 0
        r2 = 0

        last = (m+n)//2

        while i<=last and j<m and k<n:
            r2 = r1
            i+=1
            if l1[j]<l2[k]:
                r1 = l1[j]
                j+=1
            else:
                r1 = l2[k]
                k+=1
        
        while i<=last and j<m:
            r2 = r1
            r1 = l1[j]
            i+=1
            j+=1

        print(r1)

        while i<=last and k<n:
            r2 = r1
            r1 = l2[k]
            i+=1
            k+=1
        
        if (m+n)%2:
            return r1
        else:
            return (r1+r2)/2

