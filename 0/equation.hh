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
    template<core::number T, core::number V = core::convertion_to_real<T>::type> constexpr V resolve(V const& a,V const& b)
    {
        return a/b;
    }

    /**
    *\brief Resuleve 'x' en la ecuacion de la forma ax = b
    *
    */
    template<core::decimal T,core::index auto S> constexpr matrix<T,S,1> resolve(matrix<T,S,S> const& a, matrix<T,S,1> const& b)
    {
        auto x = a.inverse() * b;
        return x;
    }

    /**
    *\brief Resuleve 'x' en la ecuacion de la forma ax = b
    *
    */
    template<core::decimal T,core::index auto S> constexpr matrix<T,S,1> resolve(matrix<T,S,S> const& a, vector<T,S> const& b)
    {
        auto x = a.inverse() * b;
        return x;
    }


    /**
    *\brief Resuleve una ecuacion de la forma ax + b = y
    *
    */
    template<core::number T, core::number V = core::convertion_to_real<T>::type> constexpr V resolve(V const& a,V const& b,V const& y)
    {
        return (y + b) / a;
    }


}

#endif // OCTETOS_NUMBERS_MATH_HH
