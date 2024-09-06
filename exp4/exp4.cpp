// 4. Write a program to solve 0/1 knapsack using Greedy algorithm.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

bool compareValue(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int knapsack_0_1(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compareValue);
    int currect_weight = 0;
    int total_value = 0;

    for (const auto &item : items)
    {
        if (currect_weight + item.weight <= capacity)
        {
            currect_weight += item.weight;
            total_value += item.value;
        }
        else
        {
            break;
        }
    }
    return total_value;
}
int main()
{
    cout<<"Name: Nirmit Rampal\nURN: 2302729\n\n";
    int n, capacity;

    cout << "Enter the number of items you want INPUT: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight and value for item" << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int maxValue = knapsack_0_1(capacity, items);

    cout << "Maximum Value that can be store is " << maxValue << endl;
    return 0;
}