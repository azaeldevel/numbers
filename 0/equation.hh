#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<number T,decimal V> class equation<T,1,V> : public secuence<T,1,V>
    {
    protected:
        T _c_;
    public:
        equation() = default;
        equation(const T& c, const T& a)
        {
            _c_ = c;
            secuence<T,1,V>::data[0] = a;
        }




        T& c()
        {
            return _c_;
        }
        T& a()
        {
            return secuence<T,1,V>::data[0];
        }
        V x()
        {
            return V(_c_)/V(secuence<T,1,V>::data[0]);
        }
    };
    template<number T,decimal V> class equation<T,2,V> : public secuence<T,2,V>
    {
    protected:
        T _c_;
    public:
        equation() = default;
        equation(const T& c, const T& a)
        {
            _c_ = c;
            secuence<T,2,V>::data[0] = a;
        }
        equation(const T& c, const T& a,const T& b)
        {
            _c_ = c;
            secuence<T,2,V>::data[0] = a;
            secuence<T,2,V>::data[1] = b;
        }




        T& c()
        {
            return equation<T,2,V>::_c_;
        }
        T& a()
        {
            return equation<T,2,V>::data[0];
        }
        T& b()
        {
            return equation<T,2,V>::data[1];
        }
        V x(T y)
        {
            return (equation<T,2,V>::_c_ - (b() * y)) / a();
        }
        V y(T x)
        {
            return V(equation<T,2,V>::_c_ - (a() * x)) / V(b());
        }
    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
