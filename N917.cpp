class Solution {
    private:
    bool isLetter(char s) {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
            return true;
        }
        else 
            return false;
    }
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.length() -1;
        while (i < j) {
            while(!isLetter(S[i]) && (i < S.length() - 1)) {
                i ++;
            }
             
            while(!isLetter(S[j]) && j > 0) {
                j --;
            }
                 
            if (i < j) {
                char tmp = S[j];
                S[j] = S[i];
                S[i] = tmp;
                i ++;
                j --;
            }
        }

        return S;
    }
};

