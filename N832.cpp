class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.size() == 0 || A[0].size() == 0)
            return A; 

        int height = A.size(); 
        int width = A[0].size();
        int width_half = width / 2 - 1;
        bool width_odd = (width % 2 != 0);
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j <= width_half ; j ++) {
                if (A[i][j] == A[i][width -1 - j]) {
                    A[i][j] = A[i][width - 1 -j] = (A[i][j] == 0 ? 1 : 0);
                }
             }
             if (width_odd) {
                A[i][width_half + 1] = A[i][width_half + 1] == 1 ? 0 : 1;
             }
        }

        return A;
    }
};
