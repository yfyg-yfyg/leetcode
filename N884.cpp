class Solution {
  
    unordered_map<string, int> InsertToMap(string A) {
        unordered_map<string, int> a_map;
       
        string word;
        for(auto &a_char : A) {
            if (a_char == ' ' && !word.empty()) {
                a_map[word] ++;
                word.clear();
            }
            else if (a_char != ' ') {
                    word += a_char;
            }
        }
           
        if (!word.empty()) {
            a_map[word] ++;
            word.clear();
        }
       
        return a_map;
    }

    void Check(unordered_map<string, int> &A, unordered_map<string, int> &B, vector<string> &result) {
        for (auto it = A.begin(); it != A.end(); it ++) {
            if (it->second == 1 && B.find(it->first) == B.end()) {
                result.push_back(it->first);
            }
        }

        return;
    }
    
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> a_map = InsertToMap(A);
        unordered_map<string, int> b_map = InsertToMap(B);

        vector<string> result; 

        Check(a_map, b_map, result);
        Check(b_map, a_map, result);

        return result;
    }
};
