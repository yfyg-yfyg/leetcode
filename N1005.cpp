class Solution {
    int sum(vector<int> vec) {
        int sum = 0;

        for (int i = 0; i < vec.size(); i ++) {
            sum += vec[i];
        }

        return sum;
    }
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());

        int i = 0;   
        while (A[i] < 0) {
            i ++;
        }
        
        int j = 0;
        while(K > 0 && j < i) {
            A[j] = -A[j];
            K --;
            j ++;
        }

        if (K > 0 && K % 2 == 1) {
            int m = i;
            for (; m > 0; m--) {
                if (A[m-1] >= A[m]) {
                    A[m] = -A[m];
                    break;
                }
            }
            if (m == 0) 
               A[0] = -A[0];
        }

        return sum(A);
 
    }
};

