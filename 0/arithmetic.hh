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

    template<typename T,natural Z,Z L> class PrimeNumbers : public consecutive<T,Z,L>
    {
    public:
        constexpr PrimeNumbers()
        {
            for(Z i = 0; i < L; i++)
            {
                consecutive<T,Z,L>::data[i].number = i;
                consecutive<T,Z,L>::data[i].prime = true;
            }
            /*consecutive<T,Z,L>::data[2].prime = true;
            consecutive<T,Z,L>::data[3].prime = true;
            consecutive<T,Z,L>::data[5].prime = true;
            consecutive<T,Z,L>::data[7].prime = true;
            consecutive<T,Z,L>::data[9].prime = true;
            consecutive<T,Z,L>::data[11].prime = true;
            consecutive<T,Z,L>::data[13].prime = true;
            consecutive<T,Z,L>::data[17].prime = true;
            consecutive<T,Z,L>::data[19].prime = true;
            consecutive<T,Z,L>::data[23].prime = true;*/
        }

        constexpr void erastostenes()
        {
            consecutive<T,Z,L>::data[0].prime = false;
            consecutive<T,Z,L>::data[1].prime = false;
            Z temp;
            for(Z i = 2; i < L; i++)
            {
                for(Z j = 2; j < L; j++)
                {
                    temp = i * j;
                    if(temp < L) consecutive<T,Z,L>::data[temp].prime = false;
                }
            }

        }

        void print(std::ostream& out) const
        {
            for(Z i = 0; i < L; i++)
            {
                if(consecutive<T,Z,L>::data[i].prime) out << consecutive<T,Z,L>::data[i].number << "\n";
            }
        }
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
