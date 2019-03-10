#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[11];
const double mon=82.3;
int main(){
    for(int i=0;i<=35;i++){
        double y=(mon-2.3*i)/1.9;
        if(i>=y)continue;
        if(fabs(y-(int)y)<eps)cout<<i<<endl;
    }
    return 0;
}
