class Solution {
    public int mySqrt(int x) {
        long l = 1, u = x;
        while (l <= u) {
            long m = l + ((u - l) >> 1);
            if (m * m == x)
                return (int)m;
            else if (m * m < x) {
                l = m + 1;
            }
            else {
                u = m - 1;
            }
        }
        
        return (int)u;
    }
}

