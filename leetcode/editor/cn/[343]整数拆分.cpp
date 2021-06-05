//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划 
// 👍 525 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3)  return n-1;
        switch(n%3){
            case 0:return pow(3, n/3);
            case 1:return pow(3, (n-4)/3)*2*2;
            case 2:return pow(3, (n-2)/3)*2;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
