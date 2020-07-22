class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;

        int len = S.length();
        int left = 0, right = len;

        for (char s : S) {
            if (s == 'I') {
                ans.push_back(left ++);
            }
            else {
                ans.push_back(right --);
            }
        }

        ans.push_back(left);

        return ans;
    }
};

