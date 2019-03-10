#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=1005;
int main(){
    freopen("1.txt","r",stdin);
    double sum=0,a,b;
    while(cin>>a>>b){
        sum+=a*b/100.0;
    }
    cout<<sum<<endl;
    return 0;
}
