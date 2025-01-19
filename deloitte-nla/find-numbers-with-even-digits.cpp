//  Find Numbers with Even Digits
//  Problem Statement:
//  In a distant kingdom, a wise king has a chest full of magical numbers. He decides to reward the
//  most observant mathematician in the land. Your task is to analyze a list of these numbers and
//  identify which ones contain an even number of digits. The king believes that only numbers with
//  an even number of digits hold the key to unlock the hidden treasures of the kingdom. Can you
//  help identify these numbers for the king?
//  Constraints:
//  ● Thearray length 1≤n≤10^4
//  ● Eachnumber in the array is a positive integer 1≤num≤10^9
//  Sample Input:
//  123,4567,89,1001,22
//  Sample Output:
//  4567, 89, 1001, 22
//  Explanation:
//  Numbers like 123 have 3 digits, which is odd, so they are excluded. However, 89 and 22 have 2
//  digits, which is even, so they are included

#include <bits/stdc++.h>
using namespace std;

bool checkEvenDigits(int nums)
{
    int count = 0;
    while (nums > 0)
    {
        nums /= 10;
        count++;
    }
    return count % 2 == 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    vector<int> result;
    for (int nums : numbers)
    {
        if (checkEvenDigits(nums))
        {
            result.push_back(nums);
        }
    }
    cout << "Numbers with even digits:";
    for (int nums : result)
    {
        cout << nums << " ";
    }
    cout << endl;
    return 0;
}