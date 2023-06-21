
#include <iostream>

#include "v0.hh"
#include <0/equation.hh>
#include <0/vector.hh>


namespace numbers_here = oct::nums::v0;



void v0_developing()
{

}

void v0_matrix()
{
    numbers_here::matrix<int,3,3,float> mx1(1);
    CU_ASSERT(sizeof(mx1) == sizeof(int) * 3 * 3);
    //std::cout << "Size : " << sizeof(mx1) << "\n";
    //mx1.printLn(std::cout);

    numbers_here::matrix<int,1,3,float> mx2(1);
    CU_ASSERT(sizeof(mx2) == sizeof(int) * 1 * 3);
    //std::cout << "Size : " << sizeof(mx2) << "\n";
    //mx2.printLn(std::cout);

    numbers_here::matrix<int,1,1,float> mx3(5);
    CU_ASSERT(sizeof(mx3) == sizeof(int) * 1 * 1);
    //std::cout << "Size : " << sizeof(mx3) << "\n";
    //mx3.printLn(std::cout);

    numbers_here::matrix<int,3,3,float> mx4(5);
    numbers_here::matrix<int,3,3,float> mx5(7);
    numbers_here::matrix<int,3,3,float> mx6 = mx4 + mx5;
    //mx6.printLn(std::cout);
    CU_ASSERT(mx6[0][0] == 12);
    CU_ASSERT(mx6[1][0] == 12);
    CU_ASSERT(mx6[2][0] == 12);
    CU_ASSERT(mx6[1][1] == 12);
    CU_ASSERT(mx6[2][2] == 12);

    numbers_here::matrix<int,3,3,float> mx7 = mx5 - mx4;
    CU_ASSERT(mx7[0][0] == 2);
    CU_ASSERT(mx7[1][0] == 2);
    CU_ASSERT(mx7[2][0] == 2);
    CU_ASSERT(mx7[1][1] == 2);
    CU_ASSERT(mx7[2][2] == 2);

    numbers_here::matrix<int,3,3,float> mx8 = mx5 * 3;
    CU_ASSERT(mx8[0][0] == 21);
    CU_ASSERT(mx8[1][0] == 21);
    CU_ASSERT(mx8[2][0] == 21);
    CU_ASSERT(mx8[1][1] == 21);
    CU_ASSERT(mx8[2][2] == 21);

    numbers_here::matrix<int,3,2,float> mx9;
    mx9[0][0] = 2;
    mx9[0][1] = -1;
    mx9[0][2] = 0;
    mx9[1][0] = 1;
    mx9[1][1] = 2;
    mx9[1][2] = -3;
    CU_ASSERT(mx9[0][0] == 2);
    CU_ASSERT(mx9[0][1] == -1);
    CU_ASSERT(mx9[0][2] == 0);
    CU_ASSERT(mx9[1][0] == 1);
    CU_ASSERT(mx9[1][1] == 2);
    CU_ASSERT(mx9[1][2] == -3);

    numbers_here::matrix<int,2,3,float> mx10;
    mx10[0][0] = 1;
    mx10[0][1] = 3;
    mx10[1][0] = -2;
    mx10[1][1] = 1;
    mx10[2][0] = 0;
    mx10[2][1] = 4;
    CU_ASSERT(mx10[0][0] == 1);
    CU_ASSERT(mx10[0][1] == 3);
    CU_ASSERT(mx10[1][0] == -2);
    CU_ASSERT(mx10[1][1] == 1);
    CU_ASSERT(mx10[2][0] == 0);
    CU_ASSERT(mx10[2][1] == 4);

    numbers_here::matrix<int,2,2,float> mx11 = mx9 * mx10;
    //mx11.printLn(std::cout);
    //std::cout << "Columns : " << mx11.columns() << "\n";
    //std::cout << "Rows : " << mx11.rows() << "\n";
    CU_ASSERT(mx11[0][0] == 4);
    CU_ASSERT(mx11[0][1] == 5);
    CU_ASSERT(mx11[1][0] == -3);
    CU_ASSERT(mx11[1][1] == -7);
}


void v0_equation()
{

    numbers_here::equation<int,1,1,float> eq1(50,numbers_here::vector<int,1,float>(2));
    //std::cout << "Size : " << sizeof(eq1) << "\n";
    CU_ASSERT(sizeof(eq1) == 8);
    CU_ASSERT(eq1.c() == 50);
    CU_ASSERT(eq1.a(0) == 2);
    //std::cout << "eq1.x() : " << eq1.x() << "\n";
    CU_ASSERT(numbers_here::resolve(eq1) == 25);


    numbers_here::equation<int,2,1,float> eq2(4,{-3,5});
    CU_ASSERT(eq2.c() == 4);
    CU_ASSERT(eq2[0] == -3);
    CU_ASSERT(eq2[1] == 5);
    //std::cout << "Size : " << sizeof(eq2) << "\n";
    CU_ASSERT(sizeof(eq2) == 12);
    float rest1[9];
    for(int i = -4; i < 5; i++)
    {
        rest1[i + 4] = numbers_here::resolve(eq2,1,i);
        //std::cout << "(" << i << "," << rest1[i + 4] << ")\n";
    }
    CU_ASSERT(abs(rest1[0] + 1.6) < infimium);
    CU_ASSERT(abs(rest1[4] - 0.8) < infimium);
    CU_ASSERT(abs(rest1[8] - 3.2) < infimium);

    numbers_here::matrix<int,3,3,float> mx1;
    numbers_here::equation<numbers_here::matrix<int,3,3,float>,3,3,float> eq3(4,mx1);
}


void v0_secuence()
{
    numbers_here::secuence<int,1> sec1(1);
    CU_ASSERT(sizeof(sec1) == sizeof(int));
    CU_ASSERT(sec1[0] == 1);

    numbers_here::secuence<int,2> sec2(1);
    CU_ASSERT(sizeof(sec2) == sizeof(int) * 2);
    CU_ASSERT(sec2[0] == 1);
    CU_ASSERT(sec2[1] == 1);

    numbers_here::secuence<int,3> sec3(1);
    CU_ASSERT(sizeof(sec3) == sizeof(int) * 3);
    CU_ASSERT(sec3[0] == 1);
    CU_ASSERT(sec3[1] == 1);
    CU_ASSERT(sec3[2] == 1);

    constexpr numbers_here::secuence<int,3> sec4(1);
}

void v0_vector()
{
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

    constexpr numbers_here::vector<int,3,float> vect5 {4,-3,5};

    numbers_here::secuence<numbers_here::secuence<int,3>,numbers_here::factorial(3)> pers;
    numbers_here::vector<int,3,float> vect4 {4,-3,5};
    vect4.permutation(pers);
    /*
    for(size_t i = 0; i < pers.size(); i++)
    {
        pers[i].printLn(std::cout);
    }
    */
    //CU_ASSERT(pers[0] == {4,-3,5});s
}

void v0_funtions()
{
    CU_ASSERT(numbers_here::factorial(3) == 6);
    CU_ASSERT(numbers_here::factorial(6) == 720);
}


int v0_init(void)
{


	return 0;
}
int v0_clean(void)
{


	return 0;
}
