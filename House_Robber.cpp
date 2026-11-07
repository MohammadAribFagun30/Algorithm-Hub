#include <bits/stdc++.h>
using namespace std;

// int n;
// vector<int> a, memo;

// // most money from houses i...n-1
// int rob(int i) {
//     if (i >= n) return 0;                 // no houses left
//     if (memo[i] != -1) return memo[i];

//     int take = a[i] + rob(i + 2);
//     int skip = rob(i + 1);

//     return memo[i] = max(take, skip);
// }

// int main() {
//     a = {2, 7, 9, 3, 1};
//     n = a.size();
//     memo.assign(n, -1);

//     cout << rob(0) << "\n";               // 12
// }



int n;
vector<int> a;
vector<vector<int>> memo;

// most money from houses i...n-1, given whether house i-1 was robbed
int rob(int i, int prevTaken) {
    if (i == n) return 0;  // no houses left

    if (memo[i][prevTaken] != -1)
        return memo[i][prevTaken];

    int skip = rob(i + 1, 0);  // skip house i
    
    int take = 0;

    if (!prevTaken)
     take =  a[i] + rob(i + 1, 1);  // rob house i

    return memo[i][prevTaken] = max(skip,take);
}

int main() {
    a = {2, 7, 9, 3, 1};
    n = a.size();

    memo.assign(n, vector<int>(2, -1));

    cout << rob(0, 0) << "\n";  // 12
}