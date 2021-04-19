//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 0 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
// Related Topics 字符串 
// 👍 1568 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r;
        char c;
        if (strs.empty())	return r;
        for (int j = 0; j < strs[0].length(); j++) {
            c = strs[0].at(j);
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].length() || strs[0].at(j) != strs[i].at(j)) {
                    return r;
                }
            }
            r += c;
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
