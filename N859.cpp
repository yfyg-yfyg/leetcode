class Solution {
    
public:
    bool buddyStrings(string A, string B) {
       if (A.size() != B.size()) 
         return false;
        
        set<char>  sets;
        vector<char> a, b;
        bool has_duplicate_chars =false;
        
        int count = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (A[i] != B[i]) {
                a.push_back(A[i]);
                b.push_back(B[i]);
                continue;
            }

            if (!has_duplicate_chars) {
                if (sets.count(A[i]) == 0) {
                    sets.insert(A[i]);
                }
                else {
                    has_duplicate_chars = true;
                }
            }
        }

        if (a.size() == 0 && has_duplicate_chars)
            return true;
        
        if (a.size() != 2 || a[0] != b[1] || a[1] != b[0])
            return false;

        return true; 
    }
};

