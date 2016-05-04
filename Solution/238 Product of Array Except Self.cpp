class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> output(len, 1);
        int i = 0;
        int leftProduct = 1;
        int rightProduct = 1;

        while (i < len) {
            output[i] *= leftProduct;
            leftProduct *= nums[i];
            i++;
            output[len-i] *= rightProduct;
            rightProduct *= nums[len-i];
        }
        return output;
    }
};

// https://leetcode.com/problems/product-of-array-except-self/
// 输入一个数组nums
// 输出一个相同大小的数组，数组中每个i位置的元素 是数组nums[i]以外的所有元素的乘积
// 解法很简单 设置两个变量 leftProduct = 1和 rightProduct = 1，然后 遍历nums数组， leftProduct 从左边开始累乘， rightProduct 从右边开始累乘
// output[i] = leftProduct * rightProduct
