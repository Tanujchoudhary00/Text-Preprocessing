#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    string temp;

    ifstream fin("C:/Users/abc/projects/Text-Preprocessing/dummy-text.txt");

    /*map for storing word and its freq*/
    map<string,int> wordfreq;

    /*extracting from file word by word*/
    while(fin)
    {
        /*for storing individual words*/
        string word;

        fin >> word;
        /*converting to lowercase*/
        transform( word.begin(), word.end(), word.begin(), :: tolower );

        /*incrementing in map*/
        wordfreq[word]++;
    }

    fin.close();

    /*stop words list*/
    vector<string> stopwords = {"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};

    /*removing stop words*/
    for(auto elem : stopwords)
        wordfreq.erase(elem);

    for(auto elem : wordfreq)
        cout  << elem.first <<  " = " << elem.second << endl;
}

