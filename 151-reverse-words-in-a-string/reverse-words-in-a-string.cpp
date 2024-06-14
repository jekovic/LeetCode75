class Solution {
public:
    string reverseWords(string s) {
        vector<string> result;
        string temp = "";
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (temp != "") {
                    result.push_back(temp);
                    temp = "";
                }
            }
            else {
                string t(1, s[i]);
                temp += t;
                if (i == s.size() - 1) {
                    if (temp != "") {
                        result.push_back(temp);
                        temp = "";
                    }
                }
            }
        }

        reverse(result.begin(), result.end());

        for (int i = 0; i != result.size(); i++) {
            res += result[i];
            if (i == result.size() - 1) break;
            res += " ";
        }

        return res;
    }
};