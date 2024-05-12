class Solution:
    def isValid(self, s: str) -> bool:
        mp = {
            "(":1,
            ")":-1,
            "{":2,
            "}":-2,
            "[":3,
            "]":-3
        }

        stack = []
        for char in s:
            val=mp[char]
            if val<0:
                if(len(stack)==0 or stack.pop() != -val):
                    return False
            else:
                stack.append(val)
                    
        if len(stack):
            return False
        return True