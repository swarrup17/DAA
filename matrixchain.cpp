#include <iostream>
#include <iomanip> // For formatting the table output
#include <climits> // For INT_MAX

using namespace std;

int c = 0;

// Utility function to print matrices in table format with 2-character gap between values
void printMatrix(int matrix[][100], int n, const string& name) {
    cout << name << " matrix:" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j < i) {
                cout << setw(7) << " "; // Additional space for gap
            } else {
                cout << setw(7) << matrix[i][j]; // Additional space for gap
            }
        }
        cout << endl;
    }
    cout << endl;
}

void MatrixChainOrder(int p[], int n) {
    int m[100][100] = {0}; // Matrix to store the minimum number of operations
    int s[100][100] = {0}; // Matrix to store the split points

    // Initializing the main diagonal of the matrix to 0
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
        c++;
    }

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // Initialize the cost to a large value
            c += 4;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                c += 7;

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                    c++;
                }
                c += 5;
            }
            c += 6;
        }
        c += 4;
    }

    // Print the m and s matrices with 2-character gap between values
    printMatrix(m, n, "m");
    printMatrix(s, n, "s");
}

int main() {
    int arr[] = {22, 44, 77, 55, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    MatrixChainOrder(arr, size);

    cout << "No. of steps Required: " << c << endl;

    return 0;
}
