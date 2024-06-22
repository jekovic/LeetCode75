class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;

        bool flag1 = true, flag2 = true;
        set<char> s1, s2;
        map<char, int> m1, m2;
        for(char w : word1){
            s1.insert(w);
            m1[w]++;
        }

        for(char w : word2){
            s2.insert(w);
            m2[w]++;
        }
        
        vector<int> temp1, temp2;
        for(auto i = m1.begin(); i != m1.end(); i++) {
            temp1.push_back(i->second);
        }
        for(auto i = m2.begin(); i != m2.end(); i++) {
            temp2.push_back(i->second);
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if(s1 != s2)
            return false;
        else {
            if(temp1 == temp2){
                return true;
            }
            else return false;
        }

    }
};