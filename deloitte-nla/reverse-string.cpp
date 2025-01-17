// Problem Statement:

// Write a function that takes a string s as input and returns the string with the words reversed. A word is defined as a sequence of non-space characters. You must ensure that words are separated by a single space in the output, and there should be no leading or trailing spaces.

// Example Input and Output:

// Input:

// "hello world"
// Output:

// "world hello"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    // Remove leading and trailing spaces
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);

    // Use a stringstream to split words
    stringstream ss(s);
    string word;
    vector<string> words;

    // Collect words into a vector
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Reverse the words
    reverse(words.begin(), words.end());

    // Join words back into a single string
    string result;
    for (int i = 0; i < words.size(); ++i)
    {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main()
{
    string input;

    getline(cin, input);

    string result = reverseWords(input);
    cout << result << endl;

    return 0;
}