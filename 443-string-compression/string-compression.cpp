class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;

        for(int i=0; i < chars.size();) {
            const char c = chars[i];
            int cnt = 0;

            while(i < chars.size() and chars[i] == c){
                ++cnt;
                ++i;
            }

            chars[ans++] = c;

            if (cnt > 1){
                for(char c_ : to_string(cnt)){
                    chars[ans++] = c_;
                }
            }
        }

        return ans;
    }
};