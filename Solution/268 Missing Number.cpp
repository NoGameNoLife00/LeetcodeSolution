// 解法1： 41ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int len = nums.size();
        int cnt = 0;
        vector<int> tmp(nums.size()+1, 0);
        for (int n : nums){
            tmp[n] = 1;
        }
        for (int i = 0; i < tmp.size(); i++ ){
            if (tmp.at(i) == 0){
                result = i;
                break;
            }
        }
        return result;
    }
};
// 解法2： 36ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int len = nums.size();
        int sum = (len) * (len + 1) / 2;
        int currSum = 0;
        for (int n : nums) {
            currSum += n;
        }
        result = sum - currSum;
        return result;
    }
};
// 解法3： 36ms
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int cnt = 0;
        for (int n : nums) {
            result ^= n;
            result ^= cnt;
            cnt++;
        }
        return result;
    }
};
https://leetcode.com/problems/missing-number/
要求：给定一个数组nums 数组大小为n， 按照0，1，2....n的顺序，数组里面会少一个数字， 求出这个缺少的数字
例如[0, 1, 3] 输出 2
解法1； 创建一个大小为n+1的辅助数组tmp并初始化为0， 然后遍历nums，为tmp数组元素赋值。nums中出现了数字i，tmp对应的i元素赋值为1
        之后遍历tmp数组，找到值不为1的元素的位置。 该值就为缺少的数字
解法2： 利用数学公式 sum = n * (n+1)/2； 求得0,1...n的和。 之后遍历nums，求得nums数组元素值的和currSum， sum-currSum就为结果
解法3： 利用位运行，两个相同的数进行异或，结果为0原理。将nums数组中所有元素值和0，1...n全部异或一遍。 得到的值就是结果