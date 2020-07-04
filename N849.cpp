class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = -1;
         
        bool searching_start = true;
        int start, end;
        int distance;
        for (int i = 0; i < seats.size(); i ++) {
            if (searching_start) {
                if (seats[i] == 0) {
                    start = i;
                    searching_start = false;
                }
            }
            else {
                if (seats[i] == 1) {
                    end = i - 1;
                    searching_start = true;
                    
                    if (start == 0) {
                        distance = end - start + 1;
                    }
                    else {
                        distance = (end - start) / 2 + 1;
                    }
                    max_dist = max(distance, max_dist);
                }
            }
        }
      
        if (!searching_start) {
            distance =  seats.size() - start;
            max_dist = max(distance, max_dist);
        }
   
        return max_dist;
    }
};
