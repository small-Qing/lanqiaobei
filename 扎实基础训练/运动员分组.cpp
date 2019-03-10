#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[11];
const double mon=82.3;
int ans[30];
void p(int y){
    if(ans[y]==0)y--;
    sort(ans,ans+y+1);
    for(int i=y;i>=0;i--){
        cout<<ans[i]<<endl;
    }
}
int main(){
    int m;
    cin>>m;
    int x=m%8;
    int y=m/8;
    for(int i=0;i<y;i++)ans[i]=8;
    ans[y]=x;
    int dei=8-x;
    if(dei==0||x==0){
        p(y);
    }
    else {
        int maxcur=8;
        bool f=true;
        while(f){
            for(int i=0;i<y;i++){
                ans[y]++;
                ans[i]--;
                if(maxcur-ans[y]>0)dei=min(dei,maxcur-ans[y]);
                else {
                    f=false;
                }
            }
            if(f)maxcur--;
        }
        p(y);
    }
    return 0;
}
