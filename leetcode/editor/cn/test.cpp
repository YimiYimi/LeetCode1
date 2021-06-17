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
#include <sstream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return NULL;
        queue<TreeNode*> que;
        string s = "[";
        que.push(root);
        while(!que.empty()){
            s += ",";
            TreeNode* node = que.front();
            que.pop();
            if(!node){
                s += node->val;
                que.push(node->left);
                que.push(node->right);
            }else{
                s += "null";
            }
        }
        s += "]";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        string tmp;
        istringstream iss;
        while(getline(iss, tmp, ','))
            vec.push_back(tmp);
        TreeNode* node;
        return node;
    }
};
int main(){
    Codec so;
}

