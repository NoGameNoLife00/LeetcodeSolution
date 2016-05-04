class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++){
            dict[nums.at(i)]++;
        }
        set<pair<int, int>> sets;
        for (auto it = dict.begin(); it != dict.end(); it++){
            sets.insert(make_pair(it->second, it->first));
        }
        int count = 0;
        for (auto it = sets.rbegin(); it != sets.rend(); it++) {
            if (count < k){
                ret.push_back(it->second);
            }
            else {
                break;
            }
            count++;
        }
        return ret;
    }
};

// https://leetcode.com/problems/top-k-frequent-elements/
// 输入一个数组nums， 和一个正整数k， 输出k个元素的数组，该数组中元素为数组nums中出现最多元素值
// 如[1,1,1,2,2,3] k = 2, 输出 [1,2].
// 解法：创建一个哈希表来存储nums中的元素，和出现的个数。遍历nums，初始化哈希表dict
// 之后再遍历哈希表dict，存储到集合sets中（set中pair分别存两个值：元素出现的次数和元素的值），根据容器set<>特性，插入元素时就会排序(元素出现的次数)
// 最后将集合sets的前k个pair中的 元素的值加入最终输出的数组ret中