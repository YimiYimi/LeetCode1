//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数
//将返回左旋转两位得到的结果"cdefgab"。 
//
// 
//
// 示例 1： 
//
// 输入: s = "abcdefg", k = 2
//输出: "cdefgab"
// 
//
// 示例 2： 
//
// 输入: s = "lrloseumgh", k = 6
//输出: "umghlrlose"
// 
//
// 
//
// 限制： 
//
// 
// 1 <= k < s.length <= 10000 
// 
// Related Topics 数学 双指针 字符串 
// 👍 135 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //subdtr
    string reverseLeftWords1(string s, int n) {
        return s.substr(n, s.size()-n) + s.substr(0, n);
    }
    //取余拼接
    string reverseLeftWords(string s, int n) {
        string res = "";
        for(int i = n; i < s.length() + n; i++){
            res += s[i%s.length()];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
