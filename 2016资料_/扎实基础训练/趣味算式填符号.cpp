#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[11];
const double mon=82.3;
char ans[30];
map<string,int>ma;
//re:��һ������
//sum:Ŀǰ��ֵ�ĺ�
//retan:��ǰ������ֵ�����确123���ᾭ����12��
//flag:��ǰ���������ķ���+����1 -����0
//cur:���ŵ�λ��
void dfs(int re,int sum,int retan,int flag,int cur){
    if(re>=9){
        if(sum==110){//ֻ�ܳ���ɸѡ
            string s;
            for(int i=1;i<cur;i++){
                s+=ans[i];
                if(ans[i]=='9')break;
            }
            s+='=';
            ma[s]=0;
        }
        return;
    }
    ans[cur]=re+1+'0';
    int retan1=retan*10+re+1;
    dfs(re+1,sum,retan1,flag,cur+1);//�����12->123�ν���ȥ3�Ĺ���
    if(flag){//+�趨
        ans[cur+1]='+';
        dfs(re+1,sum+retan1,0,1,cur+2);
        ans[cur+1]='-';
        dfs(re+1,sum+retan1,0,0,cur+2);
    }
    else {//-�趨
        ans[cur+1]='+';
        dfs(re+1,sum-retan1,0,1,cur+2);
        ans[cur+1]='-';
        dfs(re+1,sum-retan1,0,0,cur+2);
    }
}
int check(string s){
    int sum=0;
    bool f=1;
    int temp=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>'0'&&s[i]<='9')temp=temp*10+(s[i]-'0');
        else {
            if(f)sum+=temp;
            else sum-=temp;
            temp=0;
            if(s[i]=='+')f=1;
            else if(s[i]=='-')f=0;
            else break;
        }
    }
    return sum;
}
int main(){
    ans[0]='+';
    int flag=1;
    dfs(0,0,0,flag,1);
    int num=0;
    for(auto it:ma){
        it.second=check(it.first);
        if(it.second==110){
            cout<<it.first<<it.second<<endl;
            num++;
        }
    }
    cout<<"The numble of available status:"<<num<<endl;
    return 0;
}
