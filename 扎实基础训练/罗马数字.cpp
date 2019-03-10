#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[30];
string s;
int num[30];
map<char,int>val;
int main(){
    val['I']=1;
    val['V']=5;
    val['X']=10;
    val['L']=50;
    val['C']=100;
    val['D']=500;
    val['M']=1000;
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        mem(vis,0);
        int ans=0;
        int len=s.size();
        for(int i=0;i<len;i++){
            num[i]=val[s[i]];
        }
        for(int i=0;i<len;i++){
            if(num[i]>=num[i+1])ans+=num[i];//只需要看相邻两个的大小关系
            else ans-=num[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
