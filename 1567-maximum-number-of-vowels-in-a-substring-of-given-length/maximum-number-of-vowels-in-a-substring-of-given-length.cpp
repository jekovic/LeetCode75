class Solution {
public:

    bool judge_vowel(char c_){
        if(c_ == 'a' || c_ == 'e' ||
            c_ == 'i' || c_ == 'o' || c_ == 'u'){
                return true;
            }
        return false;
    }
    
    int maxVowels(string s, int k) {
        int res = 0;
        int cnt = 0;
        for(int i=0; i<k; i++) {
            if(judge_vowel(s[i])) cnt++;
        }
        res = cnt;

        if(s.size() > k) {
            for(int i=k; i < s.size(); i++) {
                if(judge_vowel(s[i-k])){
                    if(judge_vowel(s[i])){
                        cnt = cnt;
                        if(res < cnt) res = cnt;
                    }
                    else{
                        cnt--;
                    }
                }
                else{
                    if(judge_vowel(s[i])){
                        cnt++;
                        if(res < cnt) res = cnt;
                    }
                }
            }
        }
        return res;
    }
};