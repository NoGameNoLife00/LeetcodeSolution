class Solution {
public:
    string reverseString(string s) {
        string restul;
        int len = s.length();
        for(int i = len-1; i >= 0; i--){
            restul += s[i];
        }
        return restul;
    }
};
