class Solution {
    public int findMin(int[] nums) {
        int l = 0, u = nums.length - 1;
        
        if (nums[nums.length - 1] >= nums[0])
            return nums[0];

        while(l < u) {
            int m = l + ((u -l) >> 1);
            if (nums[m] >= nums[0]) {
                l = m + 1;
            }
            else if (nums[m] < nums[0]) {
                u = m ;
            }
        }
        
        return nums[u];
    }
}

