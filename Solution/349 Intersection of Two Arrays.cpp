// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> result;
        for(int n : nums1){
            s.insert(n);
        }
        for (int n : nums2) {
            if (s.count(n)) {
                result.push_back(n);
                s.erase(n);
            }
        }
        return result;
    }
};

// https://leetcode.com/problems/intersection-of-two-arrays/
// 输入两个数组nums1，nums2， 求两个数组中都存在的元素。
// 解法： 将nums1的元素存到集合s中， 之后再遍历nums2， 如果nums2中的元素在集合s中存在，就将该元素添加到结果数组中，并从集合s中移除
// 		输出结果数组