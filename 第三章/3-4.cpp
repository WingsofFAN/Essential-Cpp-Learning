#include<iostream>
#include<iterator>  //好东西，不用写循环处理输入了 耶！
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

class even_elem
{
public:
    bool operator()(int  elem)
    {
        return elem%2?false:true;
    }
};



int main()
{
    vector<int> input;
    istream_iterator<int> in(cin),eos; // 用迭代器in绑定标准输入如cin
    copy(in,eos,back_inserter(input)); //把迭代器的内容依次拷贝到input中

    vector<int>::iterator division = partition(input.begin(),input.end(),even_elem());

    ofstream even_file("even.txt"),odd_file("odd.txt");
    if( !even_file || !odd_file )
    {
        cerr << " Unable to open file -- bailing out!\n";
        return -1;
    }

    ostream_iterator<int> even_iter(even_file,"\n"),odd_iter(odd_file," ");
    copy(input.begin(),division,even_iter);
    copy(division,input.end(),odd_iter);

    even_file.close();odd_file.close();
    return 0;


}