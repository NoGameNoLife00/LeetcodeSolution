class Solution {
public:
    int integerBreak(int n) {
        int* vDP = new int[n+1];
        if (n == 2){
            return 1;
        }
        if (n == 3){
            return 2;
        }
        if (n == 4) {
            return 4;
        }
        vDP[0] = 0;
        vDP[1] = 1;
        vDP[2] = 1;
        vDP[3] = 2;
        vDP[4] = 4;
        for (int i = 5; i <= n; i++){
            vDP[i] = 3 * max(vDP[i-3], i-3);
        }
        return vDP[n];

    }
};
//
// https://leetcode.com/problems/integer-break/
// 还是一道动态规划问题，求一个整数n拆分成x（x>2）个数字，求这x个数字相乘得到的最大数字
// 基本列出12个例子就可以看出规律了， 得到公式： n>=5时， dp[i]=3*max(dp[i-3],i-3)
//  
