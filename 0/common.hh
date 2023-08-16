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

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;

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

    /**
    *\brief Representa una secuacion continua de datos, eqiuvalante al sequence
    *\param T Tipo de dato de la secuencia
    *\param S La cantidad de datos, si es 0, la asignacion es dinamica
    **/
    template<typename T,size_t S> class sequence
    {
    protected:
        T data[S];

    public:
        sequence() = default;
        constexpr sequence(const T& v)
        {
            for(size_t i = 0; i < S; i++) data[i] = v;
        }
        /*constexpr explicit sequence(const T v[L])
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }*/
        constexpr sequence(const std::initializer_list<T>& l)
        {
            if(l.size() < S) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > S) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            const T* c = std::data(l);
            for(size_t i = 0; i < l.size(); i++)
            {
                data[i] = c[i];
            }
        }
        constexpr sequence(const sequence& s)
        {
            for(size_t i = 0; i < S; i++) data[i] = s.data[i];
        }

        constexpr T& operator [](size_t i)
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& operator [](size_t i) const
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& at(size_t i) const
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr T& at(size_t i)
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr sequence& operator =(const sequence& s)
        {
            for(size_t i = 0; i < S; i++) data[i] = s.data[i];

            return *this;
        }
        constexpr sequence& operator = (std::initializer_list<T> l)
        {
            if(l.size() < S) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > S) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            unsigned char i = 0;
            for(const T& c : l)
            {
                data[i] = c;
                i++;
            }

            return *this;
        }


        constexpr size_t size() const
        {
            return S;
        }



#ifdef OCTETOS_NUMBERS_V0_TTD
        void print(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < S; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < S; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
            out << "\n";
        }

#endif // OCTETOS_AVERSO_TTD

    private:

    };

    /**
    *\brief Representa una secuacion continua de datos, eqiuvalante al sequence
    *\param T Tipo de dato de la secuencia
    *\param L 0 para que la asignacion sea dinamica
    **/
    template<typename T> class sequence<T,0>
    {
    protected:
        size_t S;
        T* data;
        bool free;

    public:
        sequence() = default;
        sequence(size_t s, const T& v) : S(s),free(true)
        {
            data = new T[S];
            for(size_t i = 0; i < S; i++) data[i] = v;
        }
        sequence(size_t s, T* v) : S(s),free(false)
        {
            data = v;
        }
        /*constexpr explicit sequence(const T v[L])
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }*/
        sequence(const std::initializer_list<T>& l) : S(l.S),free(true)
        {
            if(l.size() < S) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > S) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            data = new T[S];
            const T* c = std::data(l);
            for(size_t i = 0; i < l.size(); i++)
            {
                data[i] = c[i];
            }
        }
        sequence(const sequence& s)  : S(s.S),free(true)
        {
            data = new T[S];
            for(size_t i = 0; i < S; i++) data[i] = s.data[i];
        }
        ~sequence()
        {
            if(free) delete[] data;
        }

        T& operator [](size_t i)
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        const T& operator [](size_t i) const
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        const T& at(size_t i) const
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        T& at(size_t i)
        {
            if(i < S) return data[i];

            throw std::out_of_range("La cantidad de datos execede la capacidad del objeto");
        }
        sequence& operator =(const sequence& s)
        {
            for(size_t i = 0; i < S; i++) data[i] = s.data[i];

            return *this;
        }
        sequence& operator = (std::initializer_list<T> l)
        {
            if(l.size() < S) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > S) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            unsigned char i = 0;
            for(const T& c : l)
            {
                data[i] = c;
                i++;
            }

            return *this;
        }


        size_t size() const
        {
            return S;
        }



#ifdef OCTETOS_NUMBERS_V0_TTD
        void print(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < S; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < S; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
            out << "\n";
        }

#endif // OCTETOS_AVERSO_TTD

    private:

    };


    template<typename T,size_t D,number V = T> struct function
    {
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
