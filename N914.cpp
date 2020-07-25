class Solution {

private:
     set<int> getFactors(int x) {
         set<int> factors;
         int factor = 2;
         int max_factor = sqrt(x);
         int num = x;
         
         while(factor <= num) {
             if (num % factor == 0) {
                 factors.insert(factor);
                 num = num / factor;
                 factor = 2;
             }
             else 
                 factor ++;
         }

         factors.insert(x);
        
         return factors;
     }

public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1)
           return false;

        map<int, int> num_map;
        for (auto card : deck){
            num_map[card] ++;
        }
       
        vector<set<int>> factors_vec;
        for (auto it = num_map.begin(); it != num_map.end(); it++) {
            auto factors = getFactors(it->second);
            factors_vec.push_back(factors);
        }

        set<int> first = factors_vec[0];
        for (auto it = first.begin(); it != first.end(); it ++) {
            int i = 1;
            for (; i < factors_vec.size(); i ++) {
                if (factors_vec[i].count(*it) == 0) 
                    break;
            }

            if (i == factors_vec.size())
                return true; 
        }

        return false;

     }
};

