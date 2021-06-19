//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 
//
// 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出: 2 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// 
// Related Topics 位运算 分治算法 
// 👍 165 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
////map
//    int majorityElement(vector<int>& nums) {
//        map<int, int> m;
//        int res;
//        for(int i:nums){
//            m[i]++;
//            if(m[i] > nums.size()/2){
//                res = i;
//                break;
//            }
//        }
//        return res;
//    }
////排序法
//    int majorityElement(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        return nums[nums.size()/2];
//    }
//极限一换一
    int majorityElement(vector<int>& nums) {
        int count = 0, res;
        for(int i:nums){
            if(!count){
                res = i;
                count++;
            }else{
                i == res ? count++:count--;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
