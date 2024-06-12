class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_p = 0 , t_p = 0;
        bool res = false;
        
        while(1) {
            if(s_p == s.size()){
                res = true;
                break;
            }
            if(t_p == t.size()){
                break;
            }

            if(s[s_p] == t[t_p]){
                s_p++;
                t_p++;
            }
            else{
                t_p++;
            }
        }
        return res;
    }
};