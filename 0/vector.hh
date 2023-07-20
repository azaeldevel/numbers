#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{
    template<number T,number V> class vector<T,2,V> : public consecutive<T,size_t,2>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            consecutive<T,size_t,2>::data[0] = x;
            consecutive<T,size_t,2>::data[1] = y;
        }



        constexpr T& x()
        {
            return consecutive<T,size_t,2>::data[0];
        }
        constexpr T& y()
        {
            return consecutive<T,size_t,2>::data[1];
        }
    };
    template<number T,number V> class vector<T,3,V> : public consecutive<T,size_t,3>
    {
    public:
        constexpr vector(const T& x, const T& y)
        {
            consecutive<T,size_t,3>::data[0] = x;
            consecutive<T,size_t,3>::data[1] = y;
        }
        constexpr vector(const T& x, const T& y, const T& z)
        {
            consecutive<T,size_t,3>::data[0] = x;
            consecutive<T,size_t,3>::data[1] = y;
            consecutive<T,size_t,3>::data[2] = z;
        }



        constexpr T& x()
        {
            return consecutive<T,size_t,3>::data[0];
        }
        constexpr T& y()
        {
            return consecutive<T,size_t,3>::data[1];
        }
        constexpr T& z()
        {
            return consecutive<T,size_t,3>::data[2];
        }
    };



}

#endif // OCTETOS_NUMBERS_MATH_HH
