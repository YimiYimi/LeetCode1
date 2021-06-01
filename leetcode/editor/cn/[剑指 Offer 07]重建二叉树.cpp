//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归 
// 👍 460 👎 0


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
// //递归法
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* myTree(vector<int>& preorder, vector<int>& inorder, int preorder_left
                     , int preorder_right, int inorder_left, int inorder_right){
        if(preorder_left > preorder_right)  return nullptr;
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];
        int size_left_subtree = inorder_root - inorder_left;
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        root->left = myTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree
                            , inorder_left, inorder_root - 1);
        root->right = myTree(preorder, inorder, preorder_left + 1 + size_left_subtree, preorder_right
                             , inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return myTree(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
    }
};
//迭代法 （存疑）
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        if(preorder.empty())    return nullptr;
//        stack<TreeNode*> s;
//        TreeNode* root = new TreeNode(preorder[0]);
//        s.push(root);
//        int inorder_index = 0;
//        for(int i = 0; i < preorder.size(); i++){
//            TreeNode* node;
//            if(!s.empty() && s.top()->val != inorder[inorder_index]){
//                node = s.top();
//                node->left = new TreeNode(preorder[i]);
//                s.push(node->left);
//            }else{
//                while(!s.empty() && s.top()->val == inorder[inorder_index]){
//                    s.pop();
//                    inorder_index++;
//                }
//                node = s.top();
//                node->right = new TreeNode(preorder[i]);
//                s.push(node->right);
//            }
//        }
//        return root;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
