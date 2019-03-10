#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
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
void solve(){
    get_prime();
    for(int i=0;i<prim.size();i++){
        for(int k=2;k<1000;k++){
            int sum=1;
            int num=prim[i];
            for(int j=1;j<10;j++){
                if(!vis[num+k]){
                    sum++;
                    num=num+k;
                }
            }
            if(sum==10){
                cout<<prim[i]<<" "<<k<<endl;
                return;
            }
        }
    }
}
int main(){
    solve();
    //cout<<sum<<endl;
    return 0;
}
