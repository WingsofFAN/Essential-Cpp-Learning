#include <iostream>

using namespace std;

const char* msg_to_usr(int num_tries)
{
    static const char* usr_msgs[] = {
        "Oops! Nice guess but not quite it!",
        "Hmm. Sorry Wong a second time.",
        "Ah, this is harder than it looks,isn't it?",
        "It must be getting pretty frustrating by now!"
    };

    if(num_tries < 0)
        num_tries = 0;
    else if(num_tries >= 4)
        num_tries = 3;

    return usr_msgs[num_tries];

}


int main()
{
    string first_name ,last_name;
    cout  << "Please enter your first name:" ;
    cin >> first_name;
    cout << "Hi，" << first_name << ". Please enter your last name: ";
    cin >> last_name;
    int num ;
    cout << "Now," << last_name << " " << first_name << " ! we guess a luck num:";

    for(int i = 0; i < 5 ;i++)
    {
        cin >> num;
        if(num != 13)
        {
            switch (i)
            {
                case 0:
                    cout << msg_to_usr(0);
                    break;
                case 1:
                    cout << msg_to_usr(1);
                    break;
                case 2:
                    cout << msg_to_usr(2);
                    break;
                default:
                    cout << msg_to_usr(3);
                    break;
            }
        }    
        else
            cout << "You are so celever!" << endl;
   
    } 
    return 0;
}