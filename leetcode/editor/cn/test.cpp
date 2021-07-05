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
#include<unordered_set>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> se;
        while(!headA){
            se.insert(headA);
            headA = headA->next;
        }
        while(!headB){
            if(se.find(headB) != se.end())  return headB;
            headB = headB->next;
        }
        return NULL;
    }
    void add(ListNode* h, vector<int> v){
        ListNode* l = h;
        for(int x:v){
            l->val = x;
            l->next = new ListNode();
            l = l->next;
        }
    }
};

int main(){
    Solution so;
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    ListNode* h1, *h2, *l1, *l2;
    vector<int> v1 = {4, 1, 8, 4, 5}, v2 = {5, 0, 1, 8, 4, 5};
    so.add(h1, v1);
    so.add(h2, v2);
//    h1->next = new ListNode(3);
//    h2 = h1 = h1->next;
    cout << so.getIntersectionNode(h1, h2);
}

