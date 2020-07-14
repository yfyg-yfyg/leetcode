class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int>  ans;
        
        sort(B.begin(), B.end(), [](int a, int b) { return a < b ;});
        int sumA = 0, sumB = 0;
        for (auto a : A) {
            sumA += a;
        }

        for (auto b : B) {
            sumB += b;
        }

        int gap = (sumA - sumB) / 2;

        for (auto a : A) {
            if (binary_search(B.begin(), B.end(), a - gap)) {
                ans.push_back(a);
                ans.push_back(a - gap);
                break;
            }
        }

        return ans;
    }

       
};

