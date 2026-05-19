#include <iostream>
using namespace std;

int main() {
    int A[8] = {77, 33, 44, 11, 88, 22, 66, 55};
    int n = 8, LOC, MIN, temp;

    cout << "Original Array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Selection Sort
    for(int K = 0; K < n - 1; K++) {
        MIN = A[K];  // Min = 77 
        LOC = K;     // Loc = 0

        // Find smallest element
        for(int J = K + 1; J < n; J++) {
            if(MIN > A[J]) {
                MIN = A[J];
                LOC = J;
            }
        }
        // Min = 11
        // Loc = 3

        // Swap elements
        temp = A[K]; // temp = 77
        A[K] = A[LOC]; // A[k] = 11
        A[LOC] = temp; // A[Loc] = 77

        // Print each pass
        cout << "Pass " << K + 1 << ": ";
        for(int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}