#include <bits/stdc++.h>
using namespace std;

class InsertionSort
{
private:
    int A[100], N;

public:
    // Input array
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> N;

        cout << "Enter elements:\n";
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }

        // Sentinel value
        A[0] = -9999;
    }

    // Insertion Sort
    void sort()
    {
        int TEMP, PTR;

        cout << "\nPasses of Insertion Sort:\n";

        for (int K = 2; K <= N; K++)
        {
            TEMP = A[K];
            PTR = K - 1;

            while (TEMP < A[PTR])
            {
                A[PTR + 1] = A[PTR];
                PTR = PTR - 1;
            }

            A[PTR + 1] = TEMP;

            // Display array after each pass
            cout << "Pass " << K - 1 << ": ";
            for (int i = 1; i <= N; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    }

    // Display sorted array
    void display()
    {
        cout << "\nSorted Array:\n";
        for (int i = 1; i <= N; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    InsertionSort obj;

    obj.input();
    obj.sort();
    obj.display();

    return 0;
}