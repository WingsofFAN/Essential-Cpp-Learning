#include <iostream>
#include <map>
#include <set>
#include <string>
#include<fstream>
#include <vector>
#include <algorithm>

using namespace std;

void initialize_exclusion_set(set<string>& exs )
{
    static string _exlude_words[25] = {
        "the","and","or","but","that","then","are","been","is","can","did","does","do","this","were","had","have","when","with","his","her"
        ,"would","will","a","an"
        };
    
    exs.insert(_exlude_words,_exlude_words+25);
}

void  process_file(map<string,int> &word_map,const set<string> &exclude_set, ifstream &ifile)
{
    string word;
    while(ifile >> word)
    {
        if (exclude_set.count(word))
            continue;
        word_map[word]++;
    }
}

void query(const map<string,int> &word_map)
{
    string search_word;
    cout << "please enter a word to search (q to quit):";
    cin >> search_word;
    while (search_word.size() && search_word != "q")
    {
        map<string ,int>::const_iterator iter;
        if((iter = word_map.find(search_word)) != word_map.end())
            cout << "Find \"" << iter->first << "\" occurs " << iter->second << " times.\n";
        else
            cout <<search_word << " was not found in word_map.";
        cout << "Another seasrch? Or q to quit. ";
        cin >> search_word;
    }    
}

void sort_word( vector<string>&all_word, ifstream &ifile )
{
    ifile.clear(); // 重置文件指针
    ifile.seekg(0,ios::beg); //指到文件开始处
    string word;
    while (ifile >> word)
    {
        all_word.push_back(word);
    }

    sort(all_word.begin(),all_word.end(),[](string a,string b){return a.length() <= b.length();});
    
}


int main()
{
    ifstream ifile("/home/fan/workspace/Essential-Cpp-Learning/第三章/test_in.txt");
    ofstream ofile("test_out.txt");
    if( !ifile || !ofile )
    {
        cerr << " Unable to open file -- bailing out!\n";
        return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set(exclude_set);
    map<string ,int> word_map;
    process_file(word_map,exclude_set,ifile);
    query(word_map);

    for(auto pp : word_map)
    {
        cout << pp.first << " occurs "<< pp.second << " times!"<< endl;
    }

    vector<string> all_word;
    sort_word(all_word,ifile);
    ifile.close();

    cout << all_word .size() << endl;

    for(auto str : all_word )
    {
        ofile << str << endl;       
    }
        
    ofile.close();

    return 0;
}