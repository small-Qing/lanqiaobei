#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn=105;
const int mod=maxn*maxn+20;
int a[maxn];
bool vis[maxn*(maxn+1)];
int main(){
    int n;
    cin>>n;
    int gcdd=0;
    mem(vis,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]=1;
        gcdd=__gcd(a[i],gcdd);
    }
    if(gcdd!=1)printf("INF\n");
    else{
        for(int i=0;i<n;i++){//ÍêÈ«±³°ü
            for(int j=0;j+a[i]<mod;j++){
                if(vis[j])vis[j+a[i]]=1;
            }
        }
        int ans=0;
        for(int j=mod-1;j>0;j--){
            if(!vis[j])ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
