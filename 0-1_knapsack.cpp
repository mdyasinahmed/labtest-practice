#include<bits/stdc++.h>
using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int profit;
};

// Function to solve the 0/1 Knapsack problem
pair<int, vector<int>> knapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> table(n+1, vector<int>(capacity+1, 0));

    // Build the table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i-1].weight > w) {
                table[i][w] = table[i-1][w];
            } else {
                table[i][w] = max(table[i-1][w], table[i-1][w - items[i-1].weight] + items[i-1].profit);
            }
        }
    }

    // Find the selected items
    vector<int> selectedItems;
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (table[i][w] != table[i-1][w]) {
            selectedItems.push_back(i-1);
            w -= items[i-1].weight;
        }
    }

    return make_pair(table[n][capacity], selectedItems);
}

int main() {
    int capacity, n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ", Weight and Profit " << ": ";
        cin >> items[i].weight >> items[i].profit;
    }

    pair<int, vector<int>> result = knapsack(items, capacity);

    cout << "Maximum Profit: " << result.first << endl;
    cout << "Selected Items: ";

    for (int i = result.second.size() - 1; i >= 0; i--) {
        cout << result.second[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
