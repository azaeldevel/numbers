#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"

namespace oct::nums::v0
{

    /*template<number T,number V> class equation<T,1,1,V> : public secuence<T,1>
    {
    protected:
        T _c_;

    public:
        equation() = default;
        constexpr equation(const T& c, const T& a)
        {
            _c_ = c;
            secuence<T,1>::data[0] = a;
        }


        constexpr T& c()
        {
            return _c_;
        }
        constexpr T& a()
        {
            return secuence<T,1>::data[0];
        }
        constexpr V x()
        {
            return V(_c_)/V(secuence<T,1>::data[0]);
        }
    };
    template<number T,number V> class equation<T,2,1,V> : public secuence<T,2>
    {
    protected:
        T _c_;
    public:
        equation() = default;
        constexpr equation(const T& c, const T& a)
        {
            _c_ = c;
            secuence<T,2>::data[0] = a;
        }
        constexpr equation(const T& c, const T& a,const T& b)
        {
            _c_ = c;
            secuence<T,2>::data[0] = a;
            secuence<T,2>::data[1] = b;
        }




        constexpr T& c()
        {
            return _c_;
        }
        constexpr T& a()
        {
            return secuence<T,2>::data[0];
        }
        constexpr T& b()
        {
            return secuence<T,2>::data[1];
        }
        constexpr V x(T y)
        {

        }
        constexpr V y(T x)
        {
            return V(_c_ - (a() * x)) / V(b());
        }
    };*/


    template<number T,number V> V resolve(const equation<T,1,1,V>& eq)
    {
        return V(eq.c())/V(eq[0]);
    }
    template<number T,number V> V resolve(const equation<T,2,1,V>& eq, const T& v, size_t index)
    {
        if(index == 0) return (eq.c() - (eq[1] * v)) / V(eq[0]);
        else if(index == 1) return V(eq.c() - (eq[0] * v)) / V(eq[1]);

        throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        return 0;
    }



}

#endif // OCTETOS_NUMBERS_MATH_HH
