#ifndef OCTETOS_NUMBERS_COMMON_HH
#define OCTETOS_NUMBERS_COMMON_HH

#ifdef OCTETOS_NUMBERS_TTD
    #include <iostream>
#endif // OCTETOS_NUMBERS_TTD

#include <concepts>


#include <core/3/Exception.hh>

namespace oct::nums::v0
{
    namespace core_here = oct::core::v3;

    template<typename T> concept number = std::same_as<T, signed char> || std::same_as<T, unsigned char> || std::same_as<T, signed short> || std::same_as<T, signed short> || std::same_as<T, unsigned short> || std::same_as<T, unsigned int>|| std::same_as<T, signed int> || std::same_as<T, float> || std::same_as<T, double> || std::same_as<T, signed long> || std::same_as<T, unsigned long>|| std::same_as<T, signed long long> || std::same_as<T, unsigned long long>  || std::same_as<T, long double>;
    template<typename T> concept real = std::same_as<T, float> || std::same_as<T, double>  || std::same_as<T, long double>;

    template<typename T> constexpr  T factorial(const T& n)
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
    template<typename T,unsigned char L> class secuence
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
        secuence(const secuence& s)
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];
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
        secuence& operator =(const secuence& s) const
        {
            for(size_t i = 0; i < L; i++) data[i] = s.data[i];
        }

        /**
        *\brief Permita los elementos de la secuencia
        **/
        void permutation() const
        {
            //secuence<secuence<T,L>,L> sec;
            for(size_t i = 0; i < L; i++)
            {
                for(size_t j = 0; j < L; j++)
                {
                    if(i == j) continue;

                }
            }
        }

#ifdef OCTETOS_NUMBERS_TTD
        void print(std::ostream& out, bool delim = true) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < L; i++)
                {
                    if(i > 0) out << ",";
                    out << data[i];
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = true) const
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

    };
    template<number T,unsigned char W,unsigned char H,template<number,unsigned char> typename C> class secuence<C<T,W>,H>
    {
    protected:
        C<T,W> data[H];

    public:
        secuence() = default;
        secuence(const T& v)
        {
            for(size_t i = 0; i < H; i++) for(size_t j = 0; j < W; j++) data[i][j] = v;
        }
        secuence(std::initializer_list<T>& l)
        {
            if(l.size() < H) throw core_here::exception("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > H) throw core_here::exception("La cantidad de datos execede la capacidad del objeto");

            unsigned char i = 0;
            for(const T& c : l)
            {
                data[i] = c;
                i++;
            }
        }
        secuence(const secuence& s)
        {
            for(size_t i = 0; i < H; i++) data[i] = s.data[i];
        }

        C<T,W>& operator [](size_t i)
        {
            if(i < H) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        const C<T,W>& operator [](size_t i) const
        {
            if(i < H) return data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        secuence& operator =(const secuence& s) const
        {
            for(size_t i = 0; i < H; i++) data[i] = s.data[i];
        }



#ifdef OCTETOS_NUMBERS_TTD
        void print(std::ostream& out) const
        {
            for(size_t i = 0; i < H; i++)
            {
                if(i > 0) out << "\n";
                data[i].print(out,false);
            }
        }
        void printLn(std::ostream& out) const
        {
            for(size_t i = 0; i < H; i++)
            {
                if(i > 0) out << "\n";
                data[i].print(out,false);
            }
            out << "\n";
        }
#endif // OCTETOS_AVERSO_TTD
    };



    /**
    *\brief Representa una matriz matematica m x n
    *\param T Tipo de dato
    *\param m Ancho de la matriz
    *\param n Altos de la matriz
    **/
    template<number T,unsigned char n,unsigned char m,number V = T> class matrix : public secuence<secuence<T,n>,m>
    {
    public:
        matrix() = default;
        matrix(const T& v) : secuence<secuence<T,n>,m>(v)
        {
        }
        matrix(std::initializer_list<std::initializer_list<T>>& l)
        {
        }

        /**
        *\brief Representa una matriz matematica m x n
        *\param T Tipo de dato
        *\param w Ancho de la matriz
        *\param h Altos de la matriz
        *\param i si i es 0 o mayor se elimina dicha fila
        *\param j si j es 0 o mayor se elimina dicha columna
        **/
        template<number t,unsigned char w,unsigned char h,number v = t> matrix<t,w,h,v> submatrix(signed i, signed j);
    };


    template<number T,unsigned char D,number V = T> class vector : public secuence<T,D>
    {
    public:
        vector() = default;
        vector(const T& v) : secuence<T,D>(v)
        {
        }
        vector(std::initializer_list<T>& l) : secuence<T,D>(l)
        {
        }
    };

    template<number T,unsigned char D,number V = T> struct function
    {
    };



    /**
    *\brief Representa una equacion con todos los termino no constantes en el lado izq
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param G El grado de la ecuacion
    *\param V Tipo de datos usado para calculos
    **/
    template<number T,unsigned char L,unsigned char G,number V = T> class equation : public secuence<T,L>
    {
    protected:
        T _c_;

    public:
        equation() = default;
        equation(const T& v) : secuence<T,L>(v)
        {
        }
        equation(std::initializer_list<T>& l);


        T& a(size_t i)
        {
            if(i < L) return secuence<T,L>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        T a(size_t i) const
        {
            if(i < L) return secuence<T,L>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
