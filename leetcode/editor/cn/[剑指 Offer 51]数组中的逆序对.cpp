//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 
// 👍 449 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size()-1);
    }
    int merge(vector<int>& nums, int l, int r){
        if(l >= r)  return 0;
        vector<int> tmp;
        int i = l, m = l + (r-l)/2, j = m+1, k, res;
        res = merge(nums, l, m) + merge(nums, m+1, r);
        for(k = l; k <= r; k++){    //不可以全部nums复制进来，不然会超时
            tmp.push_back(nums[k]);
        }
        k = l;
        while(i <= m && j <= r){
            if(tmp[i-l] <= tmp[j-l]){
                nums[k++] = tmp[(i++)-l];
            }else{
                nums[k++] = tmp[(j++)-l];
                res += m - i + 1;
            }
        }
        while(i <= m)   nums[k++] = tmp[(i++)-l];
        while(j <= r)   nums[k++] = tmp[(j++)-l];
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
