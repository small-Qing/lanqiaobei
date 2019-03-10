#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int mod=10;
const int maxn=2e5;
bool vis[11];
const double mon=82.3;
char ans[30];
int main(){
    //97x-127y=1
    //min(x+y)
    int ans=1000;
    for(double x=0;x<1000;x++){
        double y=(97.0*x-1.0)/127.0;
        if(fabs(y-(int)y)<eps){
            cout<<x<<" "<<y<<endl;
            ans=min(ans,(int)(x+y));
        }
    }
    cout<<ans<<endl;
    return 0;
}
