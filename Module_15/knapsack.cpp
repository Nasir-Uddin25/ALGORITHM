#include <bits/stdc++.h>
using namespace std;
int price[1005], weight[1005];

int knapsack(int i, int mx_weight)
{
    // base case
    if (i < 0 || mx_weight <= 0)
        return 0;
    if (weight[i] <= mx_weight)
    {
        // 2 options
        // 1. bag a rakhbo.   2. bag a rakhbo na
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + price[i];
        int opt2 = knapsack(i - 1, mx_weight);
        return max(opt1, opt2);
    }
    else
    {
        // 1 option
        //  2. bag a rakhbo na
        return knapsack(i - 1, mx_weight);
    }
}
int main()
{
    int n; // 4
    cin >> n;

    for (int i = 0; i < n; i++) // 10 4 7 5
        cin >> price[i];
    for (int i = 0; i < n; i++) // 4 3 2 5
        cin >> weight[i];

    int mx_weight;
    cin >> mx_weight; // 8

   cout << knapsack(n - 1, mx_weight); // last index number, bag er weight
    return 0;
}