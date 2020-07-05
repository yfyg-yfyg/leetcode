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


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

      int max_dist = 0;
      int distance = 0;
      int length = seats.size();
      for (int i = 0; i < length; i ++) {
         if (seats[i] == 0) {
            distance ++;
         }
         else {
            if (distance != 0) {
                max_dist = max(max_dist, (distance + 1) / 2);
                distance = 0;
            }
         }
      }

      for (int i = 0; i < length; i ++) {
         if (seats[i] != 0) {
            max_dist = max(max_dist, i);
            break;
         }
     }

     for (int i = length - 1; i >= 0; i --) {
          if (seats[i] != 0) {
              max_dist = max(max_dist, length - i - 1);
              break;
          }
      }

      return max_dist;
    }
};
