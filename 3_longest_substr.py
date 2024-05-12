class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        state = dict()
        start =0
        max_len = 0

        for i,char in enumerate(s):
            if char in state and state[char]>=start:
                start = state[char]+1
            state[char] = i
            max_len = max(max_len,i-start+1)
    
        return max_len