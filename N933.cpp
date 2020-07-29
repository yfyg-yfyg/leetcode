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

