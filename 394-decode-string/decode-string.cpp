class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> num;
        stack<string> st;
        int n = 0;

        for(int i=0; i != s.size(); i++) {
            if(isdigit(s[i])){
                //n = int(s[i]-'0');
                n = n * 10 + (s[i]-'0');
            }
            else if(s[i] == '['){
                num.push(n);
                n = 0;
                st.push(res);
                res = "";
            }
            else if(s[i] == ']'){
                int k = num.top();
                num.pop();
                string temp = st.top();
                st.pop();
                for(int t=0; t<k; t++) {
                    temp += res;
                }
                res = temp;                
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};