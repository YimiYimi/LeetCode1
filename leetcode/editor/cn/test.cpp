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

class Solution {
public:
    int findNthDigit(int n) {
        string s;
        stringstream ss;
        for(int i = 0; i <= n; i++){
            string si;
            ss << i;
            ss >> si;
            s += si;
            ss.clear(); //不可少
            if(s.size() > n)   break;
        }
        return s[n]-'0';
    }
};
int main(){
    Solution so;
    cout << so.findNthDigit(1000000000);
}

