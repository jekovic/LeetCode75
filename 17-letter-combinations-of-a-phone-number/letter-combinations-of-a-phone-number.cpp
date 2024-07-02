class Solution {
public:

    void backtracking(const string& digits, int idx, string s, vector<string>& res, const unordered_map<char, string>& m) {
        if(idx == digits.size()){
            res.push_back(s);
            return;
        }
        string letters = m.at(digits[idx]);
        for(char l : letters) {
            backtracking(digits, idx+1, s+l, res, m);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if(digits.empty()) return res;

        unordered_map<char, string> num = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"}, 
            {'6', "mno"}, 
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backtracking(digits, 0, "", res, num);

        return res;
    }
};