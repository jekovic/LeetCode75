class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int sz = 0;
        int s1 = word1.size();
        int s2 = word2.size();
        if(s1 >= s2){
            sz = s1;
        }
        else{
            sz = s2;
        }

        for(int i=0; i != sz; i++){
            if(i < word1.size()){
                result += word1[i];
            }
            if(i <word2.size()){
                result += word2[i];
            }
        }
        return result;
    }
};