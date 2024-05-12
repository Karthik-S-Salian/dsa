def factorial(x,y=1):
    fac = 1
    for i in range(y+1,x+1):
        fac*=i
    return fac

class Solution:
    def climbStairs(self, n):
        count = 0
        for x in range(n%2,n+1,2):
            y = (n-x)//2
            if(x>y):
                count+= factorial(x+y,x)//factorial(y)
            else:
                count+= factorial(x+y,y)//factorial(x)

        return count