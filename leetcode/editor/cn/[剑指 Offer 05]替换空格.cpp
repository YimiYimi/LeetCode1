//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// 👍 122 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    string replaceSpace(string s) {
//        string re = "";
//        for(char c:s){
//            switch(c){
//                case ' ':re += "%20";break;
//                default:re += c;
//            }
//        }
//        return re;
//    }
//};

//原位置换法
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(' ' == s[i]){
                s += "  ";  //加两个空格，算上当前空格刚好3个位置放下%20
            }
        }
        for(int j = s.length() - 1, i = len - 1; j >= 0 && i >= 0; i--){
            if(' ' == s[i]){
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }else   s[j--] = s[i];
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
