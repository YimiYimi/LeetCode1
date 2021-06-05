//
// Created by USER on 2021/4/19.
//
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int> > map(m, vector<int>(n, 0));
        int num = 0, step, iStep, jStep;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                step = 0;
                iStep = i;
                jStep = j;
                while(iStep > 0 || jStep > 0){
                    step += iStep%10;
                    iStep /= 10;
                    step += jStep%10;
                    jStep /= 10;
                }
                if(step <= k){
                    num++;
                    map[i][j] = 1;
                }
            }
        }
        return num;
    }
};
int main(){
    Solution so;
    vector<int> numbers = {10,10,10,10,10,1,10};
    cout << so.movingCount(16,8,4);
}

