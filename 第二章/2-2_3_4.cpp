#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline bool is_ok(int pos)
{
    const int max_size = 1024;
    if(pos < 0 || pos > max_size  || pos*(3*pos-1)/2 > numeric_limits<int>::max()-10)
    {
        cerr<< "Oops: requested size is not supported : "
            << pos << "-- can't fulfill request.\n";
        return false;
    }
    return true;
}

const vector<int>* pentagonal_series(int pos)
{
    static vector<int> _elems;
    if( is_ok(pos) && pos > _elems.size())
    {
        for(int i = _elems.size()+1; i <= pos;i++)
            _elems.push_back(i*(i*3-1)/2);
    }
    return &_elems;
}


bool pentagonal_elem(int pos, int & elem)
{
    if(is_ok(pos))
    {
        const vector<int> *penta = pentagonal_series(pos);
        elem = (*penta)[pos-1];
        return true;
    }
    else
    {
        elem = 0;
        return false;
    }
}


int main()
{
    int elem;
    vector<int> test_num = {1,5,6,8,21,88,12,3,1345};
    for(int i = 0 ; i < test_num.size() ; i++)
        if(pentagonal_elem(test_num[i],elem))
            cout << "element " << test_num[i] << " is " << elem << endl; 

    return 0;
}
