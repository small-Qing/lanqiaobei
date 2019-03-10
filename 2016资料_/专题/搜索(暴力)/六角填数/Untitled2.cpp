#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//²»ÄÜmem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int sum=0;
bool vis[20];
int a[20];
void dfs(int cur){
   if(cur>=12){
        int b=a[1]+a[2]+a[3]+a[4];
        int c=a[4]+a[5]+a[6]+a[7];
        int d=a[7]+a[8]+a[9]+a[1];
        int e=a[10]+a[2]+a[9]+a[11];
        int f=a[10]+a[3]+a[5]+a[12];
        int g=a[11]+a[8]+a[6]+a[12];
        if(b==c&&b==d&&b==e&&b==f&&b==g)cout<<a[3]<<endl;
        else return;

   }
   if(cur==1||cur==10||cur==12)dfs(cur+1);
   else{
       for(int i=1;i<=12;i++){
            if(!vis[i]){
                a[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
       }
   }

}
int main(){
    mem(a,0);
    mem(vis,0);
    a[1]=1;
    a[10]=8;
    a[12]=3;
    vis[1]=1;
    vis[3]=1;
    vis[8]=1;
    dfs(1);
    //cout<<a[3]<<endl;
    return 0;
}
