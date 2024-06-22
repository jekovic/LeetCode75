class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        map<int, int> r;

        for(int a: arr){
            m[a]++;
        }

        for(auto i = m.begin();  i != m.end(); i++){
            r[i->second]++;
            if(r[i->second] > 1)
                return false;
        }

        return true;
    }
};