#ifndef OCTETOS_NUMBERS_ARITHMETIC_V0_HH
#define OCTETOS_NUMBERS_ARITHMETIC_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include "common.hh"

namespace oct::nums::v0
{

    template<natural T> struct CaseNumber
    {
        T number;
        bool prime;
    };

    template<typename T,natural Z,Z L> class PrimeNumbers : public sequence<T,L>
    {
    public:
        constexpr PrimeNumbers()
        {
            for(Z i = 0; i < L; i++)
            {
                sequence<T,L>::data[i].number = i;
                sequence<T,L>::data[i].prime = true;
            }
        }

        constexpr void erastostenes()
        {
            sequence<T,L>::data[0].prime = false;
            sequence<T,L>::data[1].prime = false;
            Z temp;
            for(Z i = 2; i < L; i++)
            {
                for(Z j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) sequence<T,L>::data[temp].prime = false;
                }
            }

        }

        void print(std::ostream& out) const
        {
            for(Z i = 0; i < L; i++)
            {
                if(sequence<T,L>::data[i].prime) out << sequence<T,L>::data[i].number << "\n";
            }
        }
    };



    template<natural T,size_t L> class Primes : public sequence<T,L>
    {

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
                    if(temp < L) sequence<T,L>::data[temp] = 0;
                    else break;
                }
            }
        }

        constexpr void print(std::ostream& out)
        {
            for(size_t i = 0; i < L; i++)
            {
                if(sequence<T,L>::data[i] > 0) out << sequence<T,L>::data[i] << "\n";
            }
        }
    private:
        constexpr void init()
        {
            sequence<T,L>::data[0] = 0;
            sequence<T,L>::data[1] = 0;
            for(size_t i = 2; i < L; i++)
            {
                sequence<T,L>::data[i] = i;
            }
        }
    };

}

#endif // OCTETOS_NUMBERS_MATH_HH
