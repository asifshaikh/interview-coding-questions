// Sara has a box which has N chocolates in it. Sara decides to gift them
// to alice and bob. Bob gets x chocolates and Alice gets remaining y
// chocolates.
// Bob and Alice starts fighting for chocolates so sara comes up with a
// game.
// If Bob gets x chocolates and Alice got y chocolates and if x>y, then
// bob should put y chocolates into the box and vica versa is also
// applicable.
// This continues till either of them are left with 0 chocolates or they
// both have same number of chocolates.
// Sample Input 1:
// 10 4
// Sample Output 1:
// 6

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    int y = n - x;
    int b = 0;

    while (x != 0 && y != 0 && x != y)
    {
        if (x > y)
        {
            b += y;
            x = x - y;
        }
        else
        {
            b += x;
            y = y - x;
        }
    }
    cout << b << endl;
    return 0;
}