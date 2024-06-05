class Solution {
public:
    string removeStars(string s) {
        vector<char> str;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') str.pop_back();
            else str.push_back(s[i]);
        }
        string ret = "";
        for(int i=0; i != str.size(); i++) {
            //cout << str[i];
            ret += str[i];
        }
        return ret;
    }
};