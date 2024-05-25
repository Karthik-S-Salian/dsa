class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        s = []

        for op in tokens:
            if op=='/':
                i1 = s.pop()
                s.append(int(s.pop()/i1))
            elif op=='*':
                s.append(s.pop()*s.pop())
            elif op=='+':
                s.append(s.pop()+s.pop())
            elif op=='-':
                i1 = s.pop()
                s.append(s.pop()-i1)
            else:
                s.append(int(op))

        return s[0]