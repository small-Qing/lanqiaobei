#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))//����mem(double)
#define ll long long
const double eps=3e-8;
const int mod=10;
const int maxn=10005;//���������Χ��һ�㣻1e4+5  &&  long long
vector<int>ed[maxn];//�洢ÿ������ڽӵ�
ll edge[maxn][maxn];//�洢ÿ����ֵ
ll dis[maxn];//�洢bfs�д�node�㿪ʼ��·����
ll sum=0;
int bfs(int node){
    mem(dis,-1);
    queue<int>que;
    que.push(node);
    int ans=node;
    dis[node]=0;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(int i=0;i<ed[now].size();i++){
            int temp=ed[now][i];
            if(dis[temp]<0){
                dis[temp]=dis[now]+edge[now][temp];
                if(dis[temp]>sum){
                    ans=temp;
                    sum=dis[temp];
                }
                que.push(temp);
            }
        }
    }
    return ans;
}
int main(){
    freopen("in4.txt","r",stdin);
    int n,a,b;
    ll c;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%lld",&a,&b,&c);
        ed[a].push_back(b);
        ed[b].push_back(a);
        edge[a][b]=c;
        edge[b][a]=c;
    }
    int starta=1;
    int endnode,startnode;
    sum=0;
    endnode=bfs(starta);
    sum=0;
    startnode=bfs(endnode);
    ///cout<<endnode<<" "<<startnode<<" "<<sum<<endl;
    double ans=sum*(sum+1.0)/2+10.0*sum;
    printf("%.0f\n",ans);
}
