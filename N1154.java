class Solution {
    public int dayOfYear(String date) {
       int[][] daysInMonth = {
                         {0,
                          31, 
                          31+28,
                          31+28+31,
                          31+28+31+30,
                          31+28+31+30+31,
                          31+28+31+30+31+30,
                          31+28+31+30+31+30+31,
                          31+28+31+30+31+30+31+31,
                          31+28+31+30+31+30+31+31+30,
                          31+28+31+30+31+30+31+31+30+31,
                          31+28+31+30+31+30+31+31+30+31+30,
                          31+28+31+30+31+30+31+31+30+31+30+31
                          },
                          {
                          0,
                          31, 
                          31+29,
                          31+29+31,
                          31+29+31+30,
                          31+29+31+30+31,
                          31+29+31+30+31+30,
                          31+29+31+30+31+30+31,
                          31+29+31+30+31+30+31+31,
                          31+29+31+30+31+30+31+31+30,
                          31+29+31+30+31+30+31+31+30+31,
                          31+29+31+30+31+30+31+31+30+31+30,
                          31+29+31+30+31+30+31+31+30+31+30+31}
                         };
        
        String[] dateString = date.split("-"); 
        Integer[] dateInteger = new Integer[dateString.length]; 
        for (int i = 0; i < dateString.length; i ++) {
           dateInteger[i] = Integer.parseInt(dateString[i]); 
        }
        
        //Arrays.stream(date.split("-")).map(Integer::parseInt).collect(toList());
  
        int ans = 0;
        Boolean runYear = false;
        if (dateInteger[0] % 100 == 0) {
            if (dateInteger[0] % 400 == 0) {
                runYear = true;
            }
            else {
                runYear = false;
            }
        }
        else if (dateInteger[0] % 4 == 0) {
            runYear = true;
        }
        else {
            runYear = false;
        }
        
        if (runYear) {
            ans = daysInMonth[1][dateInteger[1] - 1] + dateInteger[2];
        }
        else {
            ans = daysInMonth[0][dateInteger[1] - 1] + dateInteger[2];
        }
       
       return ans; 
    }
}

