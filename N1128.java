class Solution {
   
    private int combine(int n) {
       return n *(n -1) / 2;
    }
    
    public int numEquivDominoPairs(int[][] dominoes) {
        int ans = 0;
        int[]  map = new int[100];
        
        for(int[] e : dominoes) {
            ans += map[Math.min(e[0], e[1]) + Math.max(e[0], e[1]) * 10] ++;
        }
        
        return ans;
    }
}
