#include <iostream>
#include <fstream>
#include <vector>
#include <iostream> 
#include <algorithm> 
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

vector<string> anagram(string word, vector<string> wordlist);
bool isAnagram(string word1, string word2);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}
//HELPER FUNCTION THAT SORTS STRINGS IN ALPHABETICAL ORDER
//COMPARES THE LETTERS TO SEE IF THEY ARE THE SAME
bool isAnagram(string word1, string word2){
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    if(word1.compare(word2) == 0){
        return true;
    } else {
        return false;   
    }
}

vector<string> anagram(string word, vector<string> wordlist)
{
    vector<string> anagrams;
    //GOES THROUGH EACH STRING IN DICTIONARY
    for(int i = 0; i < wordlist.size(); i++){
        if(wordlist[i].length() == word.length()){
         if(isAnagram(wordlist[i], word) == true){
            anagrams.push_back(wordlist[i]);
            }           
        }
    }
    return anagrams;
}

