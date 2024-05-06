#include "TextProcessor.h"
using namespace std;




TextProcessor::TextProcessor(string paragraph) {
    WordSplitter(paragraph);
    sortedfreq();
}
TextProcessor::TextProcessor() {

}

bool TextProcessor:: searchWordFrequency(string word, map<string, int> wordFrequency)
{
    auto it = wordFrequency.find(word);
    if (it != wordFrequency.end())
    {
        cout << "Frequency of " << word << ":" << it->second << endl;
        return true;
    }
    else
    {
        cout << "Frequency of " << word << " not found\n";
        return false;
    }
}

void TextProcessor::sortedfreq() {
    vector<pair<string, int>>vec(words.begin(), words.end());

    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort by the second element of the pair
        });
    sortedwords = vec;
}

int TextProcessor::rankkingbyitChar(string s)
{
    vector<pair<string, int>>v(words.begin(), words.end());
    if (contain(s) == 1) {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == s)
            {
                return i + 1;
            }
        }
    }
    else
        return -1;

}



int TextProcessor::rankkingbyfreq(string s)
{
    int counter = 0;
    if (contain(s) == 1) {
        for (int i = 0; i < sortedwords.size(); i++)
        {
            if (i == 0 && sortedwords[i].first == s)
                return counter + 1;


            if (sortedwords[i].first == s)
            {
                if (sortedwords[i - 1].second != sortedwords[i].second) counter++;
                return counter;
            }
            else
            {
                if (i == 0)
                    counter++;

                else
                {
                    if (sortedwords[i - 1].second == sortedwords[i].second)
                        continue;
                    else counter++;
                }
            }
        }
    }
    else
        return -1;

    // اللوب اللى بترجع كلهم عشان لو احتجنها قدام

   /* int counter = 1;
    for (int i = 0; i < sortedwords.size(); i++)
    {
        if (i == 0)
            cout << counter << " rank ( " << sortedwords[i].first << " => " << sortedwords[i].second << " ) " << endl;
        else
        {
            if(sortedwords[i].second==sortedwords[i-1].second)
                cout << counter << " rank ( " << sortedwords[i].first << " => " << sortedwords[i].second << " ) " << endl;
            else
            {
                cout << ++counter << " rank ( " << sortedwords[i].first << " => " << sortedwords[i].second << " ) " << endl;

            }
        }
    }


    */

}

bool TextProcessor::contain(string s) {

    return (words.find(s) != words.end());

}


string TextProcessor::Tolowercase(string sentence) {
    for (int i = 0; i < sentence.size(); ++i) {
        if (sentence[i] == '.'|| sentence[i] == ',' || sentence[i] == '-' || sentence[i] == ':' || sentence[i] == ';' || sentence[i] == '?' || sentence[i] == '!' || sentence[i] == '_'  )
            sentence.erase(i);
        else
        sentence[i] = tolower(sentence[i]);
    }
    return sentence;
}


void TextProcessor::WordSplitter(string paragraph) {
    HistoryOrganizer freq;
    istringstream iss(paragraph);
    map<string, int>temp;
    string word;
    while (iss >> word) {
        word = Tolowercase(word);
        temp[word]++;
        freq.setmap(word);
        // cout << word << "  " << temp[word] << endl;
    }
    words = temp;
}
void TextProcessor::Display() {

    for (auto it : sortedwords) {
        cout << it.first << " " << it.second << endl;
    }

}

