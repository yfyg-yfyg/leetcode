class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    
        for (int i = 0; i < grid.size(); i ++) {
            grid[i].insert(grid[i].begin(), 0);
            grid[i].push_back(0);
        }

        vector<int> pading(grid[0].size(), 0);
        grid.insert(grid.begin(), pading);
        grid.push_back(pading);

        int sum_x = 0, sum_y = 0, bottom = 0;
        for (int y = 1; y < grid.size(); y ++) {
            for (int x = 1; x < grid.size(); x ++) {
                sum_x += abs(grid[y][x] - grid[y][x-1]);
                sum_y += abs(grid[x][y] - grid[x-1][y]);

                if (grid[y][x]) 
                   bottom ++;
            }
        }

        return sum_x + sum_y + bottom * 2; 
 
    }
};
