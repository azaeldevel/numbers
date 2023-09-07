#ifndef OCTETOS_NUMBERS_ARITHMETIC_V0_HH
#define OCTETOS_NUMBERS_ARITHMETIC_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include "common.hh"

namespace oct::nums::v0
{

    template<core::natural T> struct CaseNumber
    {
        T number;
        bool prime;
    };

    template<typename T,core::natural Z,Z L> class PrimeNumbers : public core::array<T,L>
    {
    private:
        typedef core::array<T,L> BASE;
    public:
        constexpr PrimeNumbers()
        {
            for(Z i = 0; i < L; i++)
            {
                BASE::data[i].number = i;
                BASE::data[i].prime = true;
            }
        }

        constexpr void erastostenes()
        {
            BASE::data[0].prime = false;
            BASE::data[1].prime = false;
            Z temp;
            for(Z i = 2; i < L; i++)
            {
                for(Z j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) BASE::data[temp].prime = false;
                }
            }

        }

        void print(std::ostream& out) const
        {
            for(Z i = 0; i < L; i++)
            {
                if(BASE::data[i].prime) out << BASE::data[i].number << "\n";
            }
        }
    };



    template<core::natural T,size_t L> class Primes : public core::array<T,L>
    {
    private:
        typedef core::array<T,L> BASE;

    public:
        constexpr Primes()
        {
            init();
        }

        constexpr void erastos()
        {
            size_t temp;
            for(size_t i = 2; i < L; i++)
            {
                for(size_t j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) BASE::data[temp] = 0;
                    else break;
                }
            }
        }

        constexpr void print(std::ostream& out)
        {
            for(size_t i = 0; i < L; i++)
            {
                if(BASE::data[i] > 0) out << BASE::data[i] << "\n";
            }
        }
    private:
        constexpr void init()
        {
            BASE::data[0] = 0;
            BASE::data[1] = 0;
            for(size_t i = 2; i < L; i++)
            {
                BASE::data[i] = i;
            }
        }
    };

}

#endif // OCTETOS_NUMBERS_MATH_HH
