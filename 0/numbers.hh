#ifndef OCTETOS_NUMBERS_MATH_HH
#define OCTETOS_NUMBERS_MATH_HH

#include <concepts>


#include <core/3/Exception.hh>

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;

    template<typename T> concept number = std::same_as<T, signed char> || std::same_as<T, unsigned char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int>|| std::same_as<T, signed int> || std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, signed long> || std::same_as<T, unsigned long>|| std::same_as<T, signed long long> || std::same_as<T, unsigned long long>  || std::same_as<T, long double>;
    template<typename T> concept decimal = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double>;

    template<number T,unsigned char D,decimal V> struct vector
    {
    };

    template<number T,unsigned char D,decimal V> struct function
    {
    };



    template<number T,unsigned char D,decimal V> class equation
    {

    protected:
        T data[D + 1];
    };

    /**
    *\brief c + a1x1 + a2x2 + ... + anxn = 0
    **/
    template<number T,unsigned char D,decimal V = float> class first : public equation<T,D,V>
    {
    };
    template<number T,decimal V> class first<T,1,V> : public equation<T,1,V>
    {
    public:
        first(T c, T a)
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
        first(T c, T a)
        {
            equation<T,2,V>::data[0] = c;
            equation<T,2,V>::data[1] = a;
        }
        first(T c, T a,T b)
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


    template<number T,unsigned char D,decimal V> class second : public equation<T,D,V>
    {

    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
