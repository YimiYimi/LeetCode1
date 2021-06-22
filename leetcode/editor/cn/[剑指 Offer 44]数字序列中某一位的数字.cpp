//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学 
// 👍 138 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //找规律解法
    int findNthDigit(int n) {
        int digit = 1;
        long start = 1, count = 9;
        while(n > count){
            n -= count;
            digit++;
            start *= 10;
            count = start*digit*9;
        }
        long num = start+(n-1)/digit;
        stringstream ss;
        ss << num;
        string s;
        ss >> s;
        return s[(n-1)%digit] - '0';
    }
};

//leetcode submit region end(Prohibit modification and deletion)
