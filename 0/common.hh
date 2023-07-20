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

    template<typename T> concept number = std::same_as<T, signed char> || std::same_as<T, unsigned char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int>|| std::same_as<T, signed int> || std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, signed long> || std::same_as<T, unsigned long>|| std::same_as<T, signed long long> || std::same_as<T, unsigned long long>  || std::same_as<T, long double>;
    template<typename T> concept real = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double>;
    template<typename T> concept natural = std::same_as<T, unsigned char> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int> || std::same_as<T, unsigned long> || std::same_as<T, unsigned long long> || std::same_as<T, size_t>;
    template<typename T> concept integer = std::same_as<T, signed char> || std::same_as<T, unsigned char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int>|| std::same_as<T, signed int> || std::same_as<T, signed long> || std::same_as<T, unsigned long>|| std::same_as<T, signed long long> || std::same_as<T, unsigned long long>;

    template<natural T> constexpr T factorial(const T& n)
    {
        T number = 1;
        for(T i = 1; i <= n; i++) number *= i;

        return number;
    }

    /**
    *\brief Representa una secuacion continua de datos, eqiuvalante al array
    *\param T Tipo de dato
    *\param L La cantidad de datos
    **/
    template<typename T,size_t L> class secuence
    {
    protected:
        T data[L];

    public:
        secuence() = default;
        constexpr secuence(const T& v)
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }
        constexpr secuence(std::initializer_list<T>& l)
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
        constexpr secuence(const secuence& s)
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
        constexpr secuence& operator =(const secuence& s)
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];

            return *this;
        }
        constexpr secuence& operator = (std::initializer_list<T> l)
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
        constexpr void permutation(secuence<secuence<T,L>,factorial(L)>& pers) const
        {
            secuence<T,L> sec = *this;
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
        constexpr void permutations(secuence<T,L>& sec, int i, int n, int& p, secuence<secuence<T,L>,factorial(L)>& pers) const
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

    /**
    *\brief Representa una secuacion continua de datos, eqiuvalante al array
    *\param T Tipo de dato
    *\param L La cantidad de datos
    **/
    template<typename T,natural Z,Z L> class consecutive
    {
    protected:
        T data[L];

    public:
        consecutive() = default;
        constexpr consecutive(const T& v)
        {
            for(size_t i = 0; i < L; i++) data[i] = v;
        }
        constexpr consecutive(std::initializer_list<T>& l)
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
        constexpr consecutive(const consecutive& s)
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
        constexpr consecutive& operator =(const consecutive& s)
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];

            return *this;
        }
        constexpr consecutive& operator = (std::initializer_list<T> l)
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
        constexpr void permutation(consecutive<consecutive<T,Z,L>,Z,factorial(L)>& pers) const
        {
            secuence<T,L> sec = *this;
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
        constexpr void permutations(consecutive<T,Z,L>& sec, int i, int n, int& p, consecutive<consecutive<T,Z,L>,Z,factorial(L)>& pers) const
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

    template<typename T,size_t D,number V> class vector : public secuence<T,D>
    {
    public:
        vector() = default;
        constexpr vector(const T& v) : secuence<T,D>(v)
        {
        }
        constexpr vector(std::initializer_list<T>& l) : secuence<T,D>(l)
        {
        }
    };



    template<typename T,size_t D,number V = T> struct function
    {
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
