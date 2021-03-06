class RecentCounter {
    vector<int> timestamps;
public:
    RecentCounter() {
    }
   
    int ping(int t) {

        vector<int>::iterator it = timestamps.begin();
        for (; it != timestamps.end(); it ++) {
            if (t - (*it) <= 3000) 
               break;
        }
       
        timestamps.erase(timestamps.begin(), it);
        timestamps.push_back(t);
 
        return timestamps.size();
     }
};


class RecentCounter {
    deque<int> timestamps;
public:
    RecentCounter() {
    }
   
    int ping(int t) {

       timestamps.push_back(t);

        while(t - timestamps.front() > 3000) {
            timestamps.pop_front();
        }
       
        return timestamps.size();
     }
};

