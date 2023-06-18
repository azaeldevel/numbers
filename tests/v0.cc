
#include <iostream>

#include "v0.hh"
#include <0/equation.hh>


namespace numbers_here = oct::nums::v0;


int v0_init(void)
{


	return 0;
}
int v0_clean(void)
{


	return 0;
}


void v0_developing()
{
    numbers_here::first<int,1,float> eq1(50,2);
    //std::cout << "Size : " << sizeof(eq1) << "\n";
    CU_ASSERT(sizeof(eq1) == 8);
    CU_ASSERT(eq1.c() == 50);
    CU_ASSERT(eq1.a() == 2);
    CU_ASSERT(eq1.x() == 25);


    numbers_here::first<int,2,float> eq2(4,-3,5);
    CU_ASSERT(eq2.c() == 4);
    CU_ASSERT(eq2.a() == -3);
    CU_ASSERT(eq2.b() == 5);
    //std::cout << "Size : " << sizeof(eq2) << "\n";
    CU_ASSERT(sizeof(eq2) == 12);
    float rest1[9];
    for(int i = -4; i < 5; i++)
    {
        rest1[i + 4] = eq2.y(i);
        //std::cout << "(" << i << "," << rest1[i + 4] << ")\n";
    }
    CU_ASSERT(abs(rest1[0] + 1.6) < infimium);
    CU_ASSERT(abs(rest1[4] - 0.8) < infimium);
    CU_ASSERT(abs(rest1[8] - 3.2) < infimium);
}




