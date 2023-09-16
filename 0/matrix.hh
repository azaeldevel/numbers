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
    template<typename T,core::index auto C,core::index auto R,core::number V = core::convertion<T>::type,core::index I = size_t> class matrix //: public core::array<core::array<T,C,I>,R,I>
    {
    private:
        T data[R][C];

    public:
        matrix() = default;
        constexpr matrix(const T& v)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = v;
                }
            }
        }
        constexpr matrix(const matrix& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[i][j];
                }
            }
        }
        /***
        *\brief Contructor de copias para un matrix
        *
        */
        constexpr matrix(matrix<T,C - 1,R,V> const& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(j < C - 1) data[i][j] = o[i][j];
                    else data[i][j] = 0;
                }
            }
        }
        /***
        *\brief Contructor de copias para un matrix aumentada
        *
        */
        constexpr matrix(matrix<T,C + 1,R,V> const& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[i][j];
                }
            }
        }
        constexpr matrix(const std::initializer_list<T>& l)
        {
            if(l.size() < R * C) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > R * C) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            const T* c = std::data(l);
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = c[(C * i) + j];
                }
            }
        }


        constexpr matrix operator + (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res.data[i][j] = data[i][j] + o.data[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator + (t const& o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = data[i][j] + o;
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
                    res[i][j] = data[i][j] - o[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator  - (t const& o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = data[i][j] - o;
                }
            }

            return res;
        }
        template<core::index auto c> constexpr matrix<T,c,R,V> operator * (const matrix<T,c,C,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,c,R,V> res(0);

            for(I i = 0; i < R; i++)
            {
                for(I j = 0; j < c; j++)
                {
                    for(size_t k = 0; k < C; k++)
                    {
                        res[i][j] += data[i][k] * o[k][j];
                        //res[i][j] = 1;
                    }
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator * (t const& o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = data[i][j] * o;
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator / (t const&  o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = data[i][j] / o;
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
                    data[i][j] = o[i][j];
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
                    if(data[i][j] == o[i][j]) return false;
                }
            }

            return true;
        }

        constexpr T* operator [](I const& i)
        {
            if(i < R) return data[i];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr const T* operator [](I const& i) const
        {
            if(i < R) return data[i];

            throw std::out_of_range("Indice fuera de rango");
        }

        void diagonal(const T& v)
        {
            static_assert(C == R,"Esta operacion es solo para matrizes cuadradas");

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(i == j) data[i][j] = v;
                    else data[i][j] = 0;
                }
            }
        }

        constexpr void transpose (const matrix<T,R,C,V>& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[j][i];
                }
            }
        }

        constexpr matrix adjoint() const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");
            matrix m;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    m[i][j] = cofactor(j,i);
                }
            }

            return m;
        }
        constexpr V cofactor(const I& i,const I& j) const
        {
            V sign = std::pow(V(-1),V((i + 1) + (j + 1)));
            V det = minor(i,j).determinant();
            V ret = sign * det;
            //std::cout << "(" << sign << ") : " <<  i + 1 << " + " << j + 1 << " | det = " << det << "\n";
            //std::cout << "(" << sign << ")(" <<  i + 1 << " + " << j + 1 << ") * " << det << " = " << ret << "\n";
            //std::cout << sign << " * det = " << det << "\n";
            return ret;
        }
        constexpr matrix<T,C - 1, R - 1,V> minor(const I& a,const I& b) const
        {
            I x = 0, y = 0;
            matrix<T,C - 1, R - 1,V> submatrix;

            for (I i = 0; i < R; i++)
            {
                if(i == a) continue;
                for (I j = 0; j < R; j++)
                {
                    if(j == b) continue;
                    //std::cout << "matrix[" << x << "," << y << "]" << BASE::at(i)[j] << "\n";
                    submatrix[x][y] = data[i][j];
                    y++;
                }
                y = 0;
                x++;
            }

            return submatrix;
        }
        constexpr V determinant(const I& i = 0) const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");

            // Base case: 1x1 matrix
            if constexpr (R == 1)
            {
                return data[0][0];
            }

            // Base case: 2x2 matrix
            if constexpr (R == 2)
            {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            }

            if constexpr (R > 2)
            {
                V det = 0;
                for (I j = 0; j < R; j++)
                {
                    det += data[i][j] * cofactor(i,j);
                }
                return det;
            }

            return 1;
        }
        constexpr matrix<V,C,R,V> inverse () const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");

            return adjoint()/determinant();
        }

        /**
        *\brief determinan si la matriz cumple con la propiedad de ser lineal en cada fila
        *
        */
        constexpr bool is_lineal()const;
        /**
        *\brief determinan si la matriz cumple con la propiedad de ser alternate
        *
        */
        constexpr bool is_alternante()const;

        /**
        *\brief determinan si la matriz cumple con la propiedad de ser alternate
        *
        */
        constexpr bool is_singular()const
        {
            return not core::equal(determinant(),0);
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


#if OCTETOS_NUMBERS_TTD == 0
        void print(std::ostream& out) const
        {
            for(size_t j = 0; j < R; j++)
            {
                for(size_t i = 0; i < C; i++)
                {
                    out << data[j][i] << " ";
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



}

#endif // OCTETOS_NUMBERS_MATH_HH
