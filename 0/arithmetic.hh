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

    template<typename T,natural Z,Z L> class PrimeNumbers : public Array<T,Z,L>
    {
    public:
        constexpr PrimeNumbers()
        {
            for(Z i = 0; i < L; i++)
            {
                Array<T,Z,L>::data[i].number = i;
                Array<T,Z,L>::data[i].prime = true;
            }
        }

        constexpr void erastostenes()
        {
            Array<T,Z,L>::data[0].prime = false;
            Array<T,Z,L>::data[1].prime = false;
            Z temp;
            for(Z i = 2; i < L; i++)
            {
                for(Z j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) Array<T,Z,L>::data[temp].prime = false;
                }
            }

        }

        void print(std::ostream& out) const
        {
            for(Z i = 0; i < L; i++)
            {
                if(Array<T,Z,L>::data[i].prime) out << Array<T,Z,L>::data[i].number << "\n";
            }
        }
    };



    template<natural T,natural Z,Z L> class Primes : public Array<T,Z,L>
    {

    public:
        constexpr Primes()
        {
            init();
        }

        constexpr void erastos()
        {
            Z temp;
            for(Z i = 2; i < L; i++)
            {
                for(Z j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) Array<T,Z,L>::data[temp] = 0;
                    else break;
                }
            }
        }

        constexpr void print(std::ostream& out)
        {
            for(Z i = 0; i < L; i++)
            {
                if(Array<T,Z,L>::data[i] > 0) out << Array<T,Z,L>::data[i] << "\n";
            }
        }
    private:
        constexpr void init()
        {
            for(Z i = 0; i < L; i++)
            {
                Array<T,Z,L>::data[i] = i;
            }
            Array<T,Z,L>::data[0] = 0;
            Array<T,Z,L>::data[1] = 0;
        }
    };

}

#endif // OCTETOS_NUMBERS_MATH_HH
