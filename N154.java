class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[left] > nums[left + 1]) {
                return nums[left + 1];
            }
            
            if (left != 0 && nums[left] < nums[left -1]) {
                return nums[left];
            }
            
            if (nums[mid] == nums[0]) {
                left ++;
            }
            else if (nums[mid] > nums[0]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[0]) {
                right = mid;
            }
        }

        return  Math.min(nums[right], nums[0]);
    }
}

