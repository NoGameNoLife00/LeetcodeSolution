class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);

        for (int i = 1; i < result.size(); i++) {
            result[i] = result[i/2] + i%2;
        }

        return result;
    }
};
// 一个简单的动态规划问题。
// 7:[0 1 1 2 1 2 1 2 2 3]
// 直接找出规律， 第i个数字的bit 1的个数是
// 奇数：它前面的中间（i/2）位置上bit 1的个数 加上 1
// 偶数： 与前面的中间（i/2）位置上bit 1的个数相等
