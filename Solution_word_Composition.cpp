#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

unordered_set<string> wordSet;  // Use a hash set for faster lookups

bool isCompoundWord(const string& word) {
    if (word.empty()) 
    {
        return false;  // An empty word cannot be a compound word.
    }

    int len = word.length();

    for (int i = 1; i < len; ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);

        if (wordSet.count(prefix) && (wordSet.count(suffix) || isCompoundWord(suffix))) 
        {
            return true;
        }
    }

    return false;  // The word is not a compound word.
}

int main() {
    ifstream inputFile1("Input_01.txt");
    ifstream inputFile2("Input_02.txt");

    if (!inputFile1.is_open() || !inputFile2.is_open()) 
    {
        cerr << "Error opening input files.\n";
        return 1;
    }

    string word;

    // Read words from Input_01.txt and Input_02.txt files.

    cout<<"Choose: \n";
    cout<<"1. Input_01.txt \n";
    cout<<"2. Input_02.txt \n";
    cout<<"Enter your Choice: ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: while (inputFile1 >> word) 
                {
                    wordSet.insert(word);
                }
                break;
        case 2: while (inputFile2 >> word) 
                {
                    wordSet.insert(word);
                }
                break;
        default: cout<<"Invalid Choice! \n";
                 break;
    }
    

    inputFile1.close();
    inputFile2.close();

    // Measure time taken to process input files
    auto start = high_resolution_clock::now();

    string longestCompoundWord;
    string secondLongestCompoundWord;

    for (const string& word : wordSet) 
    {
        if (isCompoundWord(word)) {
            if (word.length() > longestCompoundWord.length()) 
            {
                secondLongestCompoundWord = longestCompoundWord;
                longestCompoundWord = word;
            } 
            else if (word.length() > secondLongestCompoundWord.length()) 
            {
                secondLongestCompoundWord = word;
            }
        }
    }

    if (longestCompoundWord.empty()) 
    {
        cout << "No Compound Word Present.\n";
    } 
    else 
    {
        // Display the identified data
        cout << "Longest Compounded Word: " << longestCompoundWord << endl;
        cout << "Second Longest Compounded Word: " << secondLongestCompoundWord << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to process input files: " << duration.count() << " milliseconds\n";

    return 0;
}

