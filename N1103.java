class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];

        int offer_candies = 1;
        int left_candies = candies;

        int count = 0;
        while(left_candies > offer_candies) {
            ans[count++ % num_people] += offer_candies;
            left_candies -= offer_candies;
            offer_candies ++;
        }

        ans[count % num_people] += left_candies;

        return ans;
    }
}

