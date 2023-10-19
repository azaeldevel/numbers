#ifndef OCTETOS_NUMBERS_V0_VECTOR_HH
#define OCTETOS_NUMBERS_V0_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> class vector : public core::array<T,L,I>
    {
    private:
        typedef core::array<T,L,I> BASE;
        typedef vector<T,L,V,I> VECTOR;
    public:
        vector() = default;
        /**
        *\brief Asigna valor a todos los elementos del arreglo
        */
        constexpr vector(const T& v) : BASE(v)
        {
        }
        constexpr vector(const T& x,const T& y)
        {
            static_assert(L == 2);
            BASE::data[0] = x;
            BASE::data[1] = y;
        }
        constexpr vector(const T& x,const T& y,const T& z)
        {
            static_assert(L == 3);
            BASE::data[0] = x;
            BASE::data[1] = y;
            BASE::data[2] = z;
        }
        /*constexpr vector(const T v[L]) : sequence<T,L>(v)
        {
        }*/
        constexpr vector(const vector& v) : BASE(v)
        {
        }
        constexpr vector(const std::initializer_list<T>& l) : BASE(l)
        {
        }

        constexpr bool operator == (const vector& s)
        {
            for(size_t i = 0; i < L; i++) if(not core::equal(BASE::data[i],s[i])) return false;

            return true;
        }


        constexpr vector operator + (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] + s[i];

            return res;
        }
        constexpr vector& operator += (const vector& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] += s[i];

            return *this;
        }
        constexpr vector& operator += (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] += s;

            return *this;
        }
        constexpr vector operator - (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] - s[i];

            return res;
        }
        constexpr vector& operator -= (const vector& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] -= s[i];

            return *this;
        }
        constexpr vector& operator -= (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] -= s;

            return *this;
        }
        constexpr vector operator * (const T& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] * s;

            return res;
        }
        constexpr vector& operator *= (const T& s)
        {
            for(size_t i = 0; i < L; i++) this->at(i) *= s;

            return *this;
        }
        //https://es.wikipedia.org/wiki/Producto_vectorial
        constexpr vector operator * (const vector& s) const
        {
            static_assert(L == 3);
            vector res;

            res[0] = (BASE::data[1] * s[2]) - (BASE::data[2] * s[1]);
            res[1] = (BASE::data[2] * s[0]) - (BASE::data[0] * s[2]);
            res[2] = (BASE::data[0] * s[1]) - (BASE::data[1] * s[0]);

            return res;
        }
        /*constexpr vector& operator = (const vector& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s[i];

            return *this;
        }*/
        constexpr vector& operator = (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s;

            return *this;
        }




        constexpr T& x()
        {
            static_assert(L > 0);
            return BASE::data[0];
        }
        constexpr const T& x() const
        {
            static_assert(L > 0);
            return BASE::data[0];
        }
        constexpr T& y()
        {
            static_assert(L > 1);
            return BASE::data[1];
        }
        constexpr const T& y() const
        {
            static_assert(L > 1);
            return BASE::data[1];
        }
        constexpr T& z()
        {
            static_assert(L > 2);
            return BASE::data[2];
        }
        constexpr const T& z() const
        {
            static_assert(L > 2);
            return BASE::data[2];
        }





        //>>>>>Algebra vectorial
        /**
        *\brief Tranformacion de translacion
        *
        **/
        void transl(const vector& v)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] += v[i];
        }
        /**
        *\brief tranformacion de scalado
        *
        **/
        void scale(const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] *= s;
        }
        /**
        *\brief Longitud
        *
        **/
        V length() const
        {
            V v = 0;
            for(size_t i = 0; i < L; i++) v += pow(BASE::data[i],V(2));

            return sqrt(v);
        }
        /**
        *\brief Longitud
        *
        **/
        V distance(VECTOR const& p) const
        {
            V v = 0;
            for(size_t i = 0; i < L; i++) v += pow(p.data[i] - BASE::data[i],V(2));

            return sqrt(v);
        }

        /**
        *\brief Transformacion de rotacion
        *\param axis Eje de rotacion
        **/
        void rotate(const T& angle,axis a)
        {
            static_assert(L == 3,"Solo para vectores de 3D");

            switch(a)
            {
            case axis::z:
                {
                    T x1 = BASE::data[0], y1 = BASE::data[1];
                    BASE::data[0] = x1 * cos(angle) - y1 * sin(angle);
                    BASE::data[1] = x1 * sin(angle) + y1 * cos(angle);
                }
                break;
            case axis::y:
                {
                    T x1 = BASE::data[0], z1 = BASE::data[2];
                    BASE::data[0] = x1 * cos(angle) - z1 * sin(angle);
                    BASE::data[2] = x1 * sin(angle) + z1 * cos(angle);
                }
                break;
            case axis::x:
                {
                    T y1 = BASE::data[1], z1 = BASE::data[2];
                    BASE::data[1] = y1 * cos(angle) - z1 * sin(angle);
                    BASE::data[2] = y1 * sin(angle) + z1 * cos(angle);
                }
                break;
            }
        }
        /**
        *\brief Transformacion de rotacion, solamente plano xy
        *
        **/
        void rotate(const T& angle)
        {
            static_assert(L == 2,"Solo para vectores de 2D");

            T x1 = BASE::data[0], y1 = BASE::data[1];
            BASE::data[0] = x1 * cos(angle) - y1 * sin(angle);
            BASE::data[1] = x1 * sin(angle) + y1 * cos(angle);
        }


        constexpr vector& normalize()
        {
            V l = length();
            for(size_t i = 0; i < L; i++) BASE::data[i] /= l;

            return *this;
        }
        constexpr void normalize(vector& v)const
        {
            V l = v.length();
            for(size_t i = 0; i < L; i++) v[i] /= l;
        }
        constexpr V dot(const vector& v)const
        {
            //static_assert(L == 3,"Solo para vectores de 3D");
            V newv = 0;
            for(size_t i = 0; i < L; i++) newv += BASE::data[i] * v[i];

            return newv;
        }

        /**
        *\brief Determina si los vectores son paralelos
        *
        **/
        constexpr bool is_parallel(const vector& v)const
        {
            //la comparacion se hace con 5 digitos de presicion
            if(core::equal(dot(v),length() * v.length(),1.0e-5f)) return true;

            return false;
        }
        /**
        *\brief Determina si los vectores son paralelos
        *
        **/
        constexpr bool is_ortho(const vector& v)const
        {
            if(core::equal(dot(v),(V)0)) return true;

            return false;
        }

        /**
        *\brief Obtiene el coseno entre los vectores
        *
        **/
        constexpr V cos(const vector& v) const
        {
            T t = 0;
            for(size_t i = 0; i < L; i++) t += this->at(i) * v[i];
            return t/(length() * v.length());
        }

