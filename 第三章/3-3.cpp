#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

int main()
{
    map<string,vector<string>> all_fimaly;

    {
        all_fimaly["yang"] = {"fan yang","zheng yang"};
        all_fimaly["Liu"] = {"li liu","fenjing liu"};
        all_fimaly["zhang"] = {"sanfeng zhang","fei zhang"};
        all_fimaly["wang"] = {"wu wang","batian wang"};
    }

    string search_word;
    cout << "please enter a first name to search children (q to quit):";
    cin >> search_word;
    while (search_word.size() && search_word != "q")
    {
        map<string ,vector<string>>::const_iterator iter;
        if((iter = all_fimaly.find(search_word)) != all_fimaly.end())
        {   
            cout << " We find ";
            for(auto child :iter->second)
                cout << child << ", ";
        }    
        else
            cout <<search_word << " was not found in all fimalies.";
        cout << "Another seasrch? Or q to quit. ";
        cin >> search_word;
    }    
    return 0;
}