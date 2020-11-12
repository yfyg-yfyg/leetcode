class Solution {
    public int findMin(int[] nums) {
        int min = nums[0];
        
        for (int i = 1; i < nums.length; i ++) {
            if (nums[i] - nums[i-1] < 0) {
                return nums[i];
            }
            
        }
        
        return min;
    }
}

