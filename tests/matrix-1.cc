


#include <numbers/0/matrix.hh>
namespace numbers = oct::nums::v0;


int main()
{

    numbers::core::array<int> arr1 {3,-2,1,5,6,2,1,0,-3};
    numbers::core::array<int,9> arr2 {3,-2,1,5,6,2,1,0,-3};

    numbers::matrix<int> mx124(3,3,(int*)arr2);

    numbers::core::array<int> arr3 {3,-2,1};
    numbers::matrix<int> mx125(3,1,(int*)arr3);
    //mx125.print(std::cout);


    numbers::matrix<int> mx126({3,1,3,-2,1});

    numbers::matrix<int> mx127;
    mx127 = (mx124 * mx126) + mx125;
    //mx127.print(std::cout);
    mx127 = (mx124 * mx126) + mx125;
    //mx127.print(std::cout);
    mx127 = (mx124 * mx126) + mx125;
    //mx127.print(std::cout);

   return 0;
}
