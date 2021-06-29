//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例: 
//
// s = "abaccdeff"
//返回 "b"
//
//s = "" 
//返回 " "
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 队列 哈希表 字符串 计数 
// 👍 107 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char firstUniqChar(string s) {
        map<char, int> m;
        for(char c:s)   m[c]++;
        for(char c:s){
            if(m[c] == 1)   return c;
        }
        return ' ';
    }
};
//leetcode submit region end(Prohibit modification and deletion)
