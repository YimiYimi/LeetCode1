//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 
//
// 
//
// 示例: 
//
// MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.min();   --> 返回 -2.
// 
//
// 
//
// 提示： 
//
// 
// 各函数的调用总次数不超过 20000 次 
// 
//
// 
//
// 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/ 
// Related Topics 栈 设计 
// 👍 133 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
////map
//class MinStack {
//private:
//    stack<int> stk;
//    map<int, int> m;
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//        stk = stack<int>();
//    }
//
//    void push(int x) {
//        stk.push(x);
//        m[x]++;
//    }
//
//    void pop() {
//        m[stk.top()]--;
//        if(m[stk.top()]<=0)
//            m.erase(stk.top());
//        stk.pop();
//    }
//
//    int top() {
//        return stk.top();
//    }
//
//    int min() {
//        int res = m.begin()->first;
//        return res;
//    }
//};
//双栈
class MinStack {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk1.push(x);
        if(stk2.empty())    stk2.push(x);
        else if(x <= stk2.top()) stk2.push(x);
    }

    void pop() {
        if(stk2.top() == stk1.top())    stk2.pop();
        stk1.pop();
    }

    int top() {
        return stk1.top();
    }

    int min() {
        return stk2.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
//leetcode submit region end(Prohibit modification and deletion)
