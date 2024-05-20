class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        final =0
        for n1 in num1:
            res = 0
            for n2 in num2:
                res = res*10 + int(n1)*int(n2)
            final=final*10 + res

        return str(final)