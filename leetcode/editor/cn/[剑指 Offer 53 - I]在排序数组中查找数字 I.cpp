//统计一个数字在排序数组中出现的次数。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
// Related Topics 数组 二分查找 
// 👍 145 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return border(nums, target) - border(nums, target-1);   //target 与 target-1不能改+
    }
    int border(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        while(l<=r){    //别漏等号
            int m = l + (r-l)/2;
            if(nums[m] <= target){  //别漏等号
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
