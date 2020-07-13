class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int z_max = 0;
        int area = 0;

        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        for (int x = 0; x < grid.size(); x ++) {
            for (int y = 0; y < grid[0].size(); y ++) {
                if (grid[x][y] > 0) 
                    area ++;

                if (grid[x][y] > z_max) 
                    z_max = grid[x][y];
            }
        }
         
        int x_width = grid.size();
        int y_width = grid[0].size();

        vector<vector<int>>  xz(grid.size(), vector<int>(z_max));
        vector<vector<int>>  yz(grid[0].size(), vector<int>(z_max));

        for (int x = 0; x < grid.size(); x ++) {
            for (int y = 0; y < grid[0].size(); y ++) {
                if (grid[x][y] > 0) {
                    for (int h = 0; h < grid[x][y]; h ++) {
                        xz[x][h] ++;
                        yz[y][h] ++;
                    }
                }
            }
        }

        for (int x = 0 ; x < grid.size(); x ++) {
            for (int z = 0; z < z_max; z ++) {
                if (xz[x][z] > 0) 
                   area ++;
            }
        }

        for (int y = 0 ; y < grid[0].size(); y ++) {
            for (int z = 0; z < z_max; z ++) {
                if (yz[y][z] > 0) 
                   area ++;
            }
        }

        return area;
    }
};
