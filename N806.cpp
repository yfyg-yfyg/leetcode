class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        
        int sum = 0;
        int line = 0;
        for (int i = 0; i < S.length(); ) {
            if (sum + widths[S[i] - 'a'] == 100) {
                line ++;
                sum = 0;
                i ++;
            }
            else if (sum + widths[S[i] - 'a'] > 100) {
                line ++;
                sum = 0;
            }
            else {
                sum += widths[S[i] - 'a'];
                i ++;
            }
        }

        if (sum > 0)
            line ++;

        return {line, sum};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {

        int sum = 0;
        int line = 1;
        for (int i = 0; i < S.length(); ) {
            int width = widths[S[i] - 'a'];
            if (sum + width > 100) {
                line ++;
                sum = 0;
            }
            else {
                sum += width;
                i ++;
            }
        }


        return {line, sum};
    }
};

