class Solution:

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        state={}
        for word in strs:
            c= "".join(sorted(list(word)))
            state[c] = state.get(c,[])
            state[c].append(word)
        return state.values()