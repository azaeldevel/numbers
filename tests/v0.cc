
#include <iostream>

#include "v0.hh"
#include <0/equation.hh>
#include <0/vector.hh>
#include <0/arithmetic.hh>
#include <0/matrix.hh>
#include <0/algebra.hh>


namespace numbers_here = oct::nums::v0;



void v0_developing()
{
}


void v0_algebra()
{
    numbers_here::Monomio<int,size_t,3> mono1(1);
    numbers_here::Monomio<int,size_t,3> mono2 {2,2,3,5};
    mono2.print(std::cout,'x');
}

void v0_arithmetic()
{
    //numbers_here::PrimeNumbers<numbers_here::CaseNumber<size_t>,size_t,1000> primes;
    //primes.erastostenes();
    /*for(size_t i = 2; i < 1000; i++)
    {
        std::cout << primes[i].number << " es ";
        if(primes[i].prime) std::cout << " primo.\n";
        else std::cout << " compuesto.\n";
    }*/
    //primes.print(std::cout);

    //constexpr numbers_here::PrimeNumbers<numbers_here::CaseNumber<size_t>,size_t,1000> primes2;

    /*numbers_here::secuence<size_t,size_t,10000> primes3(0);
    numbers_here::init(primes3);
    numbers_here::erastos(primes3);*/
    //numbers_here::print(std::cout,primes3);

    numbers_here::Primes<size_t,size_t,1000> primes4;
    primes4.erastos();
    //primes4.print(std::cout);
    CU_ASSERT(primes4[0] == 0);
    CU_ASSERT(primes4[1] == 0);
    CU_ASSERT(primes4[2] == 2);
    CU_ASSERT(primes4[3] == 3);
    CU_ASSERT(primes4[4] == 0);
    CU_ASSERT(primes4[5] == 5);
    CU_ASSERT(primes4[6] == 0);
    CU_ASSERT(primes4[7] == 7);
    CU_ASSERT(primes4[8] == 0);
    CU_ASSERT(primes4[9] == 0);

}

void v0_matrix()
{
    numbers_here::matrix<int,3ul,3ul,float> mx1(1);
    CU_ASSERT(sizeof(mx1) == sizeof(int) * 3 * 3);
    //std::cout << "Size : " << sizeof(mx1) << "\n";
    //mx1.printLn(std::cout);

    numbers_here::matrix<int,1ul,3ul,float> mx2(1);
    CU_ASSERT(sizeof(mx2) == sizeof(int) * 1 * 3);
    //std::cout << "Size : " << sizeof(mx2) << "\n";
    //mx2.printLn(std::cout);

    numbers_here::matrix<int,1ul,1ul,float> mx3(5);
    CU_ASSERT(sizeof(mx3) == sizeof(int) * 1 * 1);
    //std::cout << "Size : " << sizeof(mx3) << "\n";
    //mx3.printLn(std::cout);

    numbers_here::matrix<int,3ul,3ul,float> mx4(5);
    numbers_here::matrix<int,3ul,3ul,float> mx5(7);
    numbers_here::matrix<int,3ul,3ul,float> mx6 = mx4 + mx5;
    //mx6.printLn(std::cout);
    CU_ASSERT(mx6[0][0] == 12);
    CU_ASSERT(mx6[1][0] == 12);
    CU_ASSERT(mx6[2][0] == 12);
    CU_ASSERT(mx6[1][1] == 12);
    CU_ASSERT(mx6[2][2] == 12);

    numbers_here::matrix<int,3ul,3ul,float> mx7 = mx5 - mx4;
    CU_ASSERT(mx7[0][0] == 2);
    CU_ASSERT(mx7[1][0] == 2);
    CU_ASSERT(mx7[2][0] == 2);
    CU_ASSERT(mx7[1][1] == 2);
    CU_ASSERT(mx7[2][2] == 2);

    numbers_here::matrix<int,3ul,3ul,float> mx8 = mx5 * 3;
    CU_ASSERT(mx8[0][0] == 21);
    CU_ASSERT(mx8[1][0] == 21);
    CU_ASSERT(mx8[2][0] == 21);
    CU_ASSERT(mx8[1][1] == 21);
    CU_ASSERT(mx8[2][2] == 21);

    numbers_here::matrix<int,3ul,2ul,float> mx9;
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

    numbers_here::matrix<int,2ul,3ul,float> mx10;
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

    numbers_here::matrix<int,2ul,2ul,float> mx11 = mx9 * mx10;
    //mx11.printLn(std::cout);
    //std::cout << "Columns : " << mx11.columns() << "\n";
    //std::cout << "Rows : " << mx11.rows() << "\n";
    CU_ASSERT(mx11[0][0] == 4);
    CU_ASSERT(mx11[0][1] == 5);
    CU_ASSERT(mx11[1][0] == -3);
    CU_ASSERT(mx11[1][1] == -7);

    numbers_here::matrix<int,2ul,2ul,float> mx12;
    mx12[0][0] = 2;
    mx12[0][1] = 0;
    mx12[1][0] = -1;
    mx12[1][1] = 3;
    CU_ASSERT(mx12[0][0] == 2);
    CU_ASSERT(mx12[0][1] == 0);
    CU_ASSERT(mx12[1][0] == -1);
    CU_ASSERT(mx12[1][1] == 3);
    //std::cout << "det A : " << mx12.det() << "\n";
    CU_ASSERT(mx12.det()  == 6);

    numbers_here::matrix<int,2ul,2ul,float> mx13;
    mx13[0][0] = 5;
    mx13[0][1] = -2;
    mx13[1][0] = 4;
    mx13[1][1] = 1;
    CU_ASSERT(mx13[0][0] == 5);
    CU_ASSERT(mx13[0][1] == -2);
    CU_ASSERT(mx13[1][0] == 4);
    CU_ASSERT(mx13[1][1] == 1);
    //std::cout << "det A : " << mx13.det() << "\n";
    CU_ASSERT(mx13.det()  == 13);

    numbers_here::matrix<int,4ul,3ul,float> mx14;
    mx14[0] = {0,2,4,1};
    //eqSA[0] = 10;
    mx14[1] = {-2,5,-12,-6};
    //eqSA[1] = 10;
    mx14[2] = {1,-1,3,3};
    //eqSA[2] = 1;

    numbers_here::matrix<int,3ul,3ul,float> mx15;
    mx15[0][0] = 1;
    mx15[0][1] = 3;
    mx15[0][2] = 3;
    mx15[1][0] = -2;
    mx15[1][1] = 1;
    mx15[1][2] = 1;
    mx15[2][0] = 0;
    mx15[2][1] = 4;
    mx15[2][2] = 4;

    auto mx16 = mx15.sub(0,1);
    CU_ASSERT(mx16.rows() == 2);
    CU_ASSERT(mx16.columns() == 2);
    auto mx17 = mx16.sub(0,0);
    CU_ASSERT(mx17.rows() == 1);
    CU_ASSERT(mx17.columns() == 1);

    //std::vector<int> exclus;
    //exclus.push_back(1);
    //numbers_here::matrix<int,2,2,float> mx16 = mx15.sub<int,2,2>(exclus,exclus,true);
    //numbers_here::matrix<int,2,2,float> mx17 = mx15.sub<int,2,2>(1,1);
    //mx16.print(std::cout);
}


