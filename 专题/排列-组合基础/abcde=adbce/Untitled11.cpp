#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//²»ÄÜmem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int sum=0;
int a[5];
int vis[20];
bool judge(){
    int x=a[0]*10+a[1];
    int y=a[2]*100+a[3]*10+a[4];
    int n=a[0]*100+a[3]*10+a[1];
    int m=a[2]*10+a[4];
    if(x*y==n*m)return true;
    return false;
}
void dfs(int cur){
    if(cur>=5){
        if(cur==5){
            if(judge())sum++;
            else return ;
        }
        else return;
    }
    for(int i=1;i<=9;i++){
        if(!vis[i]){
            a[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main(){
    sum=0;
    mem(vis,0);
    dfs(0);
    cout<<sum<<endl;
    return 0;
}
