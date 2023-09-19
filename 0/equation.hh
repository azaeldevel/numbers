#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"
#include "matrix.hh"

namespace oct::nums::v0
{

    /**
    *\brief Resuleve 'x' en la ecuacion de la forma ax = b
    *
    */
    template<core::number T, core::number V = core::convertion<T>::type> constexpr V resolve(V const& a,V const& b)
    {
        return a/b;
    }

    /**
    *\brief Resuleve 'x' en la ecuacion de la forma ax = b
    *
    */
    template<core::decimal T,core::index auto S> constexpr matrix<T,1,S> resolve(matrix<T,S,S> const& a, matrix<T,1,S> const& b)
    {
        auto x = a.inverse() * b;
        return x;
    }


    /**
    *\brief Resuleve una ecuacion de la forma ax + b = y
    *
    */
    template<core::number T, core::number V = core::convertion<T>::type> constexpr V resolve(V const& a,V const& b,V const& y)
    {
        return (y + b) / a;
    }







    template<core::number T,size_t L,core::number V,core::index I>
    constexpr bool vector<T,L,V,I>::is_parallel(const vector<T,L,V,I>& v)//TODO:impletmatar
    {


        return false;
    }

}

#endif // OCTETOS_NUMBERS_MATH_HH
