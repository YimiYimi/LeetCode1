//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 深度优先搜索 
// 👍 327 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    //注意：board要用&才对
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        //检测越界、不匹配字符
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
        if(k == word.size() - 1)    return true;
        vector<vector<int> > direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        char temp = board[i][j];
        //标记已走过格子
        board[i][j] = ' ';
        for(int d = 0; d < 4; d++){
            if(dfs(board, word, i+direct[d][0], j+direct[d][1], k+1))   return true;
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i, j, 0))   return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
