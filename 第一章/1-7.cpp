#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    ifstream readf("1-7.txt");
    
    if(!readf.is_open())
    {
        cout << " Can not open 1-7.txt ! "<<endl;
        return 0;
    }

    vector<string> out;
    string temp;
    while (getline(readf,temp))
    {
        out.push_back(temp);
    }
    readf.close();

    sort(out.begin(),out.end());
    


    ofstream writef("1-7out.txt");
    for(auto pp : out)
        writef << pp << endl;
    writef.close();

    return 0;
    

}