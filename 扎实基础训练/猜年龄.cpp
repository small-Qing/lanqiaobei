#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
bool vis[10];
int main(){
    for(int i=11;i<=45;i++){
        mem(vis,0);
        int iii=i*i*i;
        int iiii=iii*i;
        int j,temp;
        bool f=false;
        for(j=1;j<=4&&iii;j++){
            temp=iii%mod;
            iii/=mod;
            if(!vis[temp])vis[temp]=true;
            else {
                f=true;
                break;
            }
        }
        if(j<4||f)continue;
        for(j=1;j<=6&&iiii;j++){
            temp=iiii%mod;
            iiii/=mod;
            if(!vis[temp])vis[temp]=true;
            else {
                f=true;
                break;
            }
        }
        if(j<6||f)continue;
        printf("ans=%d %d %d\n",i,i*i*i,i*i*i*i);
    }
    return 0;
}
