#include <bits/stdc++.h>
using namespace std;
int helper(int y,  vector<int> &dp)
{
    if(y==1 || y==2)
    {
        return y;
    }
    if(dp[y] != -1)
    {
        return dp[y];
    }
    return dp[y] = helper(y-1,dp) + helper(y-2,dp);
}

int clst(int x)
{
    vector<int>dp(x+1,-1);
    return helper(x,dp);
}

int main() {
    int n;
    cin>>n;
    cout<<clst(n)<<endl;

    return 0;
}