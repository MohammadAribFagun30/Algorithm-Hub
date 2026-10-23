#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &ar, int st, int end)
{
    int indx = st-1, pivot = ar[end];

    for(int j=st; j<end; j++)
    {
        if(ar[j] <= pivot)
        {
            indx++;

            swap(ar[j], ar[indx]);
        }
    }

    // place the pivot in the middle of the array
    indx++;
    swap(ar[end], ar[indx]);

    return indx;
}

void quickSort(vector<int> &ar, int st, int end)
{
    if(st < end)
    {
        int pivotIndx = partition(ar,st,end);

        // left half
        quickSort(ar, st, pivotIndx-1);

        // right half
        quickSort(ar, pivotIndx+1, end);

    }
}

int main() {
    int n;
    cin>>n;

    vector<int>ar(n);

    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

    quickSort(ar,0,n-1);

    for(auto  val : ar)
    {
        cout<<val<<" ";
    }

    return 0;
}