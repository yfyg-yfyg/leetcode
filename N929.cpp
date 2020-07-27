class Solution {

public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> emails_map;

        for (int i = 0; i < emails.size(); i ++) {
            string converted;
            bool local_name = true;
            bool ignore = false;
            for (int j = 0; j < emails[i].length(); j ++) {
                if (emails[i][j] == '@') {
                    local_name = false;
                    ignore = false;
                    converted += emails[i][j];
                }

                if (local_name && emails[i][j] == '+') {
                    ignore = true;
                }

                if ((!ignore && local_name && emails[i][j] != '.') ||
                    !local_name) {
                    converted += emails[i][j];
                }
            }

            emails_map[converted] ++;
        }

        return emails_map.size();

    }
};

