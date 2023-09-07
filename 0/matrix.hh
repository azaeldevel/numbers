#ifndef OCTETOS_NUMBERS_MATRIX_HH
#define OCTETOS_NUMBERS_MATRIX_HH

#include "common.hh"
#include "vector.hh"

namespace oct::nums::v0
{


    /**
    *\brief Representa una matriz matematica m x n
    *\param T Tipo de dato
    *\param R Renglones
    *\param C Columnas
    *\param V para operaciones
    **/
    template<typename T,size_t C,size_t R,core::number V = T> class matrix : public core::array<core::array<T,C>,R>
    {
    private:
        typedef core::array<core::array<T,C>,R> base;

    public:
        matrix() = default;
        constexpr matrix(const T& v) : base(v)
        {
        }
        constexpr matrix(const matrix& o) : base(o)
        {
        }


        constexpr matrix operator + (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = base::data[i][j] + o[i][j];
                }
            }

            return res;
        }
        constexpr matrix operator + (const T& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = base::data[i][j] + o;
                }
            }

            return res;
        }
        constexpr matrix operator - (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = base::data[i][j] - o[i][j];
                }
            }

            return res;
        }
        constexpr matrix operator - (const T& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = base::data[i][j] - o;
                }
            }

            return res;
        }
        template<size_t c> constexpr matrix<T,R,c,V> operator * (const matrix<T,c,C,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,R,c,V> res(0);

            for(size_t k = 0; k < C; k++)
            {
                for(size_t i = 0; i < R; i++)
                {
                    for(size_t j = 0; j < c; j++)
                    {
                        //std::cout << k << " : " << i << "," << j << "\n";
                        res[i][j] += base::data[i][k] * o[k][j];
                    }
                }
            }

            return res;
        }
        /*template<size_t c> constexpr matrix<T,R,c,V> mul (const matrix<T,c,C,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,R,c,V> res(0);

            for(size_t k = 0; k < c; k++)
            {
                for(size_t i = 0; i < R; i++)
                {
                    for(size_t j = 0; j < c; j++)
                    {
                        std::cout << k << " : " << i << "," << j << "";
                        res[i][j] += base::data[i][k] * o[k][j];
                    }
                }
            }

            return res;
        }*/
        constexpr matrix operator * (const T& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = base::data[i][j] * o;
                }
            }

            return res;
        }

        constexpr matrix& operator = (const matrix& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    base::data[i][j] = o[i][j];
                }
            }
            return *this;
        }

        constexpr bool operator == (const matrix& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(base::data[i][j] == o[i][j]) return false;
                }
            }

            return true;
        }

        /*operator T*()
        {
            return (T*)&base::data[0];
        }
        operator const T*() const
        {
            return (T*)&base::data[0];
        }
        operator void*()
        {
            return (void*)&base::data[0];
        }
        operator const void*() const
        {
            return (const void*)&base::data[0];
        }*/

        //>>>getter and setters
        constexpr size_t columns() const
        {
            return C;
        }
        constexpr size_t rows() const
        {
            return R;
        }


#if OCTETOS_NUMBERS_TTD == 0
        void print(std::ostream& out) const
        {
            for(size_t j = 0; j < R; j++)
            {
                for(size_t i = 0; i < C; i++)
                {
                    out << base::data[j][i] << " ";
                }
                out << "\n";
            }
        }
        void printLn(std::ostream& out) const
        {
            print(out);
            out << "\n";
        }
#endif // OCTETOS_AVERSO_TTD

    };

    /**
    *\brief Representa una matriz aumentada m x n
    *\param T Tipo de dato
    *\param m Renglones
    *\param n Columnas
    *\param V para operaciones
    **/
    template<typename T,size_t n,size_t m,core::number V> class extended : public matrix<T,n,m,V>
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


}

#endif // OCTETOS_NUMBERS_MATH_HH
