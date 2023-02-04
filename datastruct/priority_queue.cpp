#include <iostream>
#include <set>

int main()
{
    std::set<int> set = {1, 2, 3, 4, 5};

    set.insert(5);
    set.erase(3);

    for (const auto &value : set)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}