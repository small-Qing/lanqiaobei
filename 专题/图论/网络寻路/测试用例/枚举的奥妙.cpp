#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//不能mem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=10005;//最好数量范围大一点；1e4+5  &&  long long
vector<int>ed[maxn];//存储每个点的邻接点
ll sum=0;
struct node{
    ll from,to;
    node(int x,int y):from(x),to(y){}
    node(){}
};
vector<node>edges;
int main(){
    freopen("in5.txt","r",stdin);
    ll n,m,a,b;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%lld%lld",&a,&b);
        ed[a].push_back(b);
        ed[b].push_back(a);
        edges.push_back(node(a,b));
    }
    ll ans=0;
    for(int i=0;i<edges.size();i++){
        int from=edges[i].from;
        int to=edges[i].to;
        ans+=(ed[from].size()-1)*(ed[to].size()-1);
    }
    cout<<ans*2LL<<endl;
    return 0;
}
