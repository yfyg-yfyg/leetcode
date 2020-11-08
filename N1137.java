class Solution {
    public int tribonacci(int n) {
        if (n >= 3) {
            return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
        else if (n == 2 || n == 1) {
            return 1;
        }
        else {
            return 0;
        }
        
    }
}

