#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{
    template<number T,number V> class vector<T,2,V> : public secuence<T,2,V>
    {
    public:
        vector(const T& x, const T& y)
        {
            secuence<T,2,V>::data[0] = x;
            secuence<T,2,V>::data[1] = y;
        }



        T& x()
        {
            return secuence<T,2,V>::data[0];
        }
        T& y()
        {
            return secuence<T,2,V>::data[1];
        }
    };
    template<number T,number V> class vector<T,3,V> : public secuence<T,3,V>
    {
    public:
        vector(const T& x, const T& y)
        {
            secuence<T,3,V>::data[0] = x;
            secuence<T,3,V>::data[1] = y;
        }
        vector(const T& x, const T& y, const T& z)
        {
            secuence<T,3,V>::data[0] = x;
            secuence<T,3,V>::data[1] = y;
            secuence<T,3,V>::data[2] = z;
        }



        T& x()
        {
            return secuence<T,3,V>::data[0];
        }
        T& y()
        {
            return secuence<T,3,V>::data[1];
        }
        T& z()
        {
            return secuence<T,3,V>::data[2];
        }
    };



}

#endif // OCTETOS_NUMBERS_MATH_HH
