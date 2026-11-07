// Recurrence 

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> price, memo;

// maximum price obtainable from a rod of length len
int rod(int len) {
    if (len == 0) return 0;

    if (memo[len] != -1)
        return memo[len];

    int best = 0;

    for (int i = 1; i <= len; i++)
        best = max(best, price[i - 1] + rod(len - i));

    return memo[len] = best;
}

int main() {
    price = {1, 5, 8, 9, 10, 17, 17, 20};

    n = price.size();
    memo.assign(n + 1, -1);

    cout << rod(n) << "\n";  // 22
}









// Bottom Up --> Tabulation
#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& cuts) {
    vector<int> c = cuts;

    c.push_back(0);
    c.push_back(n);

    sort(c.begin(), c.end());

    int m = c.size();

    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int len = 2; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            int j = i + len;
            int best = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                best = min(best, dp[i][k] + dp[k][j]);
            }

                dp[i][j] = best + c[j] - c[i];
        }
    }

    return dp[0][m - 1];
}

int main() {
    int n, size;
    cin >> n >> size;

    vector<int> ar(size);

    for (int i = 0; i < size; i++) {
        cin >> ar[i];
    }

    cout << minCost(n, ar) << endl;

    return 0;
}