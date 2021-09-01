#include<iostream>
#include<iomanip>
#include<cstring>

int main()
{
    
    std::cout << "What is your name?"<< std::endl;


    const int nm_size = 128;
    char name[nm_size];
    std::cin >> std::setw(nm_size) >> name; //可以控制输入多少字符，最长到nm_size,但是空格也会出问题
 
    if(std::strlen(name) == 0)
    {
        std::cout << " Oh! There is no name!" <<std::endl; 
    } 
    else if(std::strlen(name) > 128)
    {
        std::cout << "You name is too to remeber!" << std::endl;
    }
    else
    {
        std::cout << "Hello, " << name << "! Good luck to you!" <<std::endl; 
    }

    return 0;
}