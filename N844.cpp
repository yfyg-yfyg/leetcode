/*
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

*/


class Solution {
    private:
     vector<char> removeBackChar(const string &S) {
        vector<char> s;
        for (int i = 0; i < S.length(); i ++) {
        if (S[i] != '#') {
                s.push_back(S[i]);
        }
        else {
                 if (s.size()) {
                    s.pop_back();
                }
            }
        }
        return s;
    }

public:
    bool backspaceCompare(string S, string T) {
        vector<char> s = removeBackChar(S);
        vector<char> t = removeBackChar(T);

        if (s.size() == t.size()) {
            for (unsigned int i = 0; i < s.size(); i ++) {
                if (s[i] != t[i])
                    return false;
            }
            return true;
        }
        return false;
    }
};
