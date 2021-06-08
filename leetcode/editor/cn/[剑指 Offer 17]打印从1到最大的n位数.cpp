//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。 
//
// 示例 1: 
//
// 输入: n = 1
//输出: [1,2,3,4,5,6,7,8,9]
// 
//
// 
//
// 说明： 
//
// 
// 用返回一个整数列表来代替打印 
// n 为正整数 
// 
// Related Topics 数学 
// 👍 128 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //普通情况
    vector<int> printNumbers(int n) {
        int num = pow(10, n);
        vector<int> re;
        for(int i = 1; i < num; i++){
            re.push_back(i);
        }
        return re;
    }
    //大数情况
    void printNumbers2(int n) {
        string s = "0";
        while(s.size() <= n){
            cout << s << endl;
            int i = s.size()-1;
            while(i >= 0 && s[i] == '9')    s[i--] = '0';
            if(i < 0)   s = "1" + s;
            else    s[i] += 1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
