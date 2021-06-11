//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 
// 👍 102 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root)    que.push(root);
        vector<int> tmp;
        while(!que.empty()){
            TreeNode* tree;
            int size = que.size();
            while(size--){
                tree = que.front();
                que.pop();
                if(res.size()%2)    tmp.insert(tmp.begin(), tree->val);
                else    tmp.push_back(tree->val);
                if(tree->left)  que.push(tree->left);
                if(tree->right) que.push(tree->right);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
