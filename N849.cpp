class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int mstart, mend; 
        int max_dist = -1;
         
        bool searching_end = false;
        int start, end;
        int distance; 
        for (int i = 0; i < seats.size(); i ++) {
            if (searching_end) {
                if (seats[i] != 0) {
                    searching_end = false;
                    end = i - 1;
                    int distance;
                    if (start != 0)
                       distance = (end - start) / 2 + 1;
                    else 
                       distance = end - start + 1;

                    if (distance > max_dist) 
                        max_dist = distance;
                }
                else if (i == seats.size() - 1) {
                    searching_end = false;
                    end = i;
                    
                    int distance = end - start + 1;
                    if (distance > max_dist) {
                        max_dist = distance;
                    }
                }
            }
            else {
                if (seats[i] == 0)  {
                    start = i;
                    searching_end = true;
                }
           }
        }

        if (searching_end && start == seats.size() - 1 ) {
            if (max_dist < 1) 
               max_dist = 1;
        }

        return max_dist;

    }
};
