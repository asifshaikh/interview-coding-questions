#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int> &coins)
{
    int n = coins.size();

    // Edge cases
    if (n == 0)
        return 0;
    if (n == 1)
        return coins[0];

    // Initialize two variables to store the maximum coins at previous two steps
    int prev2 = 0;        // Represents dp[i-2]
    int prev1 = coins[0]; // Represents dp[i-1]

    for (int i = 1; i < n; ++i)
    {
        // Calculate the maximum coins for the current jar
        int curr = max(prev1, coins[i] + prev2);
        // Update prev2 and prev1 for the next iteration
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1; // The last stored value represents the maximum coins we can collect
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int result = maxCoins(coins);
    cout << "Maximum coins you can collect: " << result << endl;
    return 0;
}