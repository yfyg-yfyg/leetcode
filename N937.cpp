class Solution {

    bool isDigitLog(const string &log) {
        return std::find_if(log.begin(), log.end(), 
                            [](char c) { return !(isdigit(c) || c == ' '); }) == log.end();
    }

    void insertLetterLog(vector<string> &logs, const string &letter_content,
                                           const string &letter_log) {
        auto pos = find_if(logs.begin(), logs.end(), 
                           [&letter_content](const string &log) {
                               int pos = log.find(' '); 
                               string log_content = log.substr(pos + 1);
                               return letter_content.compare(log_content) <= 0 ;
                            } );

     
            logs.insert(pos, letter_log);
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<string> digit_logs;

        for (auto log : logs) {
            int pos = log.find(' ');
            string identifier = log.substr(0, pos);
            string content = log.substr(pos + 1);
            if (isDigitLog(content)) {
                digit_logs.push_back(log);
            }
            else {
                insertLetterLog(ans, content, log);
            }
        }

        ans.insert(ans.end(), digit_logs.begin(), digit_logs.end());

        return ans;
    }
};

