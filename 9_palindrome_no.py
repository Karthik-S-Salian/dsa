class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        l=0
        z=x
        while(x):
            l=l*10+x%10
            x=x//10

        if(l==z):
            return True
        else:
            return False