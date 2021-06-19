//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法 
// 👍 290 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string s, int pos){
        if(pos == s.size()-1){
            res.push_back(s);
            return;
        }
        set<int> se;
        for(int i = pos; i < s.size(); i++){
            //之前已交换过该字母，无需重复交换，剪枝
            if(se.find(s[i]) != se.end())   continue;
            se.insert(s[i]);
            swap(s[pos], s[i]);
            dfs(s, pos+1);
            swap(s[pos], s[i]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
