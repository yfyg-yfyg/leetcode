class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
       if (A.size() == 0 || A[0].size() == 0)
          return A;
        else {
            int height = A.size();
            int width = A[0].size();

            vector<vector<int>>  B(width, vector<int>(height));
            for (int i = 0; i < height; i ++) {
                for (int j = 0; j < width; j ++) {
                    B[j][i] = A[i][j];
                }
            }

            return B;
        }
        




    }
};

