```
class Solution {
public:
    string addBinary(string a, string b) {
        int a1 = a.size();
        int b1 = b.size();
        while(a1 > b1){ // 如果b的二进制小于a的二进制就对其补零
            b = '0' + b;
            b1++;
        }
        while(b1 > a1){//同理
            a = '0' + a;
            a1++;
        }
        for(int i = a1-1; i>0; i--){
            a[i]+= b[i]-'0';
            if(a[i]>='2'){
                a[i] = (a[i]-'0') % 2 +'0' ;
                //为了把本位的数字变成字符所以需要+‘0’，如果理解的不是很深刻 这行可以分类讨论
            /*  if(a[i]=='2'){
                a[i]='0';
                a[i-1]=a[i-1]+1;
            }
            else if(a[i]=='3'){
                a[i]='1';
                a[i-1]=a[i-1]+1;
            }
            */
                a[i-1]++;
            }
        }
        a[0] = a[0]-'0' + b[0]; //零位相加
        if(a[0] >= '2'){//为防止越界 对零位进行特殊讨论
            a[0] = (a[0]-'0') % 2 +'0';
            a = '1' + a;
        }
        return a;
    }
};
```
