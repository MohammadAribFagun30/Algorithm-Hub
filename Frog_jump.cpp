#include <bits/stdc++.h>
using namespace std;

int minCost( vector<int> &h)
{
    int n = h.size();

    if(n==1) return 0;

    vector<int>dp(n);

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i=2; i<n; i++)
    {
        int jump1 = dp[i-1] + abs( h[i] - h[i-1] );
        int jump2 = dp[i-2] + abs( h[i] - h[i-2] );
        
        dp[i] = min(jump1, jump2);
    }
    return dp[n-1];

}
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int> h(n);
    
    for(int i=0; i<n; i++)
    {
        cin>>h[i];
    }


    cout << minCost(h) << endl;

    return 0;
}