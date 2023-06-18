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
        T data[L + 1];
    };

    template<number T,unsigned char D,decimal V> class vector : public secuence<T,D,V>
    {
    };

    template<number T,unsigned char D,decimal V> struct function
    {
    };



    template<number T,unsigned char D,decimal V> class equation : public secuence<T,D,V>
    {

    protected:

    public:
        T& a(size_t i)
        {
            return equation<T,2,V>::data[i];
        }
        T a(size_t i) const
        {
            return equation<T,2,V>::data[i];
        }
    };

    /**
    *\brief c + a1x1 + a2x2 + ... + anxn = 0
    **/
    template<number T,unsigned char D,decimal V = float> class first : public equation<T,D,V>
    {
    };





}

#endif // OCTETOS_NUMBERS_MATH_HH
