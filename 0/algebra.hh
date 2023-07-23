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
    template<number T,size_t L>
    class Monomio : public Sequence<T,L + 1>
    {
    private:
        typedef Sequence<T,L + 1> BASE;

    public:
        constexpr Monomio() = default;
        constexpr Monomio(T t) : BASE(t)
        {
        }
        constexpr Monomio(const std::initializer_list<T>& l) : BASE(l)
        {
        }



        void print(std::ostream& out,char tag) const
        {
            out << BASE::data[0];
            for(size_t i = 1; i < L + 1; i++)
            {
                out << char(tag + i - 1) << "^" << BASE::data[i];
            }
        }

    };

    /**
    *\brief Es un Polinomio
    *\param T Es el tipo de datos que de las variables
    *\param Z Tipo de datos que expresa el rango de numeros que puede manejar(maxima cantidad de variables que puede tener)
    *\param L Cantidad de variables
    **/
    template<number T,size_t L,size_t G>
    class Polinomio : public Sequence<Monomio<T,L>,(L * G) + 1>
    {
    private:
        typedef Sequence<Monomio<T,L>,(L * G) + 1> BASE;

    public:
        constexpr Polinomio() = default;
        constexpr Polinomio(T t) : BASE(t)
        {
        }
        constexpr Polinomio(const std::initializer_list<T>& l) : BASE(l)
        {
        }



        void print(std::ostream& out,char tag) const
        {

        }

    };

}

#endif // OCTETOS_NUMBERS_MATH_HH
