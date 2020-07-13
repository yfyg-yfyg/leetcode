class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int z_max = 0;
        int area = 0;

        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        for (int x = 0; x < grid.size(); x ++) {
            int y_max = 0, x_max = 0;
            for (int y = 0; y < grid[0].size(); y ++) {
                if (grid[x][y] > 0) area ++;
                y_max = max(y_max, grid[x][y]);
                x_max = max(x_max, grid[y][x]); 
            }
            area += y_max + x_max;
       }

        return area;
    }
};
