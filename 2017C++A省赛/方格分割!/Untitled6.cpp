#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=3e9+7;
const int maxn=100005;
vector<int>prim;
bool not_prim[maxn];
void get_prime(){
    mem(not_prim,0);
    not_prim[1]=1;//not_prime
    for(int i=2;i<maxn;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(int j=0;j<prim.size()&&prim[j]*i<maxn;j++){
            int h=prim[j]*i;
            not_prim[h]=1;
            if(i%prim[j]==0)break;
        }
    }
}
int sum=0;
bool vis[10][10];
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
///�����ǽ������Ǳ�Ŵ������Ӳ��Ǳ��
void dfs(int x,int y){
    if(x==0||y==0||x==6||y==6){//���ߵ��߽��û������ƽ�Ƶı�Ҫ�ˣ��Ը�����������Ӱ��
        sum++;
        return;///��������ݹ飡������
    }
    for(int i=0;i<4;i++){
        int xx=x+d[i][0];
        int yy=y+d[i][1];
        if(!vis[xx][yy]){
            vis[xx][yy]=1;
            vis[6-xx][6-yy]=1;
            dfs(xx,yy);
            vis[xx][yy]=0;
            vis[6-xx][6-yy]=0;
        }
    }
}
int main(){
    sum=0;
    mem(vis,0);
    vis[3][3]=1;
    dfs(3,3);
    cout<<sum/4<<endl;//��ת�Գ�����һ�ַ�����4�������
    return 0;
}
