#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//²»ÄÜmem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int sum=0;
int a[20];
bool vis[20];
bool judge(){
    if(abs(a[0]-a[1])==1)return false;
    if(abs(a[0]-a[4])==1)return false;
    if(abs(a[0]-a[3])==1)return false;
    if(abs(a[0]-a[5])==1)return false;
    //if(abs(a[0]-a[4])==1)return false;
    if(abs(a[1]-a[2])==1)return false;
    if(abs(a[1]-a[5])==1)return false;
    if(abs(a[1]-a[4])==1)return false;
    if(abs(a[1]-a[6])==1)return false;

    if(abs(a[2]-a[6])==1)return false;
    if(abs(a[2]-a[5])==1)return false;

    if(abs(a[3]-a[4])==1)return false;
    if(abs(a[3]-a[7])==1)return false;
    if(abs(a[3]-a[8])==1)return false;

    if(abs(a[4]-a[8])==1)return false;
    if(abs(a[4]-a[7])==1)return false;
    if(abs(a[4]-a[5])==1)return false;
    if(abs(a[4]-a[9])==1)return false;

    if(abs(a[5]-a[6])==1)return false;
    if(abs(a[5]-a[8])==1)return false;
    if(abs(a[5]-a[9])==1)return false;

    if(abs(a[6]-a[9])==1)return false;
    if(abs(a[7]-a[8])==1)return false;
    if(abs(a[9]-a[8])==1)return false;
    return true;
}
void dfs(int cur){
    if(cur>9){//cur要已经结束了
        if(judge())sum++;
    }
    for(int i=0;i<10;i++){
        if(!vis[i]){
            vis[i]=1;
            a[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main(){
    mem(vis,0);
    mem(a,0);
    sum=0;
    dfs(0);
    cout<<sum<<endl;
    return 0;
}
