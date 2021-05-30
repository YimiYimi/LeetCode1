//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个
//整数，判断数组中是否含有该整数。 
//
// 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// 
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
//
// 
//
// 限制： 
//
// 0 <= n <= 1000 
//
// 0 <= m <= 1000 
//
// 
//
// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 
// Related Topics 数组 双指针 
// 👍 336 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int r1, r2, c1, c2;
        r1 = c1 = 0;
        r2 = matrix.size() - 1;
        c2 = matrix[0].size() - 1;
        while(r1 < r2 && c1 < c2){
            if(matrix[r2][c1] == target)    return true;
            if(matrix[r1][c2] == target)    return true;
            if(matrix[r2][c1] > target){
                r2--;
            }else{
                c1++;
            }
            if(matrix[r1][c2] > target){
                c2--;
            }else{
                r1++;
            }
        }
        while(r1 <= r2){
            if(matrix[r1][c1] == target)    return true;
            else    r1++;
        }
        while(c1 <= c2){
            if(matrix[r2][c1] == target)    return true;
            else    c1++;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
