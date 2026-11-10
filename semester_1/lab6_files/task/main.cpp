#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <locale>
#include <chrono>
#include <ctime>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::string;


std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable: 4996)
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
           ? std::put_time(std::gmtime(&time), "%x %X")
           : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
    #pragma warning(pop)
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif
}

void Log(const string &msg)
{
    std::ofstream f("log.txt", std::ios::app);
    if (!f.is_open() ) {
        throw "Error: Could not open log file";
    }
    f << FormatTime(Now(), true) << " | " << msg << "\n";
    //f.close();
}

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

void ChangeMax(vector < string > &words)
{
    Log("finding and changing max number");
    int sum = 0, Max = INT_MIN;
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
    bool isChanged = false;
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
            isChanged = true;
        }
    }
    if (!isChanged)
        Log("string has not numbers");
}

/*std::string ReadStringFromFile(const string& filename)
{
    Log("opening file " + filename);
    std::ifstream fin{filename};
    if ( !fin.is_open() ) {
        throw "Error: Could not open file: " + filename;
    }
    if (fin.peek() == std::ifstream::traits_type::eof()) {
       throw "Error: File " + filename + " is empty";
    }
    Log("reading lines from " + filename);
    string str;
    if (!std::getline(fin, str)) {
        throw "Failed to read strings from file " + filename;
    }
    Log("file " + filename + " has been opened successfully");
    Log("got line: " + str);
    return str;
}

void WriteWordsToFile(const string& filename, vector < string > &words)
{
    Log("opening file " + filename);
    std::ofstream fout{filename};
    if (!fout.is_open() ) {
        throw "Error: Could not open file: " + filename;
    }
    Log("file " + filename + " has been opened successfully");
    Log("writing words to " + filename);
    for (size_t i = 0; i < words.size(); i++)
        fout << words[i];
}*/

void ProcessFile (const string &input_file, const string &output_file)
{
    Log("opening file " + input_file);
    std::ifstream fin{input_file};
    if ( !fin.is_open() ) {
        throw "Error: Could not open file: " + input_file;
    }
    if (fin.peek() == std::ifstream::traits_type::eof()) {
       throw "Error: File " + input_file + " is empty";
    }
    Log("file " + input_file + " has been opened successfully");
    Log("reading lines from " + input_file);
    string dels;
    if (!std::getline(fin, dels)) {
        throw "Failed to read strings from file " + input_file;
    }
    Log("got line: " + dels);

    Log("opening file " + output_file);
    std::ofstream fout{output_file};
    if (!fout.is_open() ) {
        throw "Error: Could not open file: " + output_file;
    }
    Log("file " + output_file + " has been opened successfully");

    string str;
    while (std::getline(fin, str))
    {
        Log("got line: " + str);
        vector < string > words = SplitWords(str, dels);
        ChangeMax(words);
        for (size_t i = 0; i < words.size(); i++)
            fout << words[i];
        fout << "\n";
    }
}

int main()
{
    const string output_file = "output.txt";
    const string input_file = "input.txt";
    try
    {
        ProcessFile(input_file, output_file);
    }
    catch (const string &msg)
    {
        cout << msg << "\n";
    }
    Log("program has ended with code 0\n");
    return 0;
}
