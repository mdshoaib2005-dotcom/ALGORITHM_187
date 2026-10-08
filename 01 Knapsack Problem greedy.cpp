#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

// Compare items based on value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    int totalValue = 0;
    int remainingCapacity = capacity;

    cout << "\nSelected items:\n";

    // Greedily select complete items
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;

            cout << "Weight = " << items[i].weight
                 << ", Value = " << items[i].value << endl;
        }
    }

    cout << "\nMaximum value (Greedy) = " << totalValue << endl;

    return 0;
