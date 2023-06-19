#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<number T,decimal V> class first<T,1,V> : public equation<T,1,V>
    {
    public:
        first() = default;
        first(const T& c, const T& a)
        {
            equation<T,1,V>::_c_ = c;
            equation<T,1,V>::data[0] = a;
        }




        T& c()
        {
            return equation<T,1,V>::_c_;
        }
        T& a()
        {
            return equation<T,1,V>::data[0];
        }
        V x()
        {
            return V(equation<T,1,V>::_c_)/V(equation<T,1,V>::data[0]);
        }
    private:
    };
    template<number T,decimal V> class first<T,2,V> : public equation<T,2,V>
    {
    public:
        first() = default;
        first(const T& c, const T& a)
        {
            equation<T,2,V>::_c_ = c;
            equation<T,2,V>::data[0] = a;
        }
        first(const T& c, const T& a,const T& b)
        {
            equation<T,2,V>::_c_ = c;
            equation<T,2,V>::data[0] = a;
            equation<T,2,V>::data[1] = b;
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
    private:
    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
