#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<number T,number V> V resolve(const equation<T,1,1,V>& eq)
    {
        return V(eq.c())/V(eq[0]);
    }
    template<number T,number V> V resolve(const equation<T,2,1,V>& eq, size_t index, const T& v)
    {
        if(index == 0) return (eq.c() - (eq[1] * v)) / V(eq[0]);
        else if(index == 1) return V(eq.c() - (eq[0] * v)) / V(eq[1]);

        throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        return 0;
    }

    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param V Tipo de datos usado para calculos
    **/
    template<number T,size_t L,number V> V clearance(const equation<T,L,1,V>& eq, size_t index)
    {


        return 0;
    }

    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param V Tipo de datos usado para calculos
    **/
    template<number T,size_t L,number V> V resolve(const equation<T,L,1,V>* eqs, size_t leng)
    {
        std::cout << "Resolviendo ecuacion de " << L << "º\n";

        return 0;
    }


}

#endif // OCTETOS_NUMBERS_MATH_HH
