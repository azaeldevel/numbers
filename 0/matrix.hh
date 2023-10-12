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
    template<typename T,core::index auto C = 0,core::index auto R = 0,core::number V = core::convertion<T>::type,core::index I = size_t,class A = T> class matrix //: public core::array<core::array<T,C,I>,R,I>
    {
    private:

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
        A data[R][C];
#pragma GCC diagnostic pop

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
        /***
        *\brief Contrulle un matrix de 2x2 a partir de vectores
        *
        */
        template<class B> constexpr matrix(B const& v1,B const& v2)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
        }
        /***
        *\brief Contrulle un matrix de 3x3 a partir de vectores
        *
        */
        template<class B> constexpr matrix(B const& v1,B const& v2,B const& v3)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(0,2) = v1[2];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
            at(1,2) = v2[2];
            at(2,0) = v3[0];
            at(2,1) = v3[1];
            at(2,2) = v3[2];
        }
        /***
        *\brief Contrulle un matrix de 4x4 a partir de vectores
        *
        */
        template<class B> constexpr matrix(B const& v1,B const& v2,B const& v3,B const& v4)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(0,2) = v1[2];
            at(0,3) = v1[3];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
            at(1,2) = v2[2];
            at(1,3) = v2[3];
            at(2,0) = v3[0];
            at(2,1) = v3[1];
            at(2,2) = v3[2];
            at(2,3) = v3[3];
            at(3,0) = v4[0];
            at(3,1) = v4[1];
            at(3,2) = v4[2];
            at(3,3) = v4[3];
        }


        constexpr matrix operator + (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] + o.data[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator + (t const& o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res[i][j] = data[i][j] + o;
                }
            }

            return res;
        }
        constexpr matrix operator - (const matrix& o) const
        {
            matrix res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res[i][j] = data[i][j] - o[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator  - (t const& o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
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

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res[i][j] = data[i][j] * o;
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t,C,R,V> operator / (t const&  o) const
        {
            matrix<t,C,R,V> res;

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
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
        constexpr bool operator == (const matrix& o) const
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(not core::equal(data[i][j],o[i][j])) return false;
                }
            }

            return true;
        }
        constexpr bool operator != (const matrix& o) const
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(core::equal(data[i][j],o[i][j])) return false;
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
        constexpr T& at(I const& i,I const& j)
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr T const& at(I const& i,I const& j) const
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
#ifdef __cpp_multidimensional_subscript
        constexpr T& operator [](I const& i,I const& j)
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr T const& operator [](I const& i,I const& j)const
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
#endif

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
        constexpr matrix<T,R,C,V> transpose () const
        {
            matrix<T,R,C,V> res;
            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res[i][j] = data[j][i];
                }
            }

            return res;
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

    /**
    *\brief Representa una matriz matematica m x n
    *\param T Tipo de dato
    *\param V para operaciones
    **/
    template<typename T> class matrix<T,0,0,float,size_t,T> //: public core::array<core::array<T,C,I>,R,I>
    {
    private:
        size_t R,C;
        T** data;

    public:
        matrix() : R(0),C(0),data(NULL)
        {
        }
        matrix(size_t r,size_t c) : R(r),C(c),data(new T*[R])
        {
            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
            }
        }
        constexpr matrix(size_t r,size_t c,T value) : R(r),C(c),data(new T*[R])
        {
            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = value;
                }
            }
        }
        /*constexpr matrix(const T& v)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = v;
                }
            }
        }*/
        constexpr matrix(const matrix& o) : R(o.R),C(o.C),data(new T*[R])
        {
            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
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
        /*constexpr matrix(matrix<T,C - 1,R,V> const& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(j < C - 1) data[i][j] = o[i][j];
                    else data[i][j] = 0;
                }
            }
        }*/
        /***
        *\brief Contructor de copias para un matrix aumentada
        *
        */
        /*constexpr matrix(matrix<T,C + 1,R,V> const& o)
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[i][j];
                }
            }
        }*/
        constexpr matrix(size_t r,size_t col,const std::initializer_list<T>& l) : R(r),C(col),data(new T*[R])
        {
            if(l.size() < R * C) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size() > R * C) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            const T* c = std::data(l);
            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = c[(C * i) + j];
                }
            }
        }
        constexpr matrix(const std::initializer_list<T>& l)
        {
            const T* c = std::data(l);
            if(l.size() > 2)
            {
                R = c[0];
                C = c[1];
                data = new T*[R];
            }
            else
            {
                throw std::logic_error("No continene la miniman cantidad de datos");
            }

            if(l.size() - 2 < R * C) throw std::logic_error("La cantidad de datos indicados no es suficuente para inicializar el objeto");
            if(l.size()  - 2 > R * C) throw std::logic_error("La cantidad de datos execede la capacidad del objeto");

            c += 2;
            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = c[(C * i) + j];
                }
            }
        }
        /***
        *\brief Contrulle un matrix de 2x2 a partir de vectores
        *
        */
        /*template<class B> constexpr matrix(B const& v1,B const& v2)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
        }*/
        /***
        *\brief Contrulle un matrix de 3x3 a partir de vectores
        *
        */
        /*template<class B> constexpr matrix(B const& v1,B const& v2,B const& v3)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(0,2) = v1[2];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
            at(1,2) = v2[2];
            at(2,0) = v3[0];
            at(2,1) = v3[1];
            at(2,2) = v3[2];
        }*/
        /***
        *\brief Contrulle un matrix de 4x4 a partir de vectores
        *
        */
        /*template<class B> constexpr matrix(B const& v1,B const& v2,B const& v3,B const& v4)
        {
            at(0,0) = v1[0];
            at(0,1) = v1[1];
            at(0,2) = v1[2];
            at(0,3) = v1[3];
            at(1,0) = v2[0];
            at(1,1) = v2[1];
            at(1,2) = v2[2];
            at(1,3) = v2[3];
            at(2,0) = v3[0];
            at(2,1) = v3[1];
            at(2,2) = v3[2];
            at(2,3) = v3[3];
            at(3,0) = v4[0];
            at(3,1) = v4[1];
            at(3,2) = v4[2];
            at(3,3) = v4[3];
        }*/

        constexpr ~matrix()
        {
            for(size_t i = 0; i < R; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }


        constexpr matrix operator + (const matrix& o) const
        {
            if(R != o.R) throw std::logic_error("Los operadore no tiene la misma dimension");
            if(C != o.C) throw std::logic_error("Los operadore no tiene la misma dimension");

            matrix res(R,C);
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] + o.data[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix<t> operator + (t const& o) const
        {
            matrix res(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] + o;
                }
            }

            return res;
        }
        constexpr matrix operator - (const matrix& o) const
        {
            if(R != o.R) throw std::logic_error("Los operadore no tiene la misma dimension");
            if(C != o.C) throw std::logic_error("Los operadore no tiene la misma dimension");

            matrix res(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] - o[i][j];
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix operator  - (t const& o) const
        {
            matrix res(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] - o;
                }
            }

            return res;
        }
        /**
        *\brief realiza la operacion de multimplicacion de matrices
        **/
        constexpr matrix operator * (const matrix& o) const
        {//ref : Book 1(IAL), pag 88.
            if(C != o.R) throw std::logic_error("Los operadore no tiene las demiensiones adecuada");
            //if(R == o.C) throw std::logic_error("Los operadore no tiene la misma dimension");

            matrix res(R,o.C);
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < o.C; j++)
                {
                    for(size_t k = 0; k < C; k++)
                    {
                        res.data[i][j] += data[i][k] * o[k][j];
                    }
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix operator * (t const& o) const
        {
            matrix res(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] * o;
                }
            }

            return res;
        }
        template<core::number t> constexpr matrix operator / (t const&  o) const
        {
            matrix res(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    res.data[i][j] = data[i][j] / o;
                }
            }

            return res;
        }
        constexpr matrix& operator = (const matrix& o)
        {
            if(data)
            {
                if(R != o.R or C != o.C)
                {
                    for(size_t i = 0; i < R; i++)
                    {
                        delete[] data[i];
                    }
                    delete[] data;
                    R = o.R;
                    C = o.C;
                    data = new T*[R];
                }
            }
            else
            {
                R = o.R;
                C = o.C;
                data = new T*[R];
            }

            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[i][j];
                }
            }
            return *this;
        }
        constexpr bool operator == (const matrix& o) const
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(not core::equal(data[i][j],o[i][j])) return false;
                }
            }

            return true;
        }
        constexpr bool operator != (const matrix& o) const
        {
            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    if(core::equal(data[i][j],o[i][j])) return false;
                }
            }

            return true;
        }

        constexpr T* operator [](size_t const& i)
        {
            if(i < R) return data[i];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr const T* operator [](size_t const& i) const
        {
            if(i < R) return data[i];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr T& at(size_t const& i,size_t const& j)
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr T const& at(size_t const& i,size_t const& j) const
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
#ifdef __cpp_multidimensional_subscript
        constexpr T& operator [](I const& i,I const& j)
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
        constexpr T const& operator [](I const& i,I const& j)const
        {
            if(i < R) if(j < C) return data[i][j];

            throw std::out_of_range("Indice fuera de rango");
        }
#endif

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

        constexpr void transpose (const matrix& o)
        {
            if(data)
            {
                if(R != o.C or C != o.R)
                {
                    for(size_t i = 0; i < R; i++)
                    {
                        delete[] data[i];
                    }
                    delete[] data;
                    C = o.R;
                    R = o.C;
                    data = new T*[R];
                }
            }
            else
            {
                C = o.R;
                R = o.C;
                data = new T*[R];
            }

            for(size_t i = 0; i < R; i++)
            {
                data[i] = new T[C];
                for(size_t j = 0; j < C; j++)
                {
                    data[i][j] = o[j][i];
                }
            }
        }

        constexpr matrix transpose () const
        {
            matrix res(C,R);

            for(size_t i = 0; i < C; i++)
            {
                for(size_t j = 0; j < R; j++)
                {
                    res.data[i][j] = data[j][i];
                }
            }

            return res;
        }

        constexpr matrix adjoint() const
        {
            //static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");
            if(R != C) throw std::logic_error("La matriz deve ser cuadrada para aplicar esta operacion.");
            matrix m(R,C);

            for(size_t i = 0; i < R; i++)
            {
                for(size_t j = 0; j < C; j++)
                {
                    m[i][j] = cofactor(j,i);
                }
            }

            return m;
        }
        template<core::number V = core::convertion<T>::type>  constexpr V cofactor(size_t i,size_t j) const
        {
            V sign = std::pow(V(-1),V((i + 1) + (j + 1)));
            V det = minor(i,j).determinant();
            V ret = sign * det;
            //std::cout << "(" << sign << ") : " <<  i + 1 << " + " << j + 1 << " | det = " << det << "\n";
            //std::cout << "(" << sign << ")(" <<  i + 1 << " + " << j + 1 << ") * " << det << " = " << ret << "\n";
            //std::cout << sign << " * det = " << det << "\n";
            return ret;
        }
        template<core::number V = core::convertion<T>::type> constexpr matrix minor( size_t a,size_t b) const
        {
            size_t x = 0, y = 0;
            matrix submatrix(R - 1,C - 1);

            for (size_t i = 0; i < R; i++)
            {
                if(i == a) continue;
                for (size_t j = 0; j < R; j++)
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
        template<core::number V = core::convertion<T>::type> V determinant(size_t i = 0) const
        {
            if(R != C) throw std::logic_error("La matriz deve ser cuadrada para aplicar esta operacion.");

            // Base case: 1x1 matrix
            if (R == 1)
            {
                return data[0][0];
            }

            // Base case: 2x2 matrix
            if (R == 2)
            {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            }

            if (R > 2)
            {
                V det = 0;
                for (size_t j = 0; j < R; j++)
                {
                    det += data[i][j] * cofactor(i,j);
                }
                return det;
            }

            return 1;
        }
        constexpr matrix inverse () const
        {
            //static_assert(R == C,"La matriz deve ser cuadrada para aplicar esta operacion.");
            if(R != C) throw std::logic_error("La matriz deve ser cuadrada para aplicar esta operacion.");

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
        /*constexpr bool is_singular()const
        {
            return not core::equal(determinant(),0);
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

    template<typename T,core::index auto C,core::index auto R,core::number V = core::convertion<T>::type,core::index I = size_t> matrix<T,C,R,V> create_matrix(core::array<T,3> const& v1,core::array<T,3> const& v2,core::array<T,3> const& v3)
    {
        matrix<T,C,R,V> m;
        m[0][0] = v1[0];
        m[0][1] = v1[1];
        m[0][2] = v1[2];
        m[1][0] = v2[0];
        m[1][1] = v2[1];
        m[1][2] = v2[2];
        m[2][0] = v3[0];
        m[2][1] = v3[1];
        m[2][2] = v3[2];
        return m;
    }
    template<typename T,core::index auto C,core::index auto R,core::number V = core::convertion<T>::type,core::index I = size_t> matrix<T,C,R,V> create_matrix(vector<T,3> const& v1,vector<T,3> const& v2,vector<T,3> const& v3)
    {

    }



}

#endif // OCTETOS_NUMBERS_MATH_HH
