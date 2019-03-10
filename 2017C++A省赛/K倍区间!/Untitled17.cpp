#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int maxn=100005;
int pre[maxn];
int cnt[maxn];
int n,k;
int a[maxn];
int main(){
    freopen("1.txt","r",stdin);
    cin>>n>>k;
    mem(pre,0);
    mem(cnt,0);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=(pre[i-1]+a[i])%k;
        sum+=cnt[pre[i]];
        cnt[pre[i]]++;
    }
    cout<<sum+cnt[0]<<endl;//要记得加上本身一个数字就能被整除的数
    return 0;
}
