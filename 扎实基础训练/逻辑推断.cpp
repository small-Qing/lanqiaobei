#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[11];
bool judge(){
    if(vis[0]&&!vis[1])return false;
    if(!vis[2]&&vis[3])return false;
    if(vis[0]+vis[2]>1)return false;
    if(vis[1]+vis[3]!=1)return false;
    if(vis[3]+vis[4]+vis[5]+vis[6]+vis[7]<2)return false;
    if(vis[2]!=vis[6])return false;
    if(vis[2]+vis[4]+vis[6]+vis[8]>2)return false;
    if(vis[4]&&!(vis[5]&&vis[6]))return false;
    if(vis[5]&&(vis[6]||vis[7]))return false;
    if(!vis[8]&&!vis[9]&&!vis[7])return false;
    return true;
}
int main(){
    for(int i=0;i<1024;i++){
        int temp=i;
        for(int j=9;j>=0;j--){
            vis[j]=temp%2;
            temp=temp/2;
        }
        if(judge()){
            //printf("Yes\t");
            for(int j=0;j<10;j++){
                if(vis[j])printf("%c",('A'+j));
            }
            printf("\n");
        }
    }
    return 0;
}
