class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if (len(nums) == 1):
            return 1
        
        slow, fast = 0, 0;
        
        while (fast < len(nums)):
            while (nums[fast] == nums[slow]):
                fast += 1
                if (fast == len(nums)):
                    return slow + 1;
            
            slow += 1
            nums[slow] = nums[fast]
            fast += 1
            
        return slow + 1
        