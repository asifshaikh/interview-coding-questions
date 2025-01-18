// Problem Statement -
// Joseph is learning digital logic subject which will be for his next semester. He usually tries to solve unit
// assignment problems before the lecture. Today he got one tricky question. The problem statement is "A positive
// integer has been given as an input. Convert decimal value to binary representation. Toggle all bits of it after the
// most significant bit including the most significant bit. Print the positive integer value after toggling all bits".
// Constraints-
// 1<=N<=100
// Example 1:
// Input:
// 10 -> Integer
// Output:
// 5-result-Integer
// Explanation:
// Binary representation of 10 is 1010. After toggling the bits (1010), will get 0101 which represents "5". Hence
// output will print "5".

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    string s = "";
    // converting to binary
    while (n > 0)
    {
        int rem = n % 2;
        s += to_string(rem);
        n = n / 2;
    }
    // reversing
    reverse(s.begin(), s.end());

    // toggling bits
    string newS = "";
    for (char c : s)
    {
        if (c == '0')
        {
            newS += '1';
        }
        else
        {
            newS += '0';
        }
    }
    cout << "flipped bits are: " << newS << endl;

    // converting back to decimal
    int result = 0;
    int power = 1;
    for (int i = newS.length() - 1; i >= 0; i--)
    {
        if (newS[i] == '1')
        {
            result += power;
        }
        power *= 2;
    }
    cout << "result: " << result << endl;

    return 0;
}