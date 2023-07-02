#ifndef OCTETOS_NUMBERS_COMMON_HH
#define OCTETOS_NUMBERS_COMMON_HH

#ifdef OCTETOS_NUMBERS_TTD
    #include <iostream>
#endif // OCTETOS_NUMBERS_TTD

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

    template<typename T> constexpr T factorial(const T& n)
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


#ifdef OCTETOS_NUMBERS_TTD
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

    /**
    *\brief Representa una matriz matematica m x n
    *\param T Tipo de dato
    *\param m Renglones
    *\param n Columnas
    *\param V para operaciones
    **/
    template<typename T,size_t n,size_t m,number V> class matrix : public secuence<secuence<T,n>,m>
    {
    private:

    public:
        matrix() = default;
        constexpr matrix(const T& v) : secuence<secuence<T,n>,m>(v)
        {
        }
        constexpr matrix(std::initializer_list<std::initializer_list<T>>& l)
        {
        }
        constexpr matrix(const matrix& o) : secuence<secuence<T,n>,m>(o)
        {
        }
        constexpr matrix operator + (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < n; i++)
            {
                for(size_t j = 0; j < m; j++)
                {
                    res[i][j] = secuence<secuence<T,n>,m>::data[i][j] + o[i][j];
                }
            }

            return res;
        }
        constexpr matrix operator - (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < n; i++)
            {
                for(size_t j = 0; j < m; j++)
                {
                    res[i][j] = secuence<secuence<T,n>,m>::data[i][j] - o[i][j];
                }
            }

            return res;
        }
        constexpr matrix operator * (const T& o) const
        {
            matrix res;

            for(size_t i = 0; i < n; i++)
            {
                for(size_t j = 0; j < m; j++)
                {
                    res[i][j] = secuence<secuence<T,n>,m>::data[i][j] * o;
                }
            }

            return res;
        }
        template<size_t r> constexpr matrix<T,m,r,V> operator * (const matrix<T,r,n,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,m,r,V> res;

            for(size_t i = 0; i < m; i++)
            {
                for(size_t j = 0; j < r; j++)
                {
                    res[i][j] = 0;
                    for(size_t k = 0; k < n; k++)
                    {
                        res[i][j] += secuence<secuence<T,n>,m>::data[i][k] * o[k][j];
                        //std::cout << "(" << secuence<secuence<T,n>,m>::data[i][k] << "," << o[k][j] << ") ";
                    }
                    //std::cout << "    ";
                }
                //std::cout << "\n";
            }

            return res;
        }

        constexpr matrix& operator = (const matrix& o)
        {

            for(size_t i = 0; i < m; i++)
            {
                for(size_t j = 0; j < n; j++)
                {
                    secuence<secuence<T,n>,m>::data[i][j] = o[i][j];
                }
            }
            return *this;
        }

        //>>>getter and setters
        constexpr size_t columns() const
        {
            return n;
        }
        constexpr size_t rows() const
        {
            return m;
        }


        /**
        *\brief Crea una sub-matriz
        *\param T Tipo de dato
        *\param c Ancho de la matriz
        *\param r Altos de la matriz
        *\param i filas indicadas
        *\param j columnas indicadas
        **/
        template<typename t,size_t w,size_t h> matrix<t,w,h,V> sub(const std::vector<T>& row,const std::vector<T>& columns, bool exclude)
        {
            matrix<t,w,h,V> res;
            T f=0,c;
            for(size_t i = 0; i < m; i++)
            {
                if(std::find(row.begin(),row.end(),i) != row.end()) continue;
                //std::cout << "File  : " << f << "\n";
                c=0;
                for(size_t j = 0; j < n; j++)
                {
                    if(std::find(columns.begin(),columns.end(),j) != columns.end()) continue;
                    //std::cout << "\t" << c << "\n";
                    res[f][c] = secuence<secuence<T,n>,m>::data[i][j];

                    c++;
                }

                f++;
            }

            return res;
        }
        matrix<T,n - 1, m - 1,V> sub(size_t row,size_t columns) const
        {
            if(n != m) throw core_here::exception("La matriz debe ser cuadarada para optener su determintate");
            if(n < 1) throw core_here::exception("No se puede hacer una matriz con menos de un elemento");

            matrix<T,n - 1, m - 1,V> res;
            std::cout << "matriz  : " << res.rows() << " x " << res.columns() << "\n";
            T f=0,c;
            for(size_t i = 0; i < m; i++)
            {
                if(i == row) continue;
                //std::cout << "File  : " << f << "\n";
                c=0;
                for(size_t j = 0; j < n; j++)
                {
                    if(columns  == j) continue;
                    //std::cout << "\t" << c << "\n";
                    res[f][c] = secuence<secuence<T,n>,m>::data[i][j];

                    c++;
                }

                f++;
            }

            return res;
        }
        constexpr T at(size_t i, size_t j) const
        {
            return secuence<secuence<T,n>,m>::data[i][j];
        }
        V det() const
        {
            if(n != m) throw core_here::exception("La matriz debe ser cuadarada para optener su determintate");

            if(n == 1)
            {
                return secuence<secuence<T,n>,m>::data[0][0];
            }
            else if(n == 2)
            {
                V d = 0;
                d = secuence<secuence<T,n>,m>::data[0][0] * secuence<secuence<T,n>,m>::data[1][1];
                d -= secuence<secuence<T,n>,m>::data[0][1] * secuence<secuence<T,n>,m>::data[1][0];

                return d;
            }
            else
            {//Regla de Laplace, https://www.matesfacil.com/matrices/resueltos-matrices-determinantes.html
                //T sign = 1;
                V value = 0;
                for(size_t j = 0; j < n; j++)
                {
                    //std::cout << secuence<secuence<T,n>,m>::data[i][0] << " ";
                    //value += std::pow(-1,j) * at(0,j) * sub(0,j).det();
                }

                return value;
            }

            throw core_here::exception("No esta soportada la determinate para esta dimension");
            return 0;
        }

        constexpr matrix inverse() const
        {
            matrix<T,n * 2,m,V> temp;

            for(size_t i = 0; i < n; i++)
            {
                for(size_t j = 0; j < m; j++)
                {
                    temp[i][j] = secuence<secuence<T,n>,m>::data[i][j];
                }
            }



            matrix res;
            return res;
        }
    };

    /**
    *\brief Representa una matriz aumentada m x n
    *\param T Tipo de dato
    *\param m Renglones
    *\param n Columnas
    *\param V para operaciones
    **/
    template<typename T,size_t n,size_t m,number V> class extended : public matrix<T,n,m,V>
    {
    private:
        matrix<T,1,m,V> _c_;

    public:
        const matrix<T,1,m,V>& c()const
        {
            return _c_;
        }
        matrix<T,1,m,V>& c()
        {
            return _c_;
        }
    };


    template<typename T,size_t D,number V = T> struct function
    {
    };



    /**
    *\brief Representa una equacion con todos los termino no constantes en el lado izq
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param G El grado de la ecuacion
    *\param V Tipo de datos usado para calculos
    **/
    template<typename T,size_t L,size_t G,number V> class equation : public secuence<T,L>
    {
    protected:
        T _c_;

    public:
        equation() = default;
        constexpr equation(std::initializer_list<T> l,const T& c) : secuence<T,L>(l),_c_(c)
        {
        }
        constexpr equation(std::initializer_list<T> l) : secuence<T,L>(l),_c_(0)
        {
        }
        constexpr equation(const secuence<T,L>& s,const T& c) : secuence<T,L>(s),_c_(c)
        {
        }
        constexpr equation(const secuence<T,L>& s) : secuence<T,L>(s),_c_(0)
        {
        }

        constexpr equation& operator = (const T& c)
        {
            _c_ = c;

            return *this;
        }
        constexpr equation& operator = (const equation& e)
        {
            ((secuence<T,L>*)this)->operator =((const secuence<T,L>&)e);
            _c_ = e._c_;

            return *this;
        }


        constexpr T& c()
        {
            return _c_;
        }
        constexpr const T& c() const
        {
            return _c_;
        }
        constexpr T& a(size_t i)
        {
            if(i < L) return secuence<T,L>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& a(size_t i) const
        {
            if(i < L) return secuence<T,L>::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
    };




    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param G Grado de la ecuacion
    *\param V Tipo de datos usado para calculos
    *\param i variable que sera resuelta
    **/
    template<typename T,size_t L,size_t G,number V> V resolve();

}

#endif // OCTETOS_NUMBERS_MATH_HH