#if OCTETOS_NUMBERS_TTD == 0
        void print(std::ostream& out, bool delim = true) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < 3; i++)
                {
                    if(i > 0) out << ",";
                    out << BASE::data[i];
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = true) const
        {
            if(delim) out << "(";
                for(size_t i = 0; i < 3; i++)
                {
                    if(i > 0) out << ",";
                    out << BASE::data[i];
                }
            if(delim) out << ")\n";
        }
#endif

    };


    template<core::number T,core::index auto L,core::number V> constexpr T x(const vector<T,L,V>& v)
    {
        return v[0];
    }
    template<core::number T,core::index auto L,core::number V> constexpr T y(const vector<T,L,V>& v)
    {
        return v[1];
    }
    template<core::number T,core::index auto L,core::number V> constexpr T z(const vector<T,L,V>& v)
    {
        return v[2];
    }

    /**
    *\brief Producto escalar entre vectores
    *
    **/
    template<core::number T,core::index auto L,core::number V> constexpr T scalar(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        T t = 0;
        for(size_t i = 0; i < L; i++) t += v1[i]*v2[i];

        return t;
    }

    /**
    *\brief Producto escalar entre vectores
    *
    **/
    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> constexpr T dot(const vector<T,L,V,I>& v1,const vector<T,L,V,I>& v2)
    {
        return v1.dot(v2);
    }

    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> constexpr vector<T,L,V,I> normalize(const vector<T,L,V,I>& v)
    {
        vector<T,L,V> vnew(v);
        vnew.normalize();
        return vnew;
    }
    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> constexpr vector<T,L,V,I> cross (const vector<T,L,V,I>& v1,const vector<T,L,V,I>& v2)
    {
        static_assert(L == 3);
        vector<T,L,V,I> res;

        res[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
        res[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
        res[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);

        return res;
    }

    template<core::number T,core::index auto L,core::number V = T> constexpr vector<T,L,V> cross(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        return v1 * v2;
    }


}

#endif // OCTETOS_NUMBERS_MATH_HH
