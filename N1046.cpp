class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while(stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int left = stones[stones.size() - 1] - stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (left >  0) 
               stones.push_back(left);
        }

        return stones.size() == 0 ? 0 : stones[0];
       
    }
};

