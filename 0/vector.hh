#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<number T,size_t L,number V> class vector : public sequence<T,L>
    {
    public:
        vector() = default;
        constexpr vector(const T& v) : sequence<T,L>(v)
        {
        }
        constexpr vector(const std::initializer_list<T>& l) : sequence<T,L>(l)
        {
        }
    };


    template<number T,number V> class vector<T,2,V> : public sequence<T,2>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            sequence<T,2>::data[0] = x;
            sequence<T,2>::data[1] = y;
        }
        constexpr vector(const std::initializer_list<T>& l) : sequence<T,2>(l)
        {
        }



        constexpr T& x()
        {
            return sequence<T,2>::data[0];
        }
        constexpr T& y()
        {
            return sequence<T,2>::data[1];
        }
    };
    template<number T,number V> class vector<T,3,V> : public sequence<T,3>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            sequence<T,3>::data[0] = x;
            sequence<T,3>::data[1] = y;
        }
        constexpr vector(const T& x, const T& y, const T& z)
        {
            sequence<T,3>::data[0] = x;
            sequence<T,3>::data[1] = y;
            sequence<T,3>::data[2] = z;
        }
        constexpr vector(const std::initializer_list<T>& l) : sequence<T,3>(l)
        {
        }



        constexpr T& x()
        {
            return sequence<T,3>::data[0];
        }
        constexpr T& y()
        {
            return sequence<T,3>::data[1];
        }
        constexpr T& z()
        {
            return sequence<T,3>::data[2];
        }
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
