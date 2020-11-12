/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, u = n;
        int ans = -1;
        while (l <= u) {
            int m = l + ((u - l) >> 1);
            int sw = guess(m);
            switch (sw) {
                case 0:
                    return  m;
                case -1:
                    u = m - 1;
                    break;
                case 1:
                    l = m + 1;
                    break;
            }
        }
        
        return -1;
    }
}

