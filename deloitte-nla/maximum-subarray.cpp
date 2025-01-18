// You are given an array, and you need to choose a contiguous subarray of length 'k'.
// Then, find the minimum value within that subarray and return the maximum of
// those minimum values.
// I
// Sample Input:
// Length of the subarray: 2
// Size of the array: 6
// Array elements: [3, 1, 4, 6, 2, 5]
// Explanation:
// The subarrays of size 2 are: [3, 1], [1, 4], [4, 6], [6, 2], and [2, 5].
// The minimum values within these subarrays are: 1, 1, 4, 2, and 2 respectively.
// The maximum of these minimum values is 4.
// Output: 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int k;
    cout << "Enter the length of the subarray: ";
    cin >> k;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxValue = INT_MIN;
    for (int i = 0; i < n - k; i++)
    {
        int currentMin = INT_MAX;
        for (int j = i; j < i + k; j++)
        {
            currentMin = min(currentMin, arr[j]);
        }
        maxValue = max(maxValue, currentMin);
    }
    cout << "The maximum value is: " << maxValue << endl;

    return 0;
}