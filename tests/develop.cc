
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

int main ()
{
    std::vector<int> myints = {1,2,3,4,5};

    std::sort (myints.begin(),myints.end());

    std::cout << "The " << myints.size() << "! possible permutations with " << myints.size() << " elements:\n";
    do
    {
        for(size_t i = 0; i < myints.size(); i++)
        {
            std::cout << myints[i] << ' ';
        }
        std::cout << "\n";
    }
    while ( std::next_permutation(myints.begin(),myints.end()) );

    std::cout << "After loop: ";
    for(size_t i = 0; i < myints.size(); i++)
    {
        std::cout << myints[i] << ' ';
    }
    std::cout << "\n" ;

    return 0;
}
