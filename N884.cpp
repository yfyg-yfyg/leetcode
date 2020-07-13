class Solution {
  
    unordered_map<string, int> InsertToMap(string A) {
        unordered_map<string, int> a_map;
        int word_begin = -1;

        for (int i = 0; i < A.length(); i ++) {
            if (A[i] != ' ' && word_begin == -1) {
                if (i == A.length() - 1) {
                    string word;
                    word += A[i];
                    auto it = a_map.find(word);
                    if (it == a_map.end()) {
                        a_map.insert(std::make_pair<string, int>(string(word), int(1)));
                    }
                    else {
                        it->second ++;
                    }
                }
                else 
                    word_begin = i;
            }
            else  {
               string word;
               if (A[i] == ' ' && word_begin != -1)   {
                  word = A.substr(word_begin, i - word_begin);
                  word_begin = -1;
               }
               else if (i == A.length() -1 && word_begin != -1) {
                   word = A.substr(word_begin, i - word_begin + 1);
               }

               if (!word.empty()) {
                   auto it = a_map.find(word);
                   if (it == a_map.end()) {
                       a_map.insert(make_pair(string(word), int(1)));
                   }
                   else {
                     it->second ++;
                    }
               }
            }
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
