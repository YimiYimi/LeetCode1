//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> re;
        while(head != NULL){
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()){
            re.push_back(s.top());
            s.pop();
        }
        return re;
    }
};
int main(){
    Solution so;
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);

    vector<int>re = so.reversePrint(head);
    for(int r:re)   cout << r;
}

