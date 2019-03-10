#include<bits/stdc++.h>
using namespace std;
const double eps=3e-8;
int main(){
    for(int i=20;i>=1;i--){
        for(int j=i-1;j>=1;j--){
            for(int k=j-1;k>=1;k--){
                for(int p=k-1;p>=1;p--){
                    double ans=1.0/i+1.0/j+1.0/k+1.0/p;
                    if(fabs(ans-1.0)<eps)printf("%d %d %d %d 0\n",i,j,k,p);
                }
            }
        }
    }
    return 0;
}
