class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;

        int height = grid.size();
        int width = grid[0].size();
        if (height < 3 || width < 3 ) 
            return 0; 

        for (int i = 1; i < height - 1; i ++) {
            for (int j = 1; j < width - 1; j ++) {
                if (grid[i][j] != 5)
                   continue;

                int a = grid[i][j] - grid[i][j-1];
                if ( a > 4 || a < -4) 
                   continue;
                   
                int b = grid[i][j] - grid[i-1][j];
                if ( b > 4 || b < -4)
                   continue;

                int c = grid[i][j] - grid[i-1][j-1];
                if (c > 4 || c < -4)
                   continue;

                int d = grid[i][j] - grid[i-1][j+1];
                 if (d > 4 || d < -4)
                     continue;

                if (a == b || a == c || a == d ||
                    b == c || b == d || 
                    c == d)  {
                    continue;
                    }
                else {
                    if ( grid[i][j] + a != grid[i][j+1] ||
                         grid[i][j] + b != grid[i+1][j] ||
                         grid[i][j] + c != grid[i+1][j+1] ||
                         grid[i][j] + d != grid[i+1][j-1]) {
                             continue;
                         }
                    if (d + b + c == 0 && d - a - c == 0) 
                        count ++;
                  }
            }
        }

        return count;
    }
};
