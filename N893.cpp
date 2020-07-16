class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<string>  sorted_A;
        
        for (auto a : A) {
            string odd, even;
            for (int i = 0; i < a.size(); i ++) {
                if (i % 2 == 0)
                   even += a[i];
                else 
                   odd += a[i];
            }

            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());

            sorted_A.push_back(even + odd);
          
        }

        sort(sorted_A.begin(), sorted_A.end());
       
        int count = 0;
        for (int i = 0; i < sorted_A.size() - 1; i ++) {
            if (sorted_A[i] != sorted_A[i + 1]) {
                count ++;
            }
        }

        return ++count; 
    }
};
