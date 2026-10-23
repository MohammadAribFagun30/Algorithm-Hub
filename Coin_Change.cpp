#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) // The outer loop (i) checks every amount from 1 to 11
    {
        for (int j = 0; j < coins.size(); j++) // The inner loop (j) tries each coin: 1, 2, and 5.
        {
            if (coins[j] <= i) // coins[j] <= i makes sure the coin is not larger than the amount.
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]); // 1 + dp[i - coins[j]] means: use one coin now,
                                             // then add the minimum coins needed for the remaining amount.
            }
        }
    }

    if (dp[amount] == amount + 1)
    {
        return -1;
    }

    return dp[amount];
}

int main()
{
    int n,amount;

    cin>>n>>amount;

    vector<int> coins(n);

    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }


    cout << coinChange(coins, amount) << endl;
}