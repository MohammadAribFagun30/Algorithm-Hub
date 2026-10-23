#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &ar, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int smallIndx = i;

        for(int j = i+1; j<n; j++)
        {
            if( ar[j] < ar[smallIndx] )
            {
                smallIndx = j;
            }
        }
         swap( ar[i] , ar[smallIndx]);
    }

    

    for(auto  val : ar)
    {
        cout<<val<<" ";
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

    selectionSort(ar,n-1);


    return 0;
}