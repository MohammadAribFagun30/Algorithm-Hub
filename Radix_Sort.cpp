#include <iostream>
    using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }


    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }


    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }


    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

}

void radixSort(int arr[], int n)
{
    int mx = arr[0];


    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }


    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }

}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";


    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    radixSort(arr, n);

    cout << "Sorted array: ";
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}