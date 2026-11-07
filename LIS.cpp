#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> memo;          // memo[i][prev + 1]

// longest increasing subsequence from a[i...],
// given the last picked element is a[prev] (prev = -1 if none)
int lis(int i, int prev) {
    if (i == n) return 0;
    if (memo[i][prev + 1] != -1) return memo[i][prev + 1];

    int best = lis(i + 1, prev);                  // skip a[i]

    if (prev == -1 || a[i] > a[prev])
        best = max(best, 1 + lis(i + 1, i));      // take a[i]

    return memo[i][prev + 1] = best;
}

int main() {
    a = {10, 9, 2, 5, 3, 7, 101, 18};
    n = a.size();

    memo.assign(n, vector<int>(n + 1, -1));

    cout << lis(0, -1) << "\n";                  // 4
}