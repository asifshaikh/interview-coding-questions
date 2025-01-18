// Rahul is known for copying in exams from his adjacent students, but he's smart
// about it. Instead of directly copying the words, he changes the positions of letters
// while keeping the letters constant. As the examiner, you need to determine if Rahul
// has copied a certain word from the adjacent student who is giving the same exam.
// You should provide Rahul with the appropriate markings based on your findings.
// Note:
// String is UpperCase
// Input Format:
// The first line contains the word of the adjacent student.
// The second line contains Rahul's words.
// Output Format:
// O if Rahul did not copy.
// 1 if Rahul copied.
// Constraints:
// 1 <= Length of string <= 10^6
// Sample Input:
// HELLO
// EHLLO
// Sample Output:1
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int checkIfCopied(const string &studentWord, const string &rahulWord)
{
    // If lengths are not equal, Rahul did not copy
    if (studentWord.length() != rahulWord.length())
        return 0;

    // Sort both strings
    string sortedStudent = studentWord;
    string sortedRahul = rahulWord;
    sort(sortedStudent.begin(), sortedStudent.end());
    sort(sortedRahul.begin(), sortedRahul.end());

    // Compare sorted strings
    return (sortedStudent == sortedRahul) ? 1 : 0;
}

int main()
{
    string studentWord, rahulWord;
    cout << "Enter the word of the adjacent student: ";
    cin >> studentWord;
    cout << "Enter Rahul's word: ";
    cin >> rahulWord;

    int result = checkIfCopied(studentWord, rahulWord);
    cout << result << endl;

    return 0;
}
