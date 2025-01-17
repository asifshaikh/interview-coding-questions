#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int maxE = 0;
    for (int i = 0; i < n; i++)
    {
        maxE = max(maxE, arr[i].deadline);
    }
    int slot[maxE + 1];
    int countJob = 0;
    int profit = 0;
    for (int i = 0; i < maxE + 1; i++)
    {
        slot[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                countJob++;
                profit += arr[i].profit;
                slot[j] = arr[i].id;
                break;
            }
        }
    }
    for (int i = 1; i < maxE + 1; i++)
    {
        cout << slot[i] << " ";
    }
    cout << endl;
    cout << profit << endl;
}

int main()
{

    Job arr[]{{1, 2, 100},
              {2, 1, 19},
              {3, 2, 27},
              {4, 1, 25},
              {5, 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printJobScheduling(arr, n);

    return 0;
}