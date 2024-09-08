#include <iostream>
#include <iomanip>
using namespace std;

int c = 0;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

void printTable(int dp[][100], int m, int n, string str1, string str2) {
    // Print table header
    cout << "   ";
    for (int j = 0; j <= n; j++) {
        if (j == 0)
            cout << "    ";
        else
            cout << setw(3) << str2[j-1] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                if (i == 0)
                    cout << "   ";
                else
                    cout << setw(3) << str1[i-1] << " ";
            }
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int editDistDP(string str1, string str2, int m, int n) {
    // Create a table to store results of subproblems
    int dp[100][100] = {0}; // assuming max string length is less than 100

    // Fill d[][] in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0) {
                dp[i][j] = j; // Min. operations = j
                c++;
            } else if (j == 0) {
                dp[i][j] = i; // Min. operations = i
                c++;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                c = c + 6;
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
                c = c + 10;
            }
            c = c + 4;
        }
        c = c + 4;
    }

    // Print the final table after the full computation
    printTable(dp, m, n, str1, str2);

    return dp[m][n];
}

int main() {
    string str1 = "swarup";
    string str2 = "dahal";

    cout << "Maximum no. of edit required: "
         << editDistDP(str1, str2, str1.length(), str2.length()) << endl;
    cout << "No. of steps Required: " << c << endl;

    return 0;
}
