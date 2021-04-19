//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 数学 字符串 
// 👍 599 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include<iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int bit = 0, i, tmp;
        vector<int> r;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(i = 0; i < a.length() && i < b.length(); i++){
            tmp = (bit + (a[i] - '0') + (b[i] - '0')) / 2;
            r.push_back((bit + (a[i] - '0') + (b[i] - '0')) % 2);
            bit = tmp;
        }
        while(i < a.length()){
            tmp = (bit + (a[i] - '0')) / 2;
            r.push_back((bit + (a[i] - '0') + (b[i] - '0')) % 2);
            bit = tmp;
            i++;
        }
        while(i < b.length()){
            tmp = (bit + (b[i] - '0')) / 2;
            r.push_back((bit + (a[i] - '0') + (b[i] - '0')) % 2);
            bit = tmp;
            i++;
        }
        stringstream ss;
        copy(r.rend(), r.rbegin(), ostream_iterator<int>(ss, ""));
        cout << ss.str();
        return ss.str();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
