
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
char s[maxn][maxn];
void dfs(int x,int y,char cur){
    if(cur=='8'){
        sum++;
    }
    if(s[x+1][y]==cur+1)dfs(x+1,y,cur+1);
    if(s[x][y+1]==cur+1)dfs(x,y+1,cur+1);
}
int main(){
    for(int i=0;i<4;i++)scanf("%s",s[i]);
    sum=0;
    dfs(0,0,'1');
    cout<<sum<<endl;
    return 0;
}
