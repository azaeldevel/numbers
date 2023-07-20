#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<typename T,size_t L,number V> class vector : public secuence<T,size_t,L>
    {
    public:
        vector() = default;
        constexpr vector(const T& v) : secuence<T,size_t,L>(v)
        {
        }
        constexpr vector(const std::initializer_list<T>& l) : secuence<T,size_t,L>(l)
        {
        }
    };


    template<number T,number V> class vector<T,2,V> : public secuence<T,size_t,2>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            secuence<T,size_t,2>::data[0] = x;
            secuence<T,size_t,2>::data[1] = y;
        }



        constexpr T& x()
        {
            return secuence<T,size_t,2>::data[0];
        }
        constexpr T& y()
        {
            return secuence<T,size_t,2>::data[1];
        }
    };
    template<number T,number V> class vector<T,3,V> : public secuence<T,size_t,3>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            secuence<T,size_t,3>::data[0] = x;
            secuence<T,size_t,3>::data[1] = y;
        }
        constexpr vector(const T& x, const T& y, const T& z)
        {
            secuence<T,size_t,3>::data[0] = x;
            secuence<T,size_t,3>::data[1] = y;
            secuence<T,size_t,3>::data[2] = z;
        }



        constexpr T& x()
        {
            return secuence<T,size_t,3>::data[0];
        }
        constexpr T& y()
        {
            return secuence<T,size_t,3>::data[1];
        }
        constexpr T& z()
        {
            return secuence<T,size_t,3>::data[2];
        }
    };



}

#endif // OCTETOS_NUMBERS_MATH_HH
