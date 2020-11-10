class Solution {
    public int dayOfYear(String date) {
       int[] daysInMonth = {
                          0,
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
                          };
                          
        String[] dateString = date.split("-"); 
        Integer[] dateInteger = new Integer[dateString.length]; 
        for (int i = 0; i < dateString.length; i ++) {
           dateInteger[i] = Integer.parseInt(dateString[i]); 
        }
        
        if (dateInteger[0] % 4 == 0 && dateInteger[0] % 100 != 0 ||
            dateInteger[0] % 400 == 0) {
            int ans = daysInMonth[dateInteger[1] - 1] + dateInteger[2];
            return  dateInteger[1] > 2 ? ans + 1 : ans;
        }
        else {
            return daysInMonth[dateInteger[1] - 1] + dateInteger[2];
        }
    }
}


