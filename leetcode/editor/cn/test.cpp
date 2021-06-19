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
int main(){
    Codec so;
}

