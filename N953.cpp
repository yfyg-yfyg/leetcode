class Solution {
    map<char, int> char_order_map;

    bool compareWord(const string &a, const string &b) {
        int len = min(a.length(), b.length());
        for (int i = 0; i < len; i ++) {
            if (a[i] != b[i]) {
                return char_order_map[a[i]] < char_order_map[b[i]];
            } 
        }
        return  a.length() < b.length();
    }

    void genMap(const string &order) {
        for(int i = 0; i < order.length(); i ++) {
            char_order_map[order[i]] = i;
        }
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        genMap(order);
        for (int i = 0; i < words.size() - 1; i ++) {
            if (!compareWord(words[i], words[i + 1]))
                return false;
        }

        return true;
    }
};

