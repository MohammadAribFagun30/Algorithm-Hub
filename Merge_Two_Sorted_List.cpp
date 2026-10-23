#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &ar, int st, int mid, int end)
{
    vector<int> temp;

    int i = st , j = mid+1;

    while(i<=mid && j<=end)
    {
        if(ar[i] <= ar[j])
        {
            temp.push_back(ar[i]);
            i++;
        }

        else{
            temp.push_back(ar[j]);
            j++;
        }
    }


    while(i<=mid)
    {
        temp.push_back(ar[i]);
            i++;
    }

     while(j<=end)
    {
         temp.push_back(ar[j]);
            j++;
    }

    for(int i = 0; i<temp.size(); i++)
    {
        ar[i+st] = temp[i];
    }
}

void mergeSort(vector<int> &ar, int st, int end)
{
    if(st<end)
    {
        int mid  = st + (end-st)/2;

        // left half
        mergeSort(ar, st, mid);

        // right half
        mergeSort(ar, mid+1, end);

        merge(ar, st, mid, end);
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

    mergeSort(ar,0,n-1);

    for(auto  val : ar)
    {
        cout<<val<<" ";
    }

    return 0;
}