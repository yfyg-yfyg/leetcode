class Solution {
    
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>>  positions;
        if (S.length() < 3)
         return positions;
        
        for (int i = 0; i < S.length() - 2; ) {
                int start = i; 
                int j = i + 1;
                while (S[start] == S[j] && j < S.length()) {
                    j ++;
                }
                if (j - start >= 3) {
                    vector<int> position;
                    position.push_back(start);
                    position.push_back(j - 1);
                    positions.push_back(position);
                }
                i = j; 
        }

        return positions;
    }
};
