#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int maxn=100005;

// 求x用10进制表示时的数位长度
int len(int x){
    if(x<10) return 1;
    return len(x/10)+1;
}
// 取x的第k位数字
int f(int x, int k){
    if(len(x)-k==0) return x%10;
    return f(x/10,k);
}
int main(){
    int x = 23574;
    printf("%d\n", f(x,3));
    return 0;
}
