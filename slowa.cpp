#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> words;

void generate_words(string curr_word, char prev_char, int n, vector<string>& words)
{
    if(curr_word.length() == n)
    {
        words.push_back(curr_word);
        return;
    }   

    for(char ch : {'a', 'b', 'c'})
    {
        if(ch != prev_char)
        {
            generate_words(curr_word + ch, ch, n, words);
        }
    }
}

int main()
{
    cin >> n;
    generate_words("", '\0', n, words);
    cout << words.size() << "\n";

    for(string word : words)
    {
        cout << word << endl;
    }
    
    return 0;
}