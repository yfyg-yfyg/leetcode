class Solution {
    
    int ans = 0;
    private int combine(int n) {
       return n *(n -1) / 2;
    }
    
    public int numEquivDominoPairs(int[][] dominoes) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int[] e : dominoes) {
            int key = Math.min(e[0], e[1]) + Math.max(e[0], e[1]) * 10;
            map.merge(key, 1, (a , b) -> a + 1 );
        }
        
        map.forEach((k, v) -> {
           if (v > 1) 
               ans += combine(v);
        });
      
        
        return ans;
    }
}

