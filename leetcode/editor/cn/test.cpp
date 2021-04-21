//
// Created by USER on 2021/4/19.
//
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int bit = 0, len;
        string r;
        len = max(a.length(), b.length());
        for(int i = 0; i < len; i++){
            bit += (i < a.length()) ? (a.at(a.length() - i - 1) - '0') : 0;
            bit += (i < b.length()) ? (b.at(b.length() - i - 1) - '0') : 0;
            r.insert(0, 1, char(bit%2 + (int)'0'));
//            r = (char)(bit%2 + (int)'0') + r;
            bit /= 2;
        }
        if(bit){
            r = '1' + r;
        }
        return r;
    }
};
int main(){
    Solution so;
    cout << so.addBinary("1010", "1011");
}

