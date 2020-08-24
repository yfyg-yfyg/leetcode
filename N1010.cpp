class Solution {

      int combination(int n, int l ) {
          if (n == l || l == 0)
              return 1;
          return combination(n - 1, l - 1) + combination(n - 1, l);
      }
     
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int rest_array[60] = {0};

        for (int i = 0; i < time.size(); i ++) {
            rest_array[time[i] % 60 ] += 1;
        }

        int sum = 0;
        for (int i = 1; i < 30; i ++) {
            if (rest_array[i] && rest_array[60 - i])
                sum += rest_array[i] * rest_array[60 - i];
        } 

        if (rest_array[0] >= 2) {
           // sum += combination1(rest_array[0], 2);
           sum += rest_array[0] * (rest_array[0] - 1) / 2;
        }

        if (rest_array[30] >= 2) {
           // sum += combination1(rest_array[30], 2);
           sum += rest_array[30] * (rest_array[30] - 1) / 2;
        }
         
       return sum;
    }
};

