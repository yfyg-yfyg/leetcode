class Solution {
    
    enum  Direction {
        GO_NORTH,
        GO_EAST,
        GO_SOUTH,
        GO_WEST
    };

    Direction changeDirection(Direction orig_dir, int turn) {
        Direction next_dir;

        if (orig_dir == GO_NORTH ) {
           if (turn == -1) 
               next_dir = GO_EAST;
           else if (turn == -2) 
               next_dir = GO_WEST;
        }

        if (orig_dir == GO_SOUTH ) {
           if (turn == -1) 
               next_dir = GO_WEST;
            else if (turn == -2) 
               next_dir = GO_EAST;
        }

        if (orig_dir == GO_WEST ) {
           if (turn == -1) 
               next_dir = GO_NORTH;
            else if (turn == -2) 
               next_dir = GO_SOUTH;
        }

        if (orig_dir == GO_EAST ) {
           if (turn == -1) 
               next_dir = GO_SOUTH;
            else if (turn == -2) 
               next_dir = GO_NORTH;
        }

        return next_dir;
    }

    struct pair_hash {
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const {
            auto h1 = hash<T1>()(p.first);
            auto h2 = hash<T2>()(p.second);
            return h1 ^ h2;
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        Direction cur_dir = GO_NORTH;
        vector<int> cur_pos = {0,0};
        int max_distance = 0;
        unordered_set<std::pair<int, int>, pair_hash>  obstacles_set;

        for (int i = 0; i < obstacles.size(); i ++) {
            obstacles_set.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }

        for(int i = 0; i < commands.size(); i ++) {
            if (commands[i] == -1 || commands[i] == -2)
               cur_dir = changeDirection(cur_dir, commands[i]);

            else if (commands[i] >= 1 && commands[i] <= 9 ) {
            //    cout << "cur_pos:(" << cur_pos[0] << "," << cur_pos[1] << ")" 
            //         << " direction:" << cur_dir << " forward:" << commands[i] << endl;

               for (int j = 1; j <= commands[i]; j ++) {
                   if (cur_dir == GO_NORTH) {
                       if (obstacles_set.find(make_pair(cur_pos[0], cur_pos[1] + 1)) != obstacles_set.end())
                            break;
                        else {
                            cur_pos[1] = cur_pos[1] + 1; 
                        }
                   }

                   if (cur_dir == GO_SOUTH) {
                       if (obstacles_set.find(make_pair(cur_pos[0], cur_pos[1] - 1)) != obstacles_set.end())
                            break;
                        else {
                            cur_pos[1] = cur_pos[1] - 1; 
                        }
                   }

                   if (cur_dir == GO_WEST) {
                       if (obstacles_set.find(make_pair(cur_pos[0] - 1 , cur_pos[1])) != obstacles_set.end())
                            break;
                        else {
                            cur_pos[0] = cur_pos[0] - 1; 
                        }
                   }

                   if (cur_dir == GO_EAST) {
                       if (obstacles_set.find(make_pair(cur_pos[0] + 1, cur_pos[1])) != obstacles_set.end())
                            break;
                        else {
                            cur_pos[0] = cur_pos[0] + 1; 
                        }
                   }
               }

               max_distance = max(max_distance, cur_pos[0] * cur_pos[0] + cur_pos[1] * cur_pos[1]);
            }
       }

        return max_distance;
    }
};
