class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        sd = {}
        td = {}

        for i, j in zip(s, t):
            if i in sd: sd[i] += 1
            else: sd[i] = 1

            if j in td: td[j] += 1
            else: td[j] = 1

        return sd == td
