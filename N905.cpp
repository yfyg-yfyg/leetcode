class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;
        vector<int> odd;

        for (int i = 0; i < A.size(); i ++) {
            if (A[i] % 2 == 0) 
                ans.push_back(A[i]);
            else {
                odd.push_back(A[i]);
            }
        }

        ans.insert(ans.end(), odd.begin(), odd.end());

        return ans;
    }
};



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        sort(A.begin(), A.end(), [](int a , int b) {
                                                     return (a % 2 == 0 && b % 2 == 1);
                                                   });

        return A;
    }
};


