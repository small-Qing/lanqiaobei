#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
char vis[20];
string ans="";
void f(int m, int n,int mont,int cur){
    if(m==0&&n==0){
        for(int i=0;i<cur;i++)printf("%c",vis[i]);
        printf("\n");
        return;
    }
	if(m>0){
        vis[cur]='5';
        f(m-1,n,mont+5,cur+1);
	}
    if(n>0&&mont>=5){
        vis[cur]='1';
        f(m,n-1,mont-5,cur+1);
    }
}
int f(int m, int n)
{
	if(m < n) return 0;
	if(n==0) return 1;
	return  f(m-1,n)+f(m,n-1);
}
int main(){
    //for(int n=0;n<5;n++){
        //for(int m=n;m<8;m++){
            int m=3,n=3;
            printf("%d %d\n",m,n);
            f(m,n,0,0);
            //out<<<<endl;
        //}
    //}
    return 0;
}
