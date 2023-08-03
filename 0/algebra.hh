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
    *\param L la cantiad de variables del monomio
    *\param L Cantidad de variables
    **/
    template<number T,size_t L,number V = T,char C = 'x'>
    class Monomio : public sequence<T,L + 1>
    {
    private:
        typedef sequence<T,L + 1> BASE;

    public:
        constexpr Monomio() = default;
        constexpr Monomio(T t) : BASE(t)
        {
        }
        constexpr Monomio(const std::initializer_list<T>& l) : BASE(l)
        {
        }

        constexpr Monomio operator + (const Monomio& m)
        {
            Monomio mono;
            for(size_t i = 0; i < BASE::size(); i++)
            {
                mono[i] = BASE::data[i] + m[i];
            }

            return mono;
        }
        constexpr Monomio operator - (const Monomio& m)
        {
            Monomio mono;
            for(size_t i = 0; i < BASE::size(); i++)
            {
                mono[i] = BASE::data[i] - m[i];
            }

            return mono;
        }



        void print(std::ostream& out,char tag) const
        {
            out << BASE::data[0];
            for(size_t i = 1; i < BASE::size(); i++)
            {
                out << char(tag + i - 1) << "^" << BASE::data[i];
            }
        }

    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
