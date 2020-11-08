class Solution {
    
    private int combine(int n) {
       return n *(n -1) / 2;
    }
    
    public int numEquivDominoPairs(int[][] dominoes) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        int ans = 0;
        for(int[] e : dominoes) {
            int key = Math.min(e[0], e[1]) + Math.max(e[0], e[1]) * 10;
            ans += map.merge(key, 0, (a , b) -> a + 1 );
        }
      
        return ans;
    }
}
