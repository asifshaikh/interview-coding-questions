// In a bustling tech city named AlgoVille, a group of freelance programmers is
// tasked with completing a set of projects for various clients. Each project
// comes with a job ID, a deadline (number of days by which it must be
// completed), and a profit (payment for completing the job). However, each
// programmer can only complete one project per day, and they want to
// maximize their total earnings.
// Can you help the programmers figure out which projects to take up and in
// what order to maximize their profit?
// Problem Statement:
// You are given a list of jobs where each job has:
// Job ID - A unique identifier for the job.
// Deadline - The number of days available to complete the job (from day 1).
// Profit - The payment received for completing the job.
// Your task is to:
// Schedule the jobs to maximize the total profit.
// Ensure that no two jobs are assigned on the same day.
// Jobs can only be completed within their deadline.
// Input: A list of jobs where each job is represented as:
// Job=(ID,Deadline, Profit)
// Example:
// Jobs [(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,3,15)]
// Output:
// The maximum profit.
// The job IDs in the order they should be completed.

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
    for (int i = 1; i < maxE + 1; i++)
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