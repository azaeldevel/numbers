
#include <iostream>

#include "v0.hh"
#include <0/equation.hh>
#include <0/vector.hh>


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
    numbers_here::secuence<int,1,float> sec1(1);
    CU_ASSERT(sizeof(sec1) == sizeof(int));

    numbers_here::secuence<int,2,float> sec2(1);
    CU_ASSERT(sizeof(sec2) == sizeof(int) * 2);

    numbers_here::secuence<int,3,float> sec3(1);
    CU_ASSERT(sizeof(sec3) == sizeof(int) * 3);

    numbers_here::first<int,1,float> eq1(50,2);
    //std::cout << "Size : " << sizeof(eq1) << "\n";
    CU_ASSERT(sizeof(eq1) == 8);
    CU_ASSERT(eq1.c() == 50);
    CU_ASSERT(eq1.a() == 2);
    //std::cout << "eq1.x() : " << eq1.x() << "\n";
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


    numbers_here::vector<int,2,float> vect1(4,-3);
    CU_ASSERT(vect1.x() == 4);
    CU_ASSERT(vect1.y() == -3);


    numbers_here::vector<int,3,float> vect2(4,-3,5);
    CU_ASSERT(vect2.x() == 4);
    CU_ASSERT(vect2.y() == -3);
    CU_ASSERT(vect2.z() == 5);

    numbers_here::vector<int,3,float> vect3 {4,-3,5};
    CU_ASSERT(vect3.x() == 4);
    CU_ASSERT(vect3.y() == -3);
    CU_ASSERT(vect3.z() == 5);
}




