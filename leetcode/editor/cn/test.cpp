//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>
#include <valarray>

using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        int num = pow(10, n);
        vector<int> re;
        for(int i = 1; i < num; i++){
            re.push_back(i);
        }
        return re;
    }
    void printNumbers2(int n) {
        string s = "0";
        while(s.size() <= n){
            cout << s << endl;
            int i = s.size()-1;
            while(i >= 0 && s[i] == '9')    s[i--] = '0';
            if(i < 0)   s = "1" + s;
            else    s[i] += 1;
        }
    }
};
int main(){
    Solution so;
    vector<int> numbers = {10,10,10,10,10,1,10};
    so.printNumbers2(6);
}

