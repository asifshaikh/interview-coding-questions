//  2. Making Anagrams
//  Problem Statement:
//  Alice is attending a cryptography class and has discovered that anagrams can be very useful.
//  She is working on an encryption scheme that involves two large strings. The encryption is
//  dependent on determining the minimum number of character deletions required to turn the
//  two strings into anagrams.
// Two strings are considered anagrams if the letters of one string can be rearranged to form the
//  other string, meaning both strings must contain the same exact letters in the same exact
//  frequencies.
//  Given two strings, your task is to calculate the minimum number of deletions required to make
//  them anagrams. Characters can be deleted from either string.
//  Constraints:
//  ● Bothstrings consist only of lowercase English letters (a to z).
//  ● Thelengths of the strings can vary but will not exceed ten to the power of four.
//  Input Format:
//  ● Thefirst line contains the first string.
//  ● Thesecond line contains the second string.
//  Output Format:
//  ● Print a single integer denoting the minimum number of character deletions required to
//  make the strings anagrams.
//  Sample Input:
//  cde
//  abc
//  Sample Output:
//  4
//  Explanation:
//  To make the strings anagrams:
//  ● Removedandefrom"cde" to get "c".
//  ● Removeaandbfrom"abc" to get "c".
//  This results in a total of 4 deletions

#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string s1, string s2)
{
    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1)
    {
        freq1[c - 'a']++;
    }
    for (char c : s2)
    {
        freq2[c - 'a']++;
    }
    int deletions = 0;
    for (int i = 0; i < 26; i++)
    {
        deletions += abs(freq1[i] - freq2[i]);
    }
    return deletions;
}

int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int result = makeAnagram(s1, s2);
    cout << "Minimum number of deletions required to make the strings anagrams: " << result;
    return 0;
}