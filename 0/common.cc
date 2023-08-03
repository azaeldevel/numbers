


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

template<> void sequence<int,1>::permutation(sequence<sequence<int,1>,1>& pers) const
{
    sequence<int,1> sec = *this;
    int index = 0;
    permutations(sec,0,1,index,pers);
}
template<> void sequence<int,2>::permutation(sequence<sequence<int,2>,2>& pers) const
{
    sequence<int,2> sec = *this;
    int index = 0;
    permutations(sec,0,2,index,pers);
}

template<> void sequence<int,1>::permutations(sequence<int,1>& sec, int i, int n, int& p, sequence<sequence<int,1>,1>& pers) const
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
template<> void sequence<int,2>::permutations(sequence<int,2>& sec, int i, int n, int& p, sequence<sequence<int,2>,2>& pers) const
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

