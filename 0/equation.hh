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
            equation<T,1,V>::data[0] = c;
            equation<T,1,V>::data[1] = a;
        }




        T& c()
        {
            return equation<T,1,V>::data[0];
        }
        T& a()
        {
            return equation<T,1,V>::data[1];
        }
        T x()
        {
            return equation<T,1,V>::data[0]/equation<T,1,V>::data[1];
        }
    private:
    };
    template<number T,decimal V> class first<T,2,V> : public equation<T,2,V>
    {
    public:
        first() = default;
        first(const T& c, const T& a)
        {
            equation<T,2,V>::data[0] = c;
            equation<T,2,V>::data[1] = a;
        }
        first(const T& c, const T& a,const T& b)
        {
            equation<T,2,V>::data[0] = c;
            equation<T,2,V>::data[1] = a;
            equation<T,2,V>::data[2] = b;
        }




        T& c()
        {
            return equation<T,2,V>::data[0];
        }
        T& a()
        {
            return equation<T,2,V>::data[1];
        }
        T& b()
        {
            return equation<T,2,V>::data[2];
        }
        V x(T y)
        {
            return (c() - (b() * y)) / a();
        }
        V y(T x)
        {
            return V(c() - (a() * x)) / V(b());
        }
    private:
    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
