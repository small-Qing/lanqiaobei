#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=3e9+7;
const int maxn=100005;
vector<int>prim;
bool vis[maxn];
void get_prime(){
    mem(vis,0);
    vis[1]=1;//not_prime
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prim.push_back(i);
        }
        for(int j=0;j<prim.size()&&prim[j]*i<maxn;j++){
            int h=prim[j]*i;
            vis[h]=1;
            if(i%prim[j]==0)break;
        }
    }
}
double dp[40][40];
int main(){
    freopen("1.txt","r",stdin);
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++)dp[i][j]=0;
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=i;j++)cin>>dp[i][j];
    }
    for(int i=2;i<=30;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]+=dp[i-1][j-1]/2+dp[i-1][j]/2;
        }
    }
    double y=mod;
    double ma=0;
    for(int i=1;i<=30;i++){
        y=min(y,dp[30][i]);
        ma=max(ma,dp[30][i]);
    }
    cout<<y<<" "<<ma<<endl;
    double ans=ma*(2086458231.0/y);
    printf("%lf\n",ans);
    return 0;
}
