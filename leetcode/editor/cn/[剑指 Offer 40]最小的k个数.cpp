//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法 
// 👍 256 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    //sort
//    vector<int> getLeastNumbers(vector<int>& arr, int k) {
//        sort(arr.begin(), arr.end());
//        return vector<int>(arr.begin(), arr.begin()+k);
//    }
    //堆
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() == k) return arr;
        //priority_queue内部实现为堆，greater<int>为自动升序，less<int>为自动降序
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i:arr)  q.push(i);
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
