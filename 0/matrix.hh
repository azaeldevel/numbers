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
    template<typename T,core::index auto C,core::index auto R,core::number V = T> class matrix : public core::array<core::array<T,C>,R>
    {
    private:
        typedef core::array<core::array<T,C>,R> BASE;

    public:
        matrix() = default;
        constexpr matrix(const T& v) : BASE(v)
        {
        }
        constexpr matrix(const matrix& o) : BASE(o)
        {
        }
        /***
        *\brief Contructor de copias para un matrix
        *
        */
        constexpr matrix(const matrix<T,C - 1,R,V>& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(j < C - 1) BASE::data[i][j] = o[i][j];
                    else BASE::data[i][j] = 0;
                }
            }
        }
        /***
        *\brief Contructor de copias para un matrix aumentada
        *
        */
        constexpr matrix(const matrix<T,C + 1,R,V>& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    BASE::data[i][j] = o[i][j];
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
                    BASE::data[i][j] = c[(C * i) + j];
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
                    res[i][j] = BASE::data[i][j] + o[i][j];
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
                    res[i][j] = BASE::data[i][j] + o;
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
                    res[i][j] = BASE::data[i][j] - o[i][j];
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
                    res[i][j] = BASE::data[i][j] - o;
                }
            }

            return res;
        }
        template<core::index auto c> constexpr matrix<T,R,c,V> operator * (const matrix<T,c,C,V>& o) const
        {//ref : Book 1(IAL), pag 88.
            matrix<T,R,c,V> res(0);

            for(size_t k = 0; k < C; k++)
            {
                for(size_t i = 0; i < R; i++)
                {
                    for(size_t j = 0; j < c; j++)
                    {
                        //std::cout << k << " : " << i << "," << j << "\n";
                        res[i][j] += BASE::data[i][k] * o[k][j];
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
                    res[i][j] = BASE::data[i][j] * o;
                }
            }

            return res;
        }
        constexpr matrix operator / (const T& o) const
        {
            matrix res;

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = BASE::data[i][j] / o;
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
                    BASE::data[i][j] = o[i][j];
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
                    if(BASE::data[i][j] == o[i][j]) return false;
                }
            }

            return true;
        }

        void diagonal(const T& v)
        {
            static_assert(C == R,"Esta operacion es solo para matrizes cuadradas");

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(i == j) BASE::data[i][j] = v;
                    else BASE::data[i][j] = 0;
                }
            }
        }

        constexpr void transpose (const matrix<T,R,C,V>& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    BASE::data[i][j] = o[j][i];
                }
            }
        }

        constexpr matrix adj() const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");
            matrix m(*this);




            return m;
        }
        constexpr matrix<T,C-1,R-1,V> cofactor() const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");





            return 0;
        }
        constexpr V det () const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");





            return 1;
        }
        constexpr matrix inverse () const
        {
            static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");

            return adj()/det();
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
                    out << BASE::data[j][i] << " ";
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
