#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, word = "", longestWord = "";

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    sentence = sentence + " ";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            word = word + sentence[i];
        }
        else
        {
            if (word.length() > longestWord.length())
            {
                longestWord = word;
            }
            word = "";
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << longestWord.length();

    return 0;
}
