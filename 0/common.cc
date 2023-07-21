


#include "common.hh"

namespace oct::nums::v0
{

/*
template<> int factorial<int>(const int& n)
{
    int number = 1;
    for(int i = 1; i <= n; i++) number *= i;

    return number;
}

template<> void Array<int,1>::permutation(Array<Array<int,1>,1>& pers) const
{
    Array<int,1> sec = *this;
    int index = 0;
    permutations(sec,0,1,index,pers);
}
template<> void Array<int,2>::permutation(Array<Array<int,2>,2>& pers) const
{
    Array<int,2> sec = *this;
    int index = 0;
    permutations(sec,0,2,index,pers);
}

template<> void Array<int,1>::permutations(Array<int,1>& sec, int i, int n, int& p, Array<Array<int,1>,1>& pers) const
{
    // condición base
    if (i == n - 1)
    {
        //std::cout << p << "\n";
        pers[p++] = sec;
        //sec.printLn(std::cout);
        return;
    }

    // procesa cada caracter de la string restante
    for (int j = i; j < n; j++)
    {
        // intercambiar carácter en el índice `i` con el carácter actual
        std::swap(sec[i], sec[j]);        // STL `swap()` usado

        // recurre para la subcadena `str[i+1, n-1]`
        permutations(sec, i + 1, n, p, pers);

        // retroceder (restaurar la string a su estado original)
        std::swap(sec[i], sec[j]);
    }
}
template<> void Array<int,2>::permutations(Array<int,2>& sec, int i, int n, int& p, Array<Array<int,2>,2>& pers) const
{
    // condición base
    if (i == n - 1)
    {
        //std::cout << p << "\n";
        pers[p++] = sec;
        //sec.printLn(std::cout);
        return;
    }

    // procesa cada caracter de la string restante
    for (int j = i; j < n; j++)
    {
        // intercambiar carácter en el índice `i` con el carácter actual
        std::swap(sec[i], sec[j]);        // STL `swap()` usado

        // recurre para la subcadena `str[i+1, n-1]`
        permutations(sec, i + 1, n, p, pers);

        // retroceder (restaurar la string a su estado original)
        std::swap(sec[i], sec[j]);
    }
}
*/


}

