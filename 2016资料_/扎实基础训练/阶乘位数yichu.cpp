#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
long long  big[maxn+2];
int f(int m)
{
    mem(big,0);
    big[0]=1;
	for(int i=2;i<=m;i++){
        for(int j=0;j<=maxn;j++){
            big[j]*=i;
        }
        for(int j=0;j<=maxn;j++){
            if(big[j]>9){
                big[i+1]+=big[i]/mod;
                big[i]=big[i]%mod;
            }
        }
	}
	bool t=true;
	int tou=0;
	for(int i=maxn;i>=0;i--){
        if(t&&big[i]==0)continue;
        else {
            t=false;
            tou=i;
            break;
        }
	}
	cout<<tou<<endl;
    int ans=0;
	while(1){
        for(int i=tou;i>=0;i--){
            if(i>0)big[i-1]+=big[i]%2*10;
            if(big[i]>=2)big[i]/=2;
        }
        ans++;
        if(big[0]<=1){
            if(big[0]==1)ans++;
            break;
        }
	}
	cout<<ans<<endl;
}
int main(){
    f(9999);
    return 0;
}
