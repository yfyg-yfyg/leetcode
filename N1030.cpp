class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
       vector<vector<int>> ans(R*C, vector<int>(2,0));

       for(int i = 0; i < R; i ++)  {
           for (int j = 0; j < C; j ++) {
               ans[i * C + j][0] = i;
               ans[i * C + j][1] = j;
             //  cout << "(" << i << "," << j << ")" << endl;
           }
       }

       sort(ans.begin(), ans.end(), [&r0, &c0](const vector<int> &a , const vector<int> &b) {
                                               return abs(a[0]-r0)+abs(a[1]-c0) < 
                                                      abs(b[0]-r0)+abs(b[1]-c0); 
                                               });

       return ans;
    }
};


class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
      // vector<vector<int>> ans(R*C, vector<int>(2,0));
       map<int, vector<vector<int>>> bucket;

       for(int i = 0; i < R; i ++)  {
           for (int j = 0; j < C; j ++) {
               vector<int> tmp = {i, j};
               bucket[abs(i - r0) + abs(j - c0)].emplace_back(tmp);

           }
       }


      vector<vector<int>> ans;
      for(auto it = bucket.begin(); it != bucket.end(); it ++) {
          ans.insert(ans.end(), it->second.begin(), it->second.end());
      }

       return ans;
    }
};

