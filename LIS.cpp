// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<int> a;
// vector<vector<int>> memo;          // memo[i][prev + 1]

// // longest increasing subsequence from a[i...],
// // given the last picked element is a[prev] (prev = -1 if none)
// int lis(int i, int prev) {

//     if (i == n) return 0;

//     if (memo[i][prev + 1] != -1) return memo[i][prev + 1];

//     int skip = lis(i + 1, prev);                  // skip a[i]

//     int take = 0;
//     if (prev == -1 || a[i] > a[prev])
//         take =  1 + lis(i + 1, i);      // take a[i]

//     return memo[i][prev + 1] = max(skip ,take);
// }

// int main() {

//     a = {10, 9, 2, 5, 3, 7, 101, 18};
//     n = a.size();

//     memo.assign(n, vector<int>(n + 1, -1));

//     cout << lis(0, -1) << "\n";                  // 4
// }





#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> memo;

int lis(int i, int prev) {

    if (i == n) return 0;

    if (memo[i][prev + 1] != -1)
        return memo[i][prev + 1];

    int skip = lis(i + 1, prev);

    int take = 0;
    if (prev == -1 || a[i] > a[prev])
        take = 1 + lis(i + 1, i);

    return memo[i][prev + 1] = max(skip, take);
}

// Print the LIS sequence
void printLIS(int i, int prev) {

    if (i == n) return;

    int skip = lis(i + 1, prev);

    int take = 0;
    if (prev == -1 || a[i] > a[prev])
        take = 1 + lis(i + 1, i);

    if (take > skip) {
        cout << a[i] << " ";
        printLIS(i + 1, i);
    }
    else {
        printLIS(i + 1, prev);
    }
}

int main() {

    a = {10, 9, 2, 5, 3, 7, 101, 18};
    n = a.size();

    memo.assign(n, vector<int>(n + 1, -1));

    cout << "LIS Length: " << lis(0, -1) << "\n";

    cout << "LIS Sequence: ";
    printLIS(0, -1);

    return 0;
}