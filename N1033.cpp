class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        
       vector<int> pos = {a, b, c};
       sort(pos.begin(), pos.end());
       a = pos[0];
       b = pos[1];
       c = pos[2];

       int max_moves = 0, min_moves = 0;
       max_moves = c - a - 2;

       if (a + 1 == b && b + 1 == c)
           min_moves = 0;
       else if (a + 1 == b || b + 1 == c || b - a == 2 || c - b == 2)
           min_moves =  1;
       else 
           min_moves = 2;

        return {min_moves, max_moves};
        
    }
};

