//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
// 👍 293 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<bool> > visited;  //检测已走过的格子，不然会有问题
    int dfs(int i, int j, int m, int n, int k){
        //非法判定：出界；不符要求；已走过
        if(i<0||j<0||i>=m||j>=n||i/10+i%10+j/10+j%10>k||visited[i][j])    return 0;
        visited[i][j] = true;
        return 1+dfs(i+1,j,m,n,k)+dfs(i,j+1,m,n,k);
    }
public:
    int movingCount(int m, int n, int k) {
        visited = vector<vector<bool> >(m, vector<bool>(n,false));;
        return dfs(0, 0, m, n, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
