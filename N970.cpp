class Solution {

public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans_set;
        vector<int> ans;

        for(int i = 0; ; i ++) {
            int first = pow(x, i);
            if (first <= bound) {
                cout << i << endl;
                for (int j = 0; ; j ++) {
                     int second = pow(y, j);
                     if (first + second > bound)
                         break;
                     
                     cout << j << endl << endl;
                     ans_set.insert(first + second);
                     if (y <= 1)
                         break;
                }

                if (x <= 1)
                    break;
            }
            else 
                break;
        }

        for (set<int>::iterator it = ans_set.begin(); it != ans_set.end(); it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};

