
class Solution {
    public int tribonacci(int n) {

        if (n == 2 || n == 1) {
            return 1;
        }
        else if (n == 0) {
            return 0;
        }
        else {

            int[] series = new int[3];
            series[0] = 0;
            series[1] = 1;
            series[2] = 1;

            for (int i = 3; i <= n ; i ++) {
                series[i % 3] = series[0] + series[1] + series[2];
            }


            return series[n % 3];


        }


    }
}
