//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 链表 
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// //数组法：两端交换
//class Solution {
//public:
//    vector<int> reversePrint(ListNode* head) {
//        vector<int> re;
//        while(head != NULL){
//            re.push_back(head->val);
//            head = head->next;
//        }
//        for(int i = 0, j = re.size()-1; i < j; i++, j--){
//            int temp;
//            temp = re[i];
//            re[i] = re[j];
//            re[j] = temp;
//        }
//        return re;
//    }
//};
//栈法
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
//leetcode submit region end(Prohibit modification and deletion)
