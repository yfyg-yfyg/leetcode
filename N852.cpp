class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0;
        for (; i < A.size() -1; i ++) {
            if (A[i + 1] < A[i]) 
              break;
        }

        return i; 
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;

        while(left < right)  {
            int mid = (left + right) / 2;
            if (A[mid] < A[mid +1]) {
                left = mid + 1;
            } 
            else 
                right = mid;
        }
        return right;
       // return top;
    }
};
