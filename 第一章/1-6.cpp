#include <iostream>
#include <vector>

int main()
{
    const int N = 1e5+10;
    std::vector<int>  Vec;
    int array[N];

    int t,i = 0;
    while (std::cin >> t)
    {
        array[i++] = t;
        Vec.push_back(t);
    }

    int p = 0,sum_arr = 0;
    while (p < i)
    {
        std::cout << array[p] << " ";
        sum_arr += array[p++];
    }
    std::cout << std::endl << "arr_sum: " << sum_arr << std::endl;

    int sum_vec = 0;
    for(auto pp : Vec)
    {
        std::cout <<pp  << " ";
        sum_vec += pp;
    }
    std::cout << std::endl << "vec_sum: " << sum_vec << std::endl;
    return 0;
}