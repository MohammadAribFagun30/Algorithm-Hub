#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> wt, val;
vector<vector<int>> memo;

// maximum value from items i..n-1 with capacity cap
int knap(int i, int cap) {
    if (cap == 0 || i == n) return 0;

    if (memo[i][cap] != -1)
        return memo[i][cap];

    int skip = knap(i + 1, cap);

    // skip item i

    int take = 0;

    if (wt[i] <= cap)
        take = val[i] + knap(i + 1, cap - wt[i]);

    // take item i once

    return memo[i][cap] = max(skip, take);
}

int main() {
    wt = {2, 3, 4};
    val = {4, 5, 7};

    n = wt.size();
    W = 8;

    memo.assign(n, vector<int>(W + 1, -1));

    cout << knap(0, W) << "\n";  // 12
}