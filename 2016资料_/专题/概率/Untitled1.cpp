#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//不能mem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=10005;//最好数量范围大一点；1e4+5  &&  long long
vector<int>ed[maxn];//存储每个点的邻接点
bool vis[370];
int test(){
    mem(vis,0);
    int p;
    for(int i=0;i<50;i++){//50人中
        p=rand()%366;//伪随机数
        if(vis[p])return 1;
        vis[p]=1;
    }
    return 0;
}
int main(){
    int u=0;
    int mm=1e7;
    for(int i=0;i<mm;i++){
        u+=test();
    }
    cout<<u<<endl;
    cout<<u*100/(mm)<<endl;
    return 0;
}
