class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ans = curr = ""
        n = len(nums)
        def rec(idx, nums) :
            nonlocal ans, curr
            if idx == n :
                if curr not in nums : ans = curr
                return 
            if ans != "" : return 
            curr += '0'
            rec(idx + 1, nums)
            curr = curr[:-1]
            curr += '1'
            rec(idx + 1, nums)
            curr = curr[:-1]
        rec(0, nums)
        return ans