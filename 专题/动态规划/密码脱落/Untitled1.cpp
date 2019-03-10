#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//²»ÄÜmem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int sum=0;
struct node{
    int x,y,rx,ry;
    node(int xx,int yy,int l,int r):x(xx),y(yy),rx(l),ry(r){}
    node(){}
};
char s[maxn],w[maxn];
int dp[maxn][maxn];
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)w[i]=s[n-1-i];
    mem(dp,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==w[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<n-dp[n][n]<<endl;
    cout<<gcd(10,28)<<endl;
    return 0;
}