void v0_equation()
{
    numbers_here::equation<int,1ul,1ul,float> eq1({2},50);
    //std::cout << "Size : " << sizeof(eq1) << "\n";
    CU_ASSERT(sizeof(eq1) == 8);
    CU_ASSERT(eq1.c() == 50);
    CU_ASSERT(eq1.a(0) == 2);
    //std::cout << "eq1.x() : " << eq1.x() << "\n";
    CU_ASSERT(numbers_here::resolve(eq1) == 25);

    numbers_here::equation<int,2ul,1ul,float> eq2({-3,5},4);
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

    numbers_here::equation<int,4ul,1ul,float> eqSA[3];
    eqSA[0] = {0,2,4,1};
    eqSA[0] = 10;
    eqSA[1] = {-2,5,-12,-6};
    eqSA[1] = 10;
    eqSA[2] = {1,-1,3,3};
    eqSA[2] = 1;
    CU_ASSERT(eqSA[0][0] == 0);
    CU_ASSERT(eqSA[0][1] == 2);
    CU_ASSERT(eqSA[0][2] == 4);
    CU_ASSERT(eqSA[0][3] == 1);
    //numbers_here::resolve(eqSA,3);

}


void v0_secuence()
{
    numbers_here::secuence<int,size_t,1ul> sec1(1);
    CU_ASSERT(sizeof(sec1) == sizeof(int));
    CU_ASSERT(sec1[0] == 1);

    numbers_here::secuence<int,size_t,2ul> sec2(1);
    CU_ASSERT(sizeof(sec2) == sizeof(int) * 2);
    CU_ASSERT(sec2[0] == 1);
    CU_ASSERT(sec2[1] == 1);

    numbers_here::secuence<int,size_t,3ul> sec3(1);
    CU_ASSERT(sizeof(sec3) == sizeof(int) * 3);
    CU_ASSERT(sec3[0] == 1);
    CU_ASSERT(sec3[1] == 1);
    CU_ASSERT(sec3[2] == 1);

    constexpr numbers_here::secuence<int,size_t,3ul> sec4(1);

    numbers_here::secuence<int,size_t,10> sec5(1);
    CU_ASSERT(sizeof(sec5) == sizeof(int) * sec5.size());
    CU_ASSERT(sec5[0] == 1);
    CU_ASSERT(sec5[1] == 1);
    CU_ASSERT(sec5[2] == 1);
    CU_ASSERT(sec5[9] == 1);

    numbers_here::secuence<unsigned long long,unsigned long long,10> sec6(1);
    CU_ASSERT(sizeof(sec6) == sizeof(unsigned long long) * sec6.size());
    CU_ASSERT(sec6[0] == 1);
    CU_ASSERT(sec6[1] == 1);
    CU_ASSERT(sec6[2] == 1);
    CU_ASSERT(sec6[9] == 1);
}

void v0_vector()
{
    numbers_here::vector<int,2ul,float> vect1(4,-3);
    CU_ASSERT(vect1.x() == 4);
    CU_ASSERT(vect1.y() == -3);


    numbers_here::vector<int,3ul,float> vect2(4,-3,5);
    CU_ASSERT(vect2.x() == 4);
    CU_ASSERT(vect2.y() == -3);
    CU_ASSERT(vect2.z() == 5);

    numbers_here::vector<int,3ul,float> vect3 {4,-3,5};
    CU_ASSERT(vect3.x() == 4);
    CU_ASSERT(vect3.y() == -3);
    CU_ASSERT(vect3.z() == 5);

    constexpr numbers_here::vector<int,3ul,float> vect5 {4,-3,5};

    numbers_here::secuence<numbers_here::secuence<int,size_t,3ul>,size_t,numbers_here::factorial(3ul)> pers;
    numbers_here::vector<int,3ul,float> vect4 {4,-3,5};
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
    CU_ASSERT(numbers_here::factorial(3ul) == 6);
    CU_ASSERT(numbers_here::factorial(6ul) == 720);
}


int v0_init(void)
{


	return 0;
}
int v0_clean(void)
{


	return 0;
}
