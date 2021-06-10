//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
// Related Topics 数组 
// 👍 255 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
////普通解法
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        vector<int> res;
//        if(matrix.empty()) return res;
//        vector<vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
//        vector<pair<int, int> > direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//        int k = 0, i = 0, j = 0;
//        while(res.size() < matrix.size()*matrix[0].size()){
//            res.push_back(matrix[i][j]);
//            visited[i][j] = true;
//            if(i+direct[k].first < 0
//               || j+direct[k].second < 0
//               || i+direct[k].first >= matrix.size()
//               || j+direct[k].second >= matrix[0].size()
//               || visited[i+direct[k].first][j+direct[k].second]){
//                k = (k+1)%4;
//            }
//            i += direct[k].first;
//            j += direct[k].second;
//        }
//        return res;
//    }
//};
//优雅端指针
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())  return {};
        vector<int> res;
        int rl = 0, rh = matrix.size()-1, cl = 0, ch = matrix[0].size()-1;
        while(1){
            for(int i = cl; i <= ch; i++)   res.push_back(matrix[rl][i]);   //从左到右
            if(++rl > rh)   break;
            for(int i = rl; i <= rh; i++)   res.push_back(matrix[i][ch]);   //从上到下
            if(--ch < cl)   break;
            for(int i = ch; i >= cl; i--)   res.push_back(matrix[rh][i]);   //从右到左
            if(--rh < rl)   break;
            for(int i = rh; i >= rl; i--)   res.push_back(matrix[i][cl]);   //从下到上
            if(++cl > ch)   break;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
