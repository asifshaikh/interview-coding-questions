// A password manager wants to create new passwords using two strings given by
// the user, then combines them to create a harder-to-guess combination. Given
// two strings, the task is to interleave the characters of the strings to create a
// new string. Begin with an empty string and alternately append a character from
// string 'a' and from string 'b'. If one of the strings is exhausted before the other,
// append the remaining letters from the other string all at once. The resulting
// string is the new password.
// Example:
// If a 'hackerrank' and b = 'mountain', the resulting password is
// 'hmaocuknetrariannk'.
// Function Description:
// Complete the function newPassword which takes two strings 'a' and 'b' as input
// and returns the new password as a string.
// Parameters:
// Str a: String 'a'
// Str b: String 'b'
// Returns:
// Str: New password using two strings
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "hackerrank";
    string b = "mountain";
    string result = "";
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        result += a[i++];
        result += b[j++];
    }
    while (i < a.length())
    {
        result += a[i++];
    }
    while (j < b.length())
    {
        result += b[j++];
    }
    cout << result << endl;
    return 0;
}