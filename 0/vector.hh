#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<typename T,size_t L,number V> class vector : public Sequence<T,L>
    {
    public:
        vector() = default;
        constexpr vector(const T& v) : Sequence<T,L>(v)
        {
        }
        constexpr vector(const std::initializer_list<T>& l) : Sequence<T,L>(l)
        {
        }
    };


    template<number T,number V> class vector<T,2,V> : public Sequence<T,2>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            Sequence<T,2>::data[0] = x;
            Sequence<T,2>::data[1] = y;
        }



        constexpr T& x()
        {
            return Sequence<T,2>::data[0];
        }
        constexpr T& y()
        {
            return Sequence<T,2>::data[1];
        }
    };
    template<number T,number V> class vector<T,3,V> : public Sequence<T,3>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            Sequence<T,3>::data[0] = x;
            Sequence<T,3>::data[1] = y;
        }
        constexpr vector(const T& x, const T& y, const T& z)
        {
            Sequence<T,3>::data[0] = x;
            Sequence<T,3>::data[1] = y;
            Sequence<T,3>::data[2] = z;
        }



        constexpr T& x()
        {
            return Sequence<T,3>::data[0];
        }
        constexpr T& y()
        {
            return Sequence<T,3>::data[1];
        }
        constexpr T& z()
        {
            return Sequence<T,3>::data[2];
        }
    };



}

#endif // OCTETOS_NUMBERS_MATH_HH
