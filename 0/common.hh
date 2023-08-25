#ifndef OCTETOS_NUMBERS_COMMON_V0_HH
#define OCTETOS_NUMBERS_COMMON_V0_HH

#if OCTETOS_NUMBERS_TTD == 0
    #include <iostream>
#endif

#include <concepts>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

#include <core/3/Exception.hh>
#include <core/3/arrays.hh>

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;
    namespace core = oct::core::v3;

    template<typename T> concept natural = std::same_as<T, unsigned char> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int> || std::same_as<T, unsigned long> || std::same_as<T, unsigned long long> || std::same_as<T, size_t>;
    template<typename T> concept integer = std::same_as<T, signed char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, signed int> || std::same_as<T, signed long> || std::same_as<T, signed long long> || natural<T>;
    template<typename T> concept real = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double> || integer<T>;
    template<typename T> concept number = real<T>;
    //template<typename T> concept dimension = static_assert(T == 2);

    enum class axis : unsigned char
    {
        x,
        y,
        z
    };

    template<number N>
    class Number
    {
    private:
        N n;

    public:
        Number() = default;
        Number(const N& v) : n(v)
        {
        }

        operator N&()
        {
            return n;
        }
        operator const N&() const
        {
            return n;
        }
    };

    template<number N>
    class Degree : public Number<N>
    {
    private:

    public:
        typedef Number<N> BASE;

    public:
        Degree() = default;
        Degree(const N& v) : BASE(v)
        {
        }

    };


    template<natural T> constexpr T factorial(const T& n)
    {
        T number = 1;
        for(T i = 1; i <= n; i++) number *= i;

        return number;
    }

    constexpr bool is_equal(const float& a,const float& b)
    {
        constexpr float min = std::numeric_limits<float>::min() * 2;

        if(a < b)
        {
            if(min < b - a) return true;
        }
        else if(a > b)
        {
            if(min < a - b) return true;
        }

        return false;
    }




    template<typename T,size_t D,number V = T> struct function
    {
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
