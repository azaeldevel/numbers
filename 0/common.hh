#ifndef OCTETOS_NUMBERS_COMMON_HH
#define OCTETOS_NUMBERS_COMMON_HH

#include <concepts>


#include <core/3/Exception.hh>

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;

    template<typename T> concept number = std::same_as<T, signed char> || std::same_as<T, unsigned char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int>|| std::same_as<T, signed int> || std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, signed long> || std::same_as<T, unsigned long>|| std::same_as<T, signed long long> || std::same_as<T, unsigned long long>  || std::same_as<T, long double>;
    template<typename T> concept decimal = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double>;

    template<number T,unsigned char L,decimal V> class secuence
    {
    protected:
        T data[L];

    public:
        secuence() = default;
        secuence(const T& v)
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }
        secuence(std::initializer_list<T>& l)
        {
            if(l.size() < L) throw core_here::exception("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > L) throw core_here::exception("La cantidad de datos execede la capacidad del objeto");

            unsigned char i = 0;
            for(const T& c : l)
            {
                data[i] = c;
                i++;
            }
        }

        T& operator [](size_t i)
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        const T& operator [](size_t i) const
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }

    };

    template<number T,unsigned char D,decimal V> class vector : public secuence<T,D,V>
    {
    public:
        vector() = default;
        vector(const T& v) : secuence<T,D,V>(v)
        {
        }
        vector(std::initializer_list<T>& l) : secuence<T,D,V>(l)
        {
        }
    };

    template<number T,unsigned char D,decimal V> struct function
    {
    };



    template<number T,unsigned char L,decimal V> class equation : public secuence<T,L,V>
    {
    protected:
        T _c_;

    public:
        equation() = default;
        equation(const T& v) : secuence<T,L,V>(v)
        {
        }
        equation(std::initializer_list<T>& l);


        T& a(size_t i)
        {
            if(i < L) return secuence<T,L,V>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        T a(size_t i) const
        {
            if(i < L) return secuence<T,L,V>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
    };

    /**
    *\brief c + a1x1 + a2x2 + ... + anxn = 0
    **/
    template<number T,unsigned char D,decimal V = float> class first : public equation<T,D,V>
    {
    public:
        first() = default;
    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
