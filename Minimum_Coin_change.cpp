#include <bits/stdc++.h>
using namespace std;

// can take same coin more than one time

// Top-Down DP (Memoization)


const int INF = 1e9;
vector<int> coin, memo;

// fewest coins needed to make amt (INF if impossible)
int minCoins(int amt) {
    if (amt == 0) return 0;
    if (memo[amt] != -1) return memo[amt];

    int best = INF;

    for (int c : coin)
        if (c <= amt)
            best = min(best, 1 + minCoins(amt - c));

    return memo[amt] = best;
}

int main() {
    coin = {1, 2, 5};
    int amount = 11;

    memo.assign(amount + 1, -1);

    int ans = minCoins(amount);

    cout << (ans >= INF ? -1 : ans) << "\n";  // 3
}





// Bottom-Up DP (Tabulation)

// int coinChange(vector<int> &coins, int amount)
// {
//     vector<int> dp(amount + 1, amount + 1);

//     dp[0] = 0;

//     for (int i = 1; i <= amount; i++) // The outer loop (i) checks every amount from 1 to 11
//     {
//         for (int j = 0; j < coins.size(); j++) // The inner loop (j) tries each coin: 1, 2, and 5.
//         {
//             if (coins[j] <= i) // coins[j] <= i makes sure the coin is not larger than the amount.
//             {
//                 dp[i] = min(dp[i], 1 + dp[i - coins[j]]); // 1 + dp[i - coins[j]] means: use one coin now,
//                                              // then add the minimum coins needed for the remaining amount.
//             }
//         }
//     }

//     if (dp[amount] == amount + 1)
//     {
//         return -1;
//     }

//     return dp[amount];
// }

// int main()
// {
//     int n,amount;

//     cin>>n>>amount;

//     vector<int> coins(n);

//     for(int i=0; i<n; i++)
//     {
//         cin>>coins[i];
//     }


//     cout << coinChange(coins, amount) << endl;
// }