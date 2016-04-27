class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        int alph[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            alph[s.at(i) - 'a']++;
            alph[t.at(i) - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (alph[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// 原题： https://leetcode.com/problems/valid-anagram/
// 检查两个字符串是否是 相同字母组成的异构单词
// 因为输入只有小写，解决起来也很简单（不区分大小写也简单）
// 创建一个26位的int数组，依次代表a-z字母出现的次数。变量两个字符串，s字符串中出现+1， t字符串出现-1。
// 遍历之后若数组元素还是全部为0,则为异构单词，返回true
