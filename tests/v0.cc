
#include <iostream>
#include<iomanip>


#include "v0.hh"
#include <0/equation.hh>
#include <0/vector.hh>
#include <0/arithmetic.hh>
#include <0/matrix.hh>
#include <0/algebra.hh>
#include <0/shapes.hh>


namespace numbers_here = oct::nums::v0;
namespace numbers = oct::nums::v0;



void v0_developing()
{

}


void v0_shapes()
{
    numbers_here::core::array<float,3> seq1(0);

    constexpr numbers_here::vector<float> vec1(0,0,0);
    constexpr numbers_here::Triangle<float> tri1(vec1, 1.0);
    //tri1[0].printLn(std::cout);
    //tri1[1].printLn(std::cout);
    //tri1[2].printLn(std::cout);
    //tri1.printLn(std::cout);
    CU_ASSERT_DECIMAL(tri1[0].x(),0, infimium);
    CU_ASSERT_DECIMAL(tri1[0].y(),0.433013, infimium);
    CU_ASSERT_DECIMAL(tri1[0].z(),0, infimium);
    CU_ASSERT_DECIMAL(tri1[1].x(),0.5, infimium);
    CU_ASSERT_DECIMAL(tri1[1].y(),-0.433013, infimium);
    CU_ASSERT_DECIMAL(tri1[1].z(),0, infimium);
    CU_ASSERT_DECIMAL(tri1[2].x(),-0.5, infimium);
    CU_ASSERT_DECIMAL(tri1[2].y(),-0.433013, infimium);
    CU_ASSERT_DECIMAL(tri1[2].z(),0, infimium);

    constexpr numbers_here::vector<float> vec2(0,0,1);
    constexpr numbers_here::Pyramid pyramid(tri1, vec2);
    //pyramid.printLn(std::cout);
    CU_ASSERT_DECIMAL(pyramid[0].x(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[0].y(),0.433013, infimium);
    CU_ASSERT_DECIMAL(pyramid[0].z(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[1].x(),0.5, infimium);
    CU_ASSERT_DECIMAL(pyramid[1].y(),-0.433013, infimium);
    CU_ASSERT_DECIMAL(pyramid[1].z(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[2].x(),-0.5, infimium);
    CU_ASSERT_DECIMAL(pyramid[2].y(),-0.433013, infimium);
    CU_ASSERT_DECIMAL(pyramid[2].z(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[3].x(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[3].y(),0, infimium);
    CU_ASSERT_DECIMAL(pyramid[3].z(),1, infimium);


    constexpr numbers_here::vector<float> vec3(0,0,0);
    constexpr numbers_here::Rectangle<float> rec1(vec3, 1.0);
    //rec1.printLn(std::cout);


    constexpr numbers_here::vector<float> vec4(0,0,0);
    constexpr numbers_here::Circle<float,3,200> cir1(vec4, 1.0);
    //cir1.printLn(std::cout);

    constexpr numbers_here::Shape<int,3,2,int> shape1{-1,9,2,6,8,3};
    CU_ASSERT(shape1[0].x() == -1);
    CU_ASSERT(shape1[0].y() == 9);
    CU_ASSERT(shape1[0].z() == 2);
    CU_ASSERT(shape1[1].x() == 6);
    CU_ASSERT(shape1[1].y() == 8);
    CU_ASSERT(shape1[1].z() == 3);

    constexpr numbers_here::Line<int,3> line1{-1,9,2,6,8,3};
    CU_ASSERT(line1[0].x() == -1);
    CU_ASSERT(line1[0].y() == 9);
    CU_ASSERT(line1[0].z() == 2);
    CU_ASSERT(line1[1].x() == 6);
    CU_ASSERT(line1[1].y() == 8);
    CU_ASSERT(line1[1].z() == 3);

    constexpr numbers_here::Triangle<int> tri2{0,0,0,1,1,1,2,2,2};
    CU_ASSERT(tri2[0].x() == 0);
    CU_ASSERT(tri2[0].y() == 0);
    CU_ASSERT(tri2[0].z() == 0);
    CU_ASSERT(tri2[1].x() == 1);
    CU_ASSERT(tri2[1].y() == 1);
    CU_ASSERT(tri2[1].z() == 1);
    CU_ASSERT(tri2[2].x() == 2);
    CU_ASSERT(tri2[2].y() == 2);
    CU_ASSERT(tri2[2].z() == 2);
}

void v0_algebra()
{
    numbers_here::Monomio<int,3> mono1(1);
    numbers_here::Monomio<int,3> mono2 {2,2,3,5};
    numbers_here::Monomio<int,3> mono3 {-9,2,7,3};
    numbers_here::Monomio<int,3> mono4 = mono3 + mono2;
    CU_ASSERT(mono4[0] == -7);
    CU_ASSERT(mono4[1] == 4);
    CU_ASSERT(mono4[2] == 10);
    CU_ASSERT(mono4[3] == 8);
    numbers_here::Monomio<int,3> mono5 = mono3 - mono2;
    CU_ASSERT(mono5[0] == -11);
    CU_ASSERT(mono5[1] == 0);
    CU_ASSERT(mono5[2] == 4);
    CU_ASSERT(mono5[3] == -2);


    //mono4.print(std::cout,'x');
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

    /*numbers_here::sequence<size_t,size_t,10000> primes3(0);
    numbers_here::init(primes3);
    numbers_here::erastos(primes3);*/
    //numbers_here::print(std::cout,primes3);

    numbers_here::Primes<size_t,1000> primes4;
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
    CU_ASSERT(primes4[10] == 0);
    CU_ASSERT(primes4[11] == 11);
    CU_ASSERT(primes4[12] == 0);
    CU_ASSERT(primes4[13] == 13);
    CU_ASSERT(primes4[14] == 0);
    CU_ASSERT(primes4[15] == 0);
    CU_ASSERT(primes4[16] == 0);
    CU_ASSERT(primes4[17] == 17);
    CU_ASSERT(primes4[18] == 0);
    CU_ASSERT(primes4[19] == 19);
    CU_ASSERT(primes4[20] == 0);

}

void v0_matrix()
{
    numbers_here::matrix<int,3ul,3ul,float> mx1(1);
    CU_ASSERT(sizeof(mx1) == sizeof(int) * 9);
    //std::cout << "Size matrix : " << sizeof(mx1) << "\n";
    //std::cout << "Size int : " << sizeof(int) << "\n";
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

    auto mx11 = mx9 * mx10;
    //mx11.printLn(std::cout);
    //std::cout << "Columns : " << mx11.columns() << "\n";
    //std::cout << "Rows : " << mx11.rows() << "\n";
    CU_ASSERT(mx11.columns() == 2);
    CU_ASSERT(mx11.rows() == 2);
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
    //CU_ASSERT(mx12.det()  == 6);

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
    //CU_ASSERT(mx13.det()  == 13);

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

    numbers_here::matrix<int,1,3,float> mx16;
    mx16[0][0] = 0;
    //eqSA[0] = 10;
    mx16[1][0] = -2;
    //eqSA[1] = 10;
    mx16[2][0] = 1;

    numbers_here::matrix<float,3,3,float> mx17;
    mx17.diagonal(1.5);
    //mx17.print(std::cout);


    constexpr numbers_here::matrix<int,3,3,float> mx18 = {1,2,3,4,5,6,7,8,9};
    //mx18.print(std::cout);
    CU_ASSERT(mx18[0][0] == 1);
    CU_ASSERT(mx18[0][1] == 2);
    CU_ASSERT(mx18[0][2] == 3);
    CU_ASSERT(mx18[1][0] == 4);
    CU_ASSERT(mx18[1][1] == 5);
    CU_ASSERT(mx18[1][2] == 6);
    CU_ASSERT(mx18[2][0] == 7);
    CU_ASSERT(mx18[2][1] == 8);
    CU_ASSERT(mx18[2][2] == 9);


    constexpr numbers_here::matrix<int,3,2,float> mx19 = {1,2,3,4,5,6};
    //mx19.print(std::cout);
    CU_ASSERT(mx19[0][0] == 1);
    CU_ASSERT(mx19[0][1] == 2);
    CU_ASSERT(mx19[0][2] == 3);
    CU_ASSERT(mx19[1][0] == 4);
    CU_ASSERT(mx19[1][1] == 5);
    CU_ASSERT(mx19[1][2] == 6);

    numbers_here::matrix<int,2,3,float> mx20;
    mx20.transpose(mx19);
    //mx20.print(std::cout);
    CU_ASSERT(mx20[0][0] == 1);
    CU_ASSERT(mx20[1][0] == 2);
    CU_ASSERT(mx20[2][0] == 3);
    CU_ASSERT(mx20[0][1] == 4);
    CU_ASSERT(mx20[1][1] == 5);
    CU_ASSERT(mx20[2][1] == 6);

    //auto mx21 = mx19 * mx20;
    //mx21.print(std::cout);
    //std::cout<< std::setprecision(3)<< std::fixed;
    //Algebra Lineal pag 96
    constexpr numbers_here::matrix<float,3,3,float> mx22 = {1,1,1,0,2,3,5,5,1};
    auto mx23 = mx22.inverse();
    //mx23.print(std::cout);
    CU_ASSERT(numbers::core::equal(mx23[0][0], (float)13/(float)3));
    /*CU_ASSERT(numbers::core::equal(mx23[0][1], (float)-1/(float)2));
    CU_ASSERT(numbers::core::equal(mx23[0][2], (float)-1/(float)8));
    CU_ASSERT(numbers::core::equal(mx23[1][0], (float)-15/(float)8));
    CU_ASSERT(numbers::core::equal(mx23[1][1], (float)1/(float)1));
    CU_ASSERT(numbers::core::equal(mx23[1][2], (float)3/(float)8));
    CU_ASSERT(numbers::core::equal(mx23[2][0], (float)5/(float)4));
    CU_ASSERT(numbers::core::equal(mx23[2][1], (float)0));
    CU_ASSERT(numbers::core::equal(mx23[2][2], (float)-1/(float)4));*/

    constexpr numbers_here::matrix<int,4,3,float> mx24(mx18);
    //mx24.print(std::cout);
    CU_ASSERT(mx24[0][0] == 1);
    CU_ASSERT(mx24[0][1] == 2);
    CU_ASSERT(mx24[0][2] == 3);
    CU_ASSERT(mx24[0][3] == 0);
    CU_ASSERT(mx24[1][0] == 4);
    CU_ASSERT(mx24[1][1] == 5);
    CU_ASSERT(mx24[1][2] == 6);
    CU_ASSERT(mx24[1][3] == 0);
    CU_ASSERT(mx24[2][0] == 7);
    CU_ASSERT(mx24[2][1] == 8);
    CU_ASSERT(mx24[2][2] == 9);
    CU_ASSERT(mx24[2][3] == 0);

    constexpr numbers_here::matrix<int,3,3,float> mx25(mx24);
    //mx25.print(std::cout);
    CU_ASSERT(mx25[0][0] == 1);
    CU_ASSERT(mx25[0][1] == 2);
    CU_ASSERT(mx25[0][2] == 3);
    CU_ASSERT(mx25[1][0] == 4);
    CU_ASSERT(mx25[1][1] == 5);
    CU_ASSERT(mx25[1][2] == 6);
    CU_ASSERT(mx25[2][0] == 7);
    CU_ASSERT(mx25[2][1] == 8);
    CU_ASSERT(mx25[2][2] == 9);

    //constexpr numbers_here::matrix<int,3,3,float> mx26{1,2,3,4,5,6,7,8,9};
    //mx25.print(std::cout);
    //float mx26_det = mx26.determinant();
    //std::cout << "det(mx26) is " << mx26_det << "\n";
    //CU_ASSERT(mx26_det == -24)


    constexpr numbers_here::matrix<int,3,3,float> mx27{3,-1,2,4,5,6,7,1,2};
    //mx25.print(std::cout);
    auto mx27_minor12 = mx27.minor(0,1);
    //mx27_minor12.print(std::cout);
    CU_ASSERT(mx27_minor12[0][0] == 4);
    CU_ASSERT(mx27_minor12[0][1] == 6);
    CU_ASSERT(mx27_minor12[1][0] == 7);
    CU_ASSERT(mx27_minor12[1][1] == 2);
    int mx27_minor12_det = mx27_minor12.determinant();
    //std::cout << "det(mx27_minor12_det) is " << mx27_minor12_det << "\n";
    CU_ASSERT(mx27_minor12_det == -34)
    auto mx27_minor23 = mx27.minor(1,2);
    //mx27_minor23.print(std::cout);
    CU_ASSERT(mx27_minor23[0][0] == 3);
    CU_ASSERT(mx27_minor23[0][1] == -1);
    CU_ASSERT(mx27_minor23[1][0] == 7);
    CU_ASSERT(mx27_minor23[1][1] == 1);
    int mx27_minor23_det = mx27_minor23.determinant();
    //std::cout << "det(mx27_minor23_det) is " << mx27_minor23_det << "\n";
    CU_ASSERT(mx27_minor23_det == 10)
    auto mx27_minor31 = mx27.minor(2,0);
    //mx27_minor31.print(std::cout);
    CU_ASSERT(mx27_minor31[0][0] == -1);
    CU_ASSERT(mx27_minor31[0][1] == 2);
    CU_ASSERT(mx27_minor31[1][0] == 5);
    CU_ASSERT(mx27_minor31[1][1] == 6);
    int mx27_minor31_det = mx27_minor31.determinant();
    CU_ASSERT(mx27_minor31_det == -16)
    //std::cout << "det(mx27_minor31_det) is " << mx27_minor31_det << "\n";
    //std::cout << "\n\n\n";
    int mx27_minor12_cofac = mx27.cofactor(0,1);
    int mx27_minor23_cofac = mx27.cofactor(1,2);
    int mx27_minor31_cofac = mx27.cofactor(2,0);
    int mx27_det1 = mx27_minor12_cofac + mx27_minor23_cofac + mx27_minor31_cofac;
    CU_ASSERT(mx27_det1 == 8)
    //std::cout << "\n\n\n";
    CU_ASSERT(mx27.determinant() == 8)

    /*int mx27_teorema_inversa = 0;//pag 199
    for(size_t i = 0; i < mx27.rows(); i++)
    {
        mx27_teorema_inversa += mx27[2][i] * mx27.cofactor(1,i);
    }
    CU_ASSERT(mx27_teorema_inversa == 0)*/

    /*constexpr numbers_here::matrix<int,3,3,float> mx28{3,-2,1,5,6,2,1,0,-3};
    auto mx29 = mx28.adjoint();
    //mx29.print(std::cout);
    CU_ASSERT(mx29[0][0] == -18);
    CU_ASSERT(mx29[0][1] == -6);
    CU_ASSERT(mx29[0][2] == -10);
    CU_ASSERT(mx29[1][0] == 17);
    CU_ASSERT(mx29[1][1] == -10);
    CU_ASSERT(mx29[1][2] == -1);
    CU_ASSERT(mx29[2][0] == -6);
    CU_ASSERT(mx29[2][1] == -2);
    CU_ASSERT(mx29[2][2] == 28);
    std::cout << "det " << mx28.determinant();*/
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


void v0_sequence()
{
    numbers_here::core::array<int,1ul> sec1(1);
    CU_ASSERT(sizeof(sec1) == sizeof(int));
    CU_ASSERT(sec1[0] == 1);

    numbers_here::core::array<int,2ul> sec2(1);
    CU_ASSERT(sizeof(sec2) == sizeof(int) * 2);
    CU_ASSERT(sec2[0] == 1);
    CU_ASSERT(sec2[1] == 1);

    numbers_here::core::array<int,3ul> sec3(1);
    CU_ASSERT(sizeof(sec3) == sizeof(int) * 3);
    CU_ASSERT(sec3[0] == 1);
    CU_ASSERT(sec3[1] == 1);
    CU_ASSERT(sec3[2] == 1);

    constexpr numbers_here::core::array<int,3ul> sec4(1);

    numbers_here::core::array<int,10> sec5(1);
    CU_ASSERT(sizeof(sec5) == sizeof(int) * sec5.size());
    CU_ASSERT(sec5[0] == 1);
    CU_ASSERT(sec5[1] == 1);
    CU_ASSERT(sec5[2] == 1);
    CU_ASSERT(sec5[9] == 1);

    numbers_here::core::array<unsigned long long,10> sec6(1);
    CU_ASSERT(sizeof(sec6) == sizeof(unsigned long long) * sec6.size());
    CU_ASSERT(sec6[0] == 1);
    CU_ASSERT(sec6[1] == 1);
    CU_ASSERT(sec6[2] == 1);
    CU_ASSERT(sec6[9] == 1);

}

void v0_vector()
{
    numbers_here::vector<int,2ul,float> vect1{4,-3};
    CU_ASSERT(numbers_here::x(vect1) == 4);
    CU_ASSERT(numbers_here::y(vect1) == -3);


    numbers_here::vector<int,3ul,float> vect2{4,-3,5};
    CU_ASSERT(numbers_here::x(vect2) == 4);
    CU_ASSERT(numbers_here::y(vect2) == -3);
    CU_ASSERT(numbers_here::z(vect2) == 5);

    numbers_here::vector<int,3ul,float> vect3 {4,-3,5};
    CU_ASSERT(numbers_here::x(vect3) == 4);
    CU_ASSERT(numbers_here::y(vect3) == -3);
    CU_ASSERT(numbers_here::z(vect3) == 5);

    constexpr numbers_here::vector<int,3ul,float> vect5 {4,-3,5};

    /*numbers_here::sequence<numbers_here::sequence<int,3ul>,numbers_here::factorial(3ul)> pers;
    numbers_here::vector<int,3ul,float> vect4 {4,-3,5};
    vect4.permutation(pers);*/
    /*
    for(size_t i = 0; i < pers.size(); i++)
    {
        pers[i].printLn(std::cout);
    }
    */
    //CU_ASSERT(pers[0] == {4,-3,5});

    numbers_here::vector<int,3ul,float> vect6 = vect3 + vect2;
    CU_ASSERT(numbers_here::x(vect6) == 8);
    CU_ASSERT(numbers_here::y(vect6) == -6);
    CU_ASSERT(numbers_here::z(vect6) == 10);

    numbers_here::vector<int,3ul,float> vect7 = vect6 - vect2;
    CU_ASSERT(numbers_here::x(vect7) == 4);
    CU_ASSERT(numbers_here::y(vect7) == -3);
    CU_ASSERT(numbers_here::z(vect7) == 5);


    numbers_here::vector<int,2> vect8{1, 3};
    numbers_here::vector<int,2> vect9{-5, 2};

    CU_ASSERT(numbers_here::scalar(vect8,vect9) == 1);
    //std::cout << " Dot : " << numbers_here::scalar(vect8,vect9) << "";

    numbers_here::vector<float,2> vect10{1, 0};
    for(size_t i = 0; i < 90; i++)
    {
        //std::cout << "(" << numbers_here::x(vect10) << "," << numbers_here::y(vect10) << ")\n";
        vect10.rotate(0.0174533);
    }
    CU_ASSERT(numbers_here::y(vect10) - 1.0 < infimium);

    numbers_here::vector<int,3> vect11{2,0,1};
    numbers_here::vector<int,3> vect12{1,-1,3};
    numbers_here::vector<int,3> vect13 = vect11 * vect12;
    CU_ASSERT(vect13.x() == 1);
    CU_ASSERT(vect13.y() == -5);
    CU_ASSERT(vect13.z() == -2);

    numbers_here::vector<int,3> vect14{3,0,2};
    numbers_here::vector<int,3> vect15{-1,4,2};
    numbers_here::vector<int,3> vect16 = vect14 * vect15;
    CU_ASSERT(vect16.x() == -8);
    CU_ASSERT(vect16.y() == -8);
    CU_ASSERT(vect16.z() == 12);

    numbers_here::vector<float,3> vect17{3,0,2};
    //vect17.printLn(std::cout);
    numbers_here::vector<float,3> vect18 = numbers_here::normalize(vect17);
    //vect18.printLn(std::cout);
    //std::cout << "Longitud : " << vect18.length() << "\n";
    CU_ASSERT_DECIMAL(vect18.x(), 0.83205,infimium);
    CU_ASSERT_DECIMAL(vect18.y(), 0.0,infimium);
    CU_ASSERT_DECIMAL(vect18.z(), 0.5547,infimium);

    numbers_here::vector<float,3> vect19{3,0,2};
    numbers_here::vector<float,3> vect20{-1,4,2};
    numbers_here::vector<float,3> vect21 = vect19 * vect20;
    CU_ASSERT_DECIMAL(vect21.x(), -8,infimium);
    CU_ASSERT_DECIMAL(vect21.y(), -8,infimium);
    CU_ASSERT_DECIMAL(vect21.z(), 12,infimium);
    //vect21.printLn(std::cout);

    numbers_here::vector<int,3> vect22{2,0,1};
    numbers_here::vector<int,3> vect23{1,-1,3};
    numbers_here::vector<int,3> vect24 = vect22 * vect23;
    CU_ASSERT_DECIMAL(vect24.x(),1,infimium);
    CU_ASSERT_DECIMAL(vect24.y(),-5,infimium);
    CU_ASSERT_DECIMAL(vect24.z(),-2,infimium);
    //vect24.printLn(std::cout);

    numbers_here::vector<int,3> vect25 = vect22 - vect23;
    CU_ASSERT(vect25.x() == 1);
    CU_ASSERT(vect25.y() == 1);
    CU_ASSERT(vect25.z() == -2);

    numbers_here::vector<int,3> vect26 = vect22 + vect23;
    CU_ASSERT(vect26.x() == 3);
    CU_ASSERT(vect26.y() == -1);
    CU_ASSERT(vect26.z() == 4);


    numbers_here::vector<int,3> vect27{0,0,0};
    vect27 += vect22;
    CU_ASSERT(vect27.x() == 2);
    CU_ASSERT(vect27.y() == 0);
    CU_ASSERT(vect27.z() == 1);

    numbers_here::vector<float,3> vect28{0,0,0};
    vect28 += vect20;
    CU_ASSERT_DECIMAL(vect28.x(), -1,infimium);
    CU_ASSERT_DECIMAL(vect28.y(), 4,infimium);
    CU_ASSERT_DECIMAL(vect28.z(), 2,infimium);

    numbers_here::vector<float,3> vect29{2,0,1};
    numbers_here::vector<float,3> vect30 = vect29 * 1.1;
    //vect30.printLn(std::cout);
    CU_ASSERT_DECIMAL(vect30.x(), 2.2,infimium);
    CU_ASSERT_DECIMAL(vect30.y(), 0,infimium);
    CU_ASSERT_DECIMAL(vect30.z(), 1.1,infimium);

    numbers_here::vector<float,3> vect31(0);
    vect31 = vect30;
    CU_ASSERT_DECIMAL(vect31.x(), 2.2,infimium);
    CU_ASSERT_DECIMAL(vect31.y(), 0,infimium);
    CU_ASSERT_DECIMAL(vect31.z(), 1.1,infimium);
    //vect31.printLn(std::cout);

    numbers_here::vector<float,3> vect32(0);
    vect32.x() = 2.2;
    vect32.y() = 0;
    vect32.z() = 1.1;
    CU_ASSERT_DECIMAL(vect32.x(), 2.2,infimium);
    CU_ASSERT_DECIMAL(vect32.y(), 0,infimium);
    CU_ASSERT_DECIMAL(vect32.z(), 1.1,infimium);
    //vect32.printLn(std::cout);
}

void v0_funtions()
{
    CU_ASSERT(numbers_here::factorial(3ul) == 6);
    CU_ASSERT(numbers_here::factorial(6ul) == 720);
    CU_ASSERT(numbers_here::factorial(9ul) == 362880);

    auto list1 = numbers::listing<int,2ul>();
    //list1.print(std::cout);
    CU_ASSERT(list1[0] == 1)
    CU_ASSERT(list1[1] == 2)

    auto list2 = numbers::listing<int,3ul>();
    //list1.print(std::cout);
    CU_ASSERT(list2[0] == 1)
    CU_ASSERT(list2[1] == 2)
    CU_ASSERT(list2[2] == 3)

    auto list3 = numbers::listing<int,4ul>();
    //list1.print(std::cout);
    CU_ASSERT(list3[0] == 1)
    CU_ASSERT(list3[1] == 2)
    CU_ASSERT(list3[2] == 3)
    CU_ASSERT(list3[3] == 4)


}


int v0_init(void)
{

	return 0;
}
int v0_clean(void)
{

	return 0;
}
