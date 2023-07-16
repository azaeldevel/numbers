


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

template<> void secuence<int,1>::permutation(secuence<secuence<int,1>,1>& pers) const
{
    secuence<int,1> sec = *this;
    int index = 0;
    permutations(sec,0,1,index,pers);
}
template<> void secuence<int,2>::permutation(secuence<secuence<int,2>,2>& pers) const
{
    secuence<int,2> sec = *this;
    int index = 0;
    permutations(sec,0,2,index,pers);
}

template<> void secuence<int,1>::permutations(secuence<int,1>& sec, int i, int n, int& p, secuence<secuence<int,1>,1>& pers) const
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
template<> void secuence<int,2>::permutations(secuence<int,2>& sec, int i, int n, int& p, secuence<secuence<int,2>,2>& pers) const
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



#ifdef OCTETOS_NUMBERS_TTD

#endif // OCTETOS_NUMBERS_TTD


template<> float matrix<int,1,1,float>::det() const
{
    return secuence<secuence<int,1>,1>::data[0][0];
}
template<> float matrix<int,2,2,float>::det() const
{
    float d = 0;
    d = secuence<secuence<int,2>,2>::data[0][0] * secuence<secuence<int,2>,2>::data[1][1];
    d -= secuence<secuence<int,2>,2>::data[0][1] * secuence<secuence<int,2>,2>::data[1][0];

    return d;
}


}

