class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0; i < A.size(); i ++) {
            if ( i % 2 == 0) {
                if (A[i] % 2 == 0) {
                    continue;
                }
                else {
                    for (int j = i + 1; j < A.size(); j ++) {
                        if (A[j] % 2 == 0) {
                            int temp = A[i];
                            A[i] = A[j];
                            A[j] = temp;
                            break;
                        }
                    }
                }
            }
            else {
                 if (A[i] % 2 == 1) {
                    continue;
                }
                else {
                    for (int j = i + 1; j < A.size(); j ++) {
                        if (A[j] % 2 == 1) {
                            int temp = A[i];
                            A[i] = A[j];
                            A[j] = temp;
                            break;
                        }
                    }
                }

            }
        
        }

        return A;

    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int>  ans(A.size(), 0);
        int even = 0, odd = 1;


        for (int i = 0; i < A.size(); i ++) {
            if (A[i] % 2 == 0) {
                ans[even] = A[i];
                even += 2;
            }
            else {
                ans[odd] = A[i];
                odd += 2;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0, odd = 1;

        for (; even < A.size(); even += 2) {
            if (A[even] % 2 == 1) {
                while(A[odd] % 2 == 1) {
                    odd += 2;
                }

                int temp;
                temp = A[even];
                A[even] = A[odd];
                A[odd] = temp;
            }
        }

        return A;
    }
};



