class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        sort(A.begin(), A.end(), [](int a, int b) { return a < b ;});
        sort(B.begin(), B.end(), [](int a, int b) { return a < b ;});

        int sumA = 0, sumB = 0;
        for (auto a : A) {
            sumA += a;
        }

        for (auto b : B) {
            sumB += b;
        }

        vector<int> *larger ;
        vector<int> *smaller;
        int gap;
        if (sumA > sumB) {
            larger = &A;
            smaller = &B;
            gap = (sumA - sumB) / 2;   
         }
         else {
             larger = &B;
             smaller = &A;
             gap = (sumB - sumA) / 2;
         }
  
         int large = -1, small = -1;
         int j = 0;
         for (int i = 0; i < (*smaller).size(); i ++) {
            for (; j < (*larger).size(); ) {
                 if ((*larger)[j] - (*smaller)[i] == gap) {
                     large = (*larger)[j];
                     small = (*smaller)[i]; 
                     break;
                 }
                 else if ((*larger)[j] - (*smaller)[i] > gap){
                     j = j > 0 ? j - 1 :  0;
                     break;
                 }
                 j ++;
             }

             if (large != -1) 
                break;
        }

         vector<int> ans;
         if (sumA > sumB)  {
             ans.push_back(large);
             ans.push_back(small); 
         }
         else {
            ans.push_back(small);
            ans.push_back(large);
         }

         return ans;
    }
};
