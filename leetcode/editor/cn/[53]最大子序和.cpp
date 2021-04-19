//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：nums = [-1]
//输出：-1
// 
//
// 示例 5： 
//
// 
//输入：nums = [-100000]
//输出：-100000
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 104 
// -105 <= nums[i] <= 105 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 3147 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //O(n^2)
        // int r = nums[0], tmp;
        // for (int i = 0; i < nums.size(); i++) {
        //     tmp = 0;
        // 	for (int j = i; j < nums.size(); j++) {
        // 		tmp += nums[j];
        // 		if (tmp > r)	r = tmp;
        // 	}
        // }
        // return r;

        //贪心
        int cur, r;
        r = cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur + nums[i]);
            r = max(r, cur);
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
