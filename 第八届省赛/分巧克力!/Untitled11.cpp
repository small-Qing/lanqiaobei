#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=3e9+7;
const int maxn=1e5+7;
//一开始以为dp,后来发现数据范围太大了
//看题解介绍是二分模板题。。。
//二分边长，然后去判断数量够不够
struct node{
    int h,w;
    node(int H,int W):h(H),w(W){}
    node(){}
};
node a[maxn];
int n,k;
bool judge(int m){
    int sum=0;
    for(int i=0;i<n;i++){
        int x=a[i].h/m;
        int y=a[i].w/m;
        sum+=x*y;
    }
    return sum>=k;
}
int solve(){
    int l=1,r=100001,mid;
    int ans=-1;
    while(l<r){
        mid=(l+r)/2;
        if(judge(mid)){
            ans=mid;
            //cout<<"mid="<<mid<<endl;
            l=mid+1;
        }
        else r=mid;
    }
    return ans;
}
int main(){
    freopen("1.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i].h>>a[i].w;
    }
    cout<<solve()<<endl;
    return 0;
}
