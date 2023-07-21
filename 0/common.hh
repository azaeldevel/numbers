#ifndef OCTETOS_NUMBERS_COMMON_V0_HH
#define OCTETOS_NUMBERS_COMMON_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include <concepts>
#include <vector>
#include <algorithm>
#include <cmath>

#include <core/3/Exception.hh>

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;

    template<typename T> concept natural = std::same_as<T, unsigned char> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int> || std::same_as<T, unsigned long> || std::same_as<T, unsigned long long> || std::same_as<T, size_t>;
    template<typename T> concept integer = std::same_as<T, signed char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, signed int> || std::same_as<T, signed long> || std::same_as<T, signed long long> || natural<T>;
    template<typename T> concept real = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double> || integer<T>;
    template<typename T> concept number = real<T>;

    template<natural T> constexpr T factorial(const T& n)
    {
        T number = 1;
        for(T i = 1; i <= n; i++) number *= i;

        return number;
    }


    /**
    *\brief Representa una secuacion continua de datos, eqiuvalante al array
    *\param T Tipo de dato de la secuencia
    *\param Z Tipo de datos que expresa el rango de numeros que puede manejar(longitud del arreglo)
    *\param L La cantidad de datos
    **/
    template<typename T,natural Z,Z L> class Array
    {
    protected:
        T data[L];

    public:
        Array() = default;
        constexpr Array(const T& v)
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }
        constexpr Array(const std::initializer_list<T>& l)
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
        constexpr Array(const Array& s)
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];
        }

        constexpr T& operator [](size_t i)
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& operator [](size_t i) const
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& at(size_t i) const
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr T& at(size_t i)
        {
            if(i < L) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr Array& operator =(const Array& s)
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];

            return *this;
        }
        constexpr Array& operator = (std::initializer_list<T> l)
        {
            if(l.size() < L) throw core_here::exception("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > L) throw core_here::exception("La cantidad de datos execede la capacidad del objeto");

            unsigned char i = 0;
            for(const T& c : l)
            {
                data[i] = c;
                i++;
            }

            return *this;
        }

        /**
        *\brief Permita los elementos de la secuencia
        **/
        constexpr void permutation(Array<Array<T,Z,L>,Z,factorial(L)>& pers) const
        {
            Array<T,Z,L> sec = *this;
            int index = 0;
            permutations(sec,0,L,index,pers);
        }
        constexpr size_t size() const
        {
            return L;
        }


#ifdef OCTETOS_NUMBERS_V0_TTD
        void print(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < L; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = false) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < L; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
            out << "\n";
        }

#endif // OCTETOS_AVERSO_TTD

    private:

        /**
        *\brief Permita los elementos de la secuencia
        **/
        constexpr void permutations(Array<T,Z,L>& sec, int i, int n, int& p, Array<Array<T,Z,L>,Z,factorial(L)>& pers) const
        {
            // condición base
            if (i == n - 1)
            {
                //std::cout << p << "\n";
                pers[p++] = sec;
                //sec.printLn(std::cout);
                return;
            }

            // procesa cada caracter de la string restante
            for (int j = i; j < n; j++)
            {
                // intercambiar carácter en el índice `i` con el carácter actual
                std::swap(sec[i], sec[j]);        // STL `swap()` usado

                // recurre para la subcadena `str[i+1, n-1]`
                permutations(sec, i + 1, n, p, pers);

                // retroceder (restaurar la string a su estado original)
                std::swap(sec[i], sec[j]);
            }
        }
    };




    template<typename T,size_t D,number V = T> struct function
    {
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
