#include <bits/stdc++.h>
using namespace std;

 int change(int amount, vector<int>& coins) {

    vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];

 }


int main() {
    int amount , size;

    cin>>amount>>size;

    vector<int> coins(size);

    for(int i=0; i<size; i++)
    {
        cin>>coins[i];
    }

    cout<<change(amount,coins)<<endl;

    return 0;
}