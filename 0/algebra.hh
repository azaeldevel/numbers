#ifndef OCTETOS_NUMBERS_ALGEBRA_V0_HH
#define OCTETOS_NUMBERS_ALGEBRA_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include "common.hh"

namespace oct::nums::v0
{
    /**
    *\brief Es un Monomio
    *\param T Es el tipo de datos que de las variables
    *\param Z Tipo de datos que expresa el rango de numeros que puede manejar(maxima cantidad de variables que puede tener)
    *\param L Cantidad de variables
    **/
    template<number T,natural Z,Z L>
    class Monomio : public secuence<T,Z,L + 1>
    {
    private:
        typedef secuence<T,Z,L + 1> BASE;

    public:
        Monomio() = default;
        Monomio(T t) : BASE(t)
        {
        }


    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
