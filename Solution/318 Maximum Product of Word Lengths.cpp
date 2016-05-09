class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if (len == 0) {
            return 0;
        }
        vector<int> vTemp(len, 0);
        int nMax = 0;
        for (int i = 0; i < len; i++){
            for (char ch : words[i]){
                vTemp[i] |= 1 << (ch - 'a');
            }
        }
        for (int i = 0; i < len ; i++){
            for (int j = i + 1; j < len; j++) {
                if ((vTemp[i] & vTemp[j]) == 0){
                    int t = words[i].length() * words[j].length();
                    nMax = nMax > t ? nMax : t;
                }

            }
        }
        return nMax;
    }
};

// https://leetcode.com/problems/maximum-product-of-word-lengths/
// 要求：给定一个单词字符串数组， 求出里面2个字符长度相乘最大的乘积，且这两个字符串不包含相同的字母（小写字母）
// 例子：["abcw", "baz", "foo", "bar", "xtfn", "abcdef"] 结果：16 及取"abcw", "xtfn"
// 解法：分析发现，一共有26个小写字母，可以用一个32位的int存储对应每个字母的掩码。通过两个掩码的相与（&）结果为0表示两个单词没有想同的字母，
// 所有可以创建一个words.size()大小的新数组Temp， 里面存储words对应的单词的掩码。 之后遍历数组中的掩码，两两相与（&），结果为0时，找出最大的乘积。

