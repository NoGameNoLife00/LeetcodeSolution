// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        int lo = 1;
        int hi = nums.size()-1;
        int mi;
        while (lo < hi){
            mi = lo + (hi - lo) / 2;
            int counts = 0;
            for (int n : nums){
                if (n <= mi){
                    counts++;
                }
            }

            if (counts <= mi){
                lo = mi+1;
            }else {
                hi = mi;
            }

        }
        ret = lo;
        return ret;
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/
// 要求：给定一个数组nums里面有n+1个数字（范围1到n），里面的某个数字i会重复多次，找出这个数字
// 例：[1,1,2] 结果为2
// 解法：利用二分查找法， 1到n个数字中， 如果小于等于mi=n/2的元素为n/2个。如果多与n/2，则结果就在1到n/2直接。如果小于，结果就在mi+1到n之间。
// 	重复上述过程，当lo>=hi时，结果就为lo
