#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//²»ÄÜmem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int sum=0;
int a[20];
void dfs(int cur,int num){
    if(cur>13)return;//cur>13要返回！！！范围是[0,13]
    if(num>=13){
        if(num==13){
            sum++;
        }
        else return;//num>13要返回！！！
    }
    else{
        for(int i=0;i<=4;i++){
            a[cur]=i;
            dfs(cur+1,num+i);
        }
    }
}
int dp[20][20];//表示i种牌，j个牌的种类数量
int solve(){
    ///正常DP
    mem(dp,0);
    for(int i=0;i<5;i++)dp[1][i]=1;//只有一种牌的时候，怎么组合都是1
    for(int i=2;i<=13;i++){//其实和i没什么关系。。。（可以滚动数组）
        for(int j=0;j<=13;j++){
            dp[i][j]+=dp[i-1][j];//主要看j的坐标可以等于0(注意细节)   dp[i][j]==0
            if(j-1>=0)dp[i][j]+=dp[i-1][j-1];
            if(j-2>=0)dp[i][j]+=dp[i-1][j-2];
            if(j-3>=0)dp[i][j]+=dp[i-1][j-3];
            if(j-4>=0)dp[i][j]+=dp[i-1][j-4];
            //cout<<" "<<dp[i][j];
            //if(j==13)cout<<endl;
        }
    }
    ///滚动数组
    int d[2][20];
    mem(d,0);
    for(int j=0;j<5;j++)d[1][j]=1;
    int i=1;
    for(int k=2;k<=13;k++){
        i=k%2;
        for(int j=0;j<=13;j++){
            //int p=d[1-i][j];
            d[i][j]=d[1-i][j];//主要看j的坐标可以等于0(注意细节)   d[i][j]!=0
            if(j-1>=0)d[i][j]+=d[1-i][j-1];
            if(j-2>=0)d[i][j]+=d[1-i][j-2];
            if(j-3>=0)d[i][j]+=d[1-i][j-3];
            if(j-4>=0)d[i][j]+=d[1-i][j-4];
            //cout<<" "<<d[i][j];
            //if(j==13)cout<<endl;
        }
    }
    int ans=0;
    ans=d[1][13];//d[i][13];
    return ans;
}
int main(){
    sum=0;
    mem(a,0);
    //dfs(0,0);//0表示第一种牌
    sum=solve();
    cout<<sum<<endl;
    return 0;
}
