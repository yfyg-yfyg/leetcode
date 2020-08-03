class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> ans;

        int hour_high, hour_low, minute_high, minute_low;

        int max_distance = -1;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                if (j == i )
                    continue;
                for (int k = 0; k < 4; k ++) {
                    if ( k == i || k == j)
                        continue;
                    for (int l = 0;  l < 4; l ++) {
                        if ( l == k || l == j || l == i )
                            continue;
                        int hour = A[i] * 10 + A[j]; 
                        int minute = A[k] * 10 + A[l];
                        if (hour >= 0 && hour < 24 &&  minute >=0 && minute < 60) {
                            if (hour * 60 + minute > max_distance) {
                                max_distance = hour * 60 + minute;
                                hour_high = A[i];
                                hour_low = A[j];
                                minute_high = A[k];
                                minute_low = A[l];
                            }

                        }
                    }
                }
            }
        }

         if (max_distance ==  -1) 
            return "";
        else 
            return to_string(hour_high) + to_string(hour_low) + ":" + 
                   to_string(minute_high) + to_string(minute_low);
        
    }
};

