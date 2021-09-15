#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//理解有误

// template <typename elemType>
// elemType my_max(elemType p1,elemType p2)
// {
//     if(p1 > p2)
//         return p1;
//     else
//         return p2;
// }


// int main()
// {
//     int a = 10,b =-20;
//     cout << my_max(a,b) << endl;

//     float c = 10.123,d =10.23131;
//     cout << my_max(c,d) << endl;

//     string str1 = "Hahahaha" ,str2 ="Hehehehe";
//     cout << my_max(str1,str2) << endl;

//     vector<int> list1 = {1,2,3,4,5},list2 = {5,4,3,2,1};
//     for(auto pp:my_max(list1,list2))
//         cout << pp << " ";
//     cout << endl;

//     vector<float> list3 = {1.2,2.3,3.4,4.5,5.6},list4 = {5.1,4.2,3.3,2.4,1.5};
//     for(auto pp:my_max(list3,list4))
//         cout << pp << " ";
//     cout << endl;

//     vector<string> list5 = {"hello","world","Duang"},list6 = {"I","am","good","man"};
//     for(auto pp:my_max(list5,list6))
//         cout << pp << " ";
//     cout << endl;

//     int ll1[] = {1,2,3,4,5},ll2[] = {5,4,3,2,1};
//     int* T1 = my_max(ll1,ll2);
//     for(int i = 0 ; i < 5 ;i++)
//         cout << T1[i] << " ";
//     cout << endl;

//     float ll3[] = {1.2,2.3,3.4,4.5,5.6},ll4[] = {5.1,4.2,3.3,2.4,1.5};
//     float* T2 = my_max(ll3,ll4);
//     for(int i = 0; i < 5;i++)
//         cout << T2[i] << " ";
//     cout << endl;

//     string ll5[] = {"hello","world","Duang"},ll6[] = {"I","am","good","man"};

//     //这里送入比较，比较的也许是地址的值，即指针
//     string* T3 = my_max(ll5,ll6);
//     for(int i = 0 ; i < 4;i++)
//         cout << T3[i] << " ";
//     cout << endl;


//     return 0;
// }

//模板函数+重载
template <typename elemType>
inline elemType my_max(elemType p1,elemType p2)
{
    if(p1 > p2)
        return p1;
    else
        return p2;
}

template <typename elemType>
inline elemType my_max(const vector<elemType> &vec )
{
    return *max_element(vec.begin(),vec.end());
}

template <typename elemType>
inline elemType my_max(const elemType *vec, int size )
{
    return *max_element(vec,vec+size);
}


int main()
{
    int a = 10,b =-20;
    cout << my_max(a,b) << endl;

    float c = 10.123,d =10.23131;
    cout << my_max(c,d) << endl;

    string str1 = "Hahahaha" ,str2 ="Hehehehe";
    cout << my_max(str1,str2) << endl;

    vector<int> list1 = {1,2,3,4,5};
    cout << my_max(list1) << endl;

    vector<float> list3 = {1.2,2.3,3.4,4.5,5.6};
    cout << my_max(list3)<<endl;

    vector<string> list5 = {"hello","world","Duang"};
    cout << my_max(list5)<< endl;

    int ll1[] = {1,2,3,4,5};
    cout << my_max(ll1,5) <<endl;

    float ll3[] = {1.2,2.3,3.4,4.5,5.6};
    cout << my_max(ll3,5) << endl;

    string ll5[] = {"I","am","good","man"};
    cout << my_max(ll5,4) << endl;

    return 0;
}