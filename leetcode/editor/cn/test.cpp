//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size()-1, m;
        while(l < r){
            m = (l + r) / 2;
            if(numbers[m] < numbers[r]){
                r = m;
            }else if(numbers[m] > numbers[r]){
                l = m + 1;
            }else{
                r--;
            }
        }
        return numbers[l];
    }
};
int main(){
    Solution so;
    vector<int> numbers = {10,10,10,10,10,1,10};
    cout << so.minArray(numbers);
}

