#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &ar, int n)
{

    for (int i = 1; i < n; i++)
    {
        int currnt = ar[i];
        int pre = i - 1;

        while (pre >= 0 && ar[pre] > currnt)
        {
            ar[pre + 1] = ar[pre];
            pre--;
        }
        ar[pre + 1] = currnt;
    }

    for (auto val : ar)
    {
        cout << val << " ";
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> ar(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    insertionSort(ar, n - 1);

    return 0;
}