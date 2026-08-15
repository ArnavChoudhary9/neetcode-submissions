class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        _map = {}
        for i, num in enumerate(nums):
            if (j := (target - num)) in _map: return [_map[j], i]
            _map[num] = i