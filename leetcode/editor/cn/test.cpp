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
#include <cstring>

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
    char firstUniqChar(string s) {
        char res;
        res = ' ';
        map<char, int> m;
        for(int i = s.length()-1; i >= 0; i--){
            char c = s[i];
            if(m.find(c)!=m.end() && res == c) res = ' ';
            else if(m.find(c)==m.end()) res = c;
            m[c]++;
        }
        return res;
    }
};
int main(){
    Solution so;
    cout << so.firstUniqChar("dddccdbba");
}

