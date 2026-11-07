#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int R, C;
vector<vector<int>> grid, memo;

// cheapest total from (r, c) to the destination, including (r, c)
int cost(int r, int c) {
    
    if (r >= R || c >= C) return INF;              // outside the grid

    if (r == R - 1 && c == C - 1) return grid[r][c]; // destination
    
    if (memo[r][c] != -1) return memo[r][c];

    int down  = cost(r + 1, c);
    int right = cost(r, c + 1);

    return memo[r][c] = grid[r][c] + min(down, right);
}

int main() {
    grid = {{1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}};

    R = grid.size();
    C = grid[0].size();

    memo.assign(R, vector<int>(C, -1));

    cout << cost(0, 0) << "\n";              // 7
}