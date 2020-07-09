class Solution {
public:
    int binaryGap(int N) {
        int max = 0;
        int count = 0;
        bool find_first = false; 

        while (N > 0) {
            if (N & 0x01) {
                if (!find_first) {
                    find_first = true;
                }
                else  {
                    count ++;
                    if (count > max) {
                        max = count;
                    }
                    count = 0;
                }
            }
            else {
                if (find_first)
                  count ++;
            }

            N = N >> 1;
        }

        return max;
    }
};
