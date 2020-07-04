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


class Solution {
  private:
    int removeBackspace(string S, int pos) {
        int sharp_count = 1;
        pos --;
        while ( sharp_count >=1 && pos >= 0 ) {
            if (S[pos--] == '#') {
                sharp_count ++;
            }
            else {
                sharp_count --;
            }
        }

        return pos;
    }

  public:
    bool backspaceCompare(string S, string T) {
       int i = S.length() - 1;
       int j = T.length() - 1;

       while(true) {
           while (i >=0 && j >= 0 &&
                  S[i] != '#' && T[j] != '#' && S[i] == T[j]) {
               i --;
               j --;
           }

           if (i >= 0 && S[i] == '#') {
               i = removeBackspace(S, i);
           }
           cout << i << endl;

           if (j >= 0 && T[j] == '#') {
               j = removeBackspace(T,j);
           }
           cout << j << endl << endl;
 
           if (i < 0 && j < 0 ) {
               return true;
           }
           if (i >= 0 && S[i] != '#' && j < 0 ||
               j >= 0 && T[j] != '#' && i < 0)  {
                   return false;
               }

           else if (i >=0 && S[i] != '#' && j >=0 && T[j] != '#' && S[i] != T[j]) {
               return false;
           } 
        }
      
       return false;
    }
};
