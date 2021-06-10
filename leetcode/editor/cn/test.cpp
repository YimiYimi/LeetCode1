//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>
#include <valarray>
#include<stack>
#include<set>
#include<map>
#include<queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
private:
    vector<int> res;
    queue<TreeNode*> que;
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root){
            que.push(root);
        }
        else    return {};
        while(!que.empty()){
            TreeNode *q = que.front();
            res.push_back(q->val);
            if(q->left)   que.push(q->left);
            if(q->right)   que.push(q->right);
            que.pop();
        }
        return res;
    }
};
int main(){
    Solution so;
    vector<int> res = so.levelOrder(new TreeNode(3,new TreeNode(9,NULL,NULL),
                                                 new TreeNode(20,new TreeNode(15,NULL,NULL),
                                                              new TreeNode(7,NULL,NULL))));
    for(int i:res){
        cout << i << " " << endl;
    }
}

