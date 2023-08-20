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
    template<typename T,size_t C,size_t R,number V> class matrix : public sequence<sequence<T,C>,R>
    {
    private:
        typedef sequence<sequence<T,C>,R> base;

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
        template<size_t r> constexpr matrix<T,R,r,V> operator * (const matrix<T,r,C,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,R,r,V> res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < r; j++)
                {
                    res[i][j] = 0;
                    for(size_t k = 0; k < C; k++)
                    {
                        res[i][j] += base::data[i][k] * o[k][j];
                        //std::cout << "(" << sequence<sequence<T,n>,m>::data[i][k] << "," << o[k][j] << ") ";
                    }
                    //std::cout << "    ";
                }
                //std::cout << "\n";
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

        //>>>getter and setters
        constexpr size_t columns() const
        {
            return C;
        }
        constexpr size_t rows() const
        {
            return R;
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

}

#endif // OCTETOS_NUMBERS_MATH_HH
