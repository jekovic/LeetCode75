class Solution {
    /*
    https://wyatti.tistory.com/entry/Cc-%EC%B5%9C%EB%8C%80-%EA%B3%B5%EC%95%BD%EC%88%98
    */
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(),str2.size())) : "";
    }
};