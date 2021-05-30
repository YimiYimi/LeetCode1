//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(' ' == s[i]){
                s += "  ";  //加两个空格，算上当前空格刚好3个位置放下%20
            }
        }
        for(int j = s.length() - 1, i = len - 1; j >= 0 && i >= 0; i--){
            if(' ' == s[i]){
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }else   s[j--] = s[i];
        }
        return s;
    }
};
int main(){
    Solution so;
    cout << so.replaceSpace("We are happy.");
}

