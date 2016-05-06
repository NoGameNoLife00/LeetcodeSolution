class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) {
            return 0;
        }

        return sqrt(n);
    }
};

// https://leetcode.com/problems/bulb-switcher/
// 给定n个灯泡， 初始化全部关闭， 第一轮，按下每一个灯泡的开关（全部打开）。
// 第二轮， 按下每个距离为2的灯泡的开关。第三轮，按下每隔3个的灯泡开关。
// 第i轮，按下每隔i个的灯泡开关。第n轮， 按下第n个灯泡的开关。
// 如：n=4
// [0000]->[1111]->[1010]->[1000]->[1001]
// 结果为2
// 解法： 直接举例多个n的取值从中找规律，然后发现结果为n的平方根取整及int(sqrt(N))
//