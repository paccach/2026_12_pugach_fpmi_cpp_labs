#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::string;


vector < string > SplitWords(const string& s,
                             const string& delimeters)
{
    size_t i = 0;
    vector < string > words;
    while (i < s.size())
    {
        bool isdel = delimeters.find(s[i]) != string::npos;
        size_t start = i;
        while (i < s.size() &&
               (delimeters.find(s[i]) != string::npos) == isdel)
            i++;
        words.push_back(s.substr(start, i - start));
    }
    return words;
}

int main()
{
    int sum = 0, Max = INT_MIN;
    string str, dels;
    cout << "input string:\n";
    getline(cin, str);
    cout << "input delimeters (one line): ";
    getline(cin, dels);
    vector < string > words = SplitWords(str, dels);
    for (size_t w = 0; w < words.size(); w++)
    {
        string word = words[w];
        bool isNegative = false, f = false;
        if (word.size() == 1 && word[0] == '-')
            continue;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (i == 0 && word[i] == '-')
                isNegative = true;
            else if (word[i] < '0' || word[i] > '9')
            {
                f = true;
                break;
            }
        }
        if (f)
            continue;
        int number = std::stoi(word);
        sum += number;
        if (abs(number) > Max)
        {
            Max = abs(number);
        }
    }
    for (size_t w = 0; w < words.size(); w++)
    {
        string word = words[w];
        bool isNegative = false, f = false;
        if (word.size() == 1 && word[0] == '-')
            continue;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (i == 0 && word[i] == '-')
                isNegative = true;
            else if (word[i] < '0' || word[i] > '9')
            {
                f = true;
                break;
            }
        }
        if (f)
            continue;
        int number = std::stoi(word);
        if (abs(number) == Max)
        {
            string new_word = std::to_string(sum);
            words[w] = new_word;
        }
    }
    for (size_t i = 0; i < words.size(); i++)
        cout << words[i];
    return 0;
}
