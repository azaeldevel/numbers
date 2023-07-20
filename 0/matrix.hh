#ifndef OCTETOS_NUMBERS_MATRIX_HH
#define OCTETOS_NUMBERS_MATRIX_HH

#include "common.hh"

namespace oct::nums::v0
{


    /**
    *\brief Representa una matriz matematica m x n
    *\param T Tipo de dato
    *\param m Renglones
    *\param n Columnas
    *\param V para operaciones
    **/
    template<typename T,size_t n,size_t m,number V> class matrix : public consecutive<consecutive<T,size_t,n>,size_t,m>
    {
    private:
        typedef consecutive<consecutive<T,size_t,n>,size_t,m> base;
    public:
        matrix() = default;
        constexpr matrix(const T& v) : base(v)
        {
        }
        constexpr matrix(std::initializer_list<std::initializer_list<T>>& l)
        {
        }
        constexpr matrix(const matrix& o) : base(o)
        {
        }
        constexpr matrix operator + (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < n; i++)
            {
                for(size_t j = 0; j < m; j++)
                {
                    res[i][j] = base::data[i][j] + o[i][j];
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
                    res[i][j] = base::data[i][j] - o[i][j];
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
                    res[i][j] = base::data[i][j] * o;
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
                        res[i][j] += base::data[i][k] * o[k][j];
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
                    base::data[i][j] = o[i][j];
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
                    res[f][c] = base::data[i][j];

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
            //std::cout << "matriz  : " << res.rows() << " x " << res.columns() << "\n";
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
                    res[f][c] = base::data[i][j];
                    c++;
                }
                f++;
            }

            return res;
        }
        constexpr T at(size_t i, size_t j) const
        {
            return base::data[i][j];
        }
        V det() const
        {
            if(n != m) throw core_here::exception("La matriz debe ser cuadarada para optener su determintate");

            if(n == 1)
            {
                return base::data[0][0];
            }
            else if(n == 2)
            {
                V d = 0;
                d = base::data[0][0] * base::data[1][1];
                d -= base::data[0][1] * base::data[1][0];

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
                    temp[i][j] = base::data[i][j];
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

}

#endif // OCTETOS_NUMBERS_MATH_HH
