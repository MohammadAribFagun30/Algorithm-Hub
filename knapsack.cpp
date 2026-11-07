#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> wt, val;
vector<vector<int>> memo;

// maximum value using item types i..n-1 with capacity cap
int knap(int i, int cap) {
    if (cap == 0 || i == n) return 0;

    if (memo[i][cap] != -1)
        return memo[i][cap];

    int best = knap(i + 1, cap);

    // move on: skip item i

    if (wt[i] <= cap)
        best = max(best, val[i] + knap(i, cap - wt[i]));

    // use item i again

    return memo[i][cap] = best;
}

int main() {
    wt = {2, 3, 4};
    val = {4, 5, 7};

    n = wt.size();
    W = 8;

    memo.assign(n, vector<int>(W + 1, -1));

    cout << knap(0, W) << "\n";  // 16
}