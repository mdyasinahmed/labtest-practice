#include<bits/stdc++.h>
using namespace std;

int main() {
    int coins[] = {1, 3, 5};
    int amount = 8;

    int n = sizeof(coins) / sizeof(coins[0]);

    // Initialize a 2D array to store the tables
    int table[n][amount + 1];

    // Initialize the array for the base case
    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
    }

    // Initialize the array for the base case when no coins are used
    for (int j = 1; j <= amount; j++) {
        table[0][j] = j;
    }

    // Fill in the table table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i] > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = min((table[i-1][j]), (1+table[i][j-coins[i]]));
            }
        }
    }

    // The final result is stored in table[n][amount]
    cout << "Minimum number of Coins to make change: " << table[n][amount] << endl;

    return 0;
}
