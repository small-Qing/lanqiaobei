
#include<bits/stdc++.h>



using namespace std;

const int maxn = 1e2+5;

const int maxm = 1e5+5;

int dp[maxm],a[maxn];

int n;

int main()

{

    while(~scanf("%d",&n))

    {

        scanf("%d",&a[1]);

        int gcd = a[1];

        memset(dp,0,sizeof dp);

        for(int i = 2;i <= n;++i)

        {

            scanf("%d",&a[i]);

            gcd = __gcd(gcd,a[i]);

        }

        if(gcd != 1)

        {

            puts("INF");

            continue;

        }

        dp[0] = 1;

        for(int i = 1;i <= n;++i)

        {

            for(int j = a[i];j < maxm;++j)

                dp[j] = max(dp[j],dp[j-a[i]]);

        }

        int ans = 0;

        for(int i = 0;i < maxm;++i)

            if(!dp[i]) ans++;

        printf("%d\n",ans);

    }

    return 0;

}
