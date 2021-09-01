
#include<iostream>
#include<string>


int main()
{
    
    std::cout << "What is your name?"<< std::endl;


    std::string name;
    std::cin >> name ; //自动以空客和回车作为分割，因此输入时要慎用空格
   
    
    if(name.length() == 0)
    {
        std::cout << " Oh! There is no name!" <<std::endl; 
    } 
    else if(name.length() > 128)
    {
        std::cout << "You name is too to remeber!" << std::endl;
    }
    else
    {
        std::cout << "Hello, " << name << "! Good luck to you!" <<std::endl; 
    }

    return 0;
}


