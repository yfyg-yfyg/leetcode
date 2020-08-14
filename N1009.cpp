class Solution {
public:
    int bitwiseComplement(int N) {

        if (N == 0)
            return 1;

        int M = N;
        int count = 0;
        while(N != 0) {
            N = N >> 1;
            count ++;
        }

        return ~M & (1 << count) - 1;
     }
};
