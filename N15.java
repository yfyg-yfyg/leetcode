class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        HashSet<List<Integer>> ans = new HashSet<>();
        for (int i = 0; i < nums.length - 2; i ++) {
            for (int j = i + 1; j < nums.length - 1; j ++) {
                int loc = Arrays.binarySearch(nums, j + 1, nums.length, -(nums[i] + nums[j]));
                if (loc >= 0) {
                    ArrayList<Integer> e = new ArrayList<>(3);
                    e.add(nums[i]);
                    e.add(nums[j]);
                    e.add(nums[loc]);
                    ans.add(e);
                }
            }
        }
        
       return ans.stream().collect(Collectors.toList());

    }
}

