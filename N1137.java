class Solution {
    public int tribonacci(int n) {
        if (n == 2 || n == 1) {
            return 1;
        }
        else if (n == 0) {
            return 0;
        } 
        else {
            ArrayList<Integer>  series = new ArrayList<>();
            series.add(0);
            series.add(1);
            series.add(1);
            
            for (int i = 3; i <= n ; i ++) {
                series.add(series.get(i-1) + series.get(i-2) + series.get(i-3));
            }
            
            
            return series.get(series.size() - 1);
            
            
        }
       
        
    }
}
