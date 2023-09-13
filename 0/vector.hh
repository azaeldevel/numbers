#ifndef OCTETOS_NUMBERS_V0_VECTOR_HH
#define OCTETOS_NUMBERS_V0_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<core::number T,size_t L = 3,core::number V = T> class vector : public core::array<T,L>
    {
    private:
        typedef core::array<T,L> BASE;
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
            for(size_t i = 0; i < L; i++) if(BASE::data[i] != s[i]) return false;

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
        constexpr vector operator * (const T& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] * s;

            return res;
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
        constexpr vector& operator = (const vector& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s[i];

            return *this;
        }
        constexpr vector& operator = (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s;

            return *this;
        }



        //>>>>>
        /**
        *\brief Tranformacion de translacion
        *
        **/
        void transl(const vector& v)
        {
            for(size_t i = 0; i < 3; i++) BASE::data[i] += v[i];
        }
        /**
        *\brief tranformacion de scalado
        *
        **/
        void scale(const T& s)
        {
            for(size_t i = 0; i < 3; i++) BASE::data[i] *= s;
        }
        /**
        *\brief Longitud
        *
        **/
        V length() const
        {
            V v = 0;
            for(size_t i = 0; i < 3; i++) v += pow(BASE::data[i],V(2));

            return sqrt(v);
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

        //>>>>>
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
            for(size_t i = 0; i < 3; i++) BASE::data[i] /= l;

            return *this;
        }
        constexpr V dot(const vector& v)
        {
            V newv = 0;
            for(size_t i = 0; i < 3; i++) newv += BASE::data[i] * v[i];

            return newv;
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


    template<core::number T,size_t L,core::number V> constexpr T x(const vector<T,L,V>& v)
    {
        return v[0];
    }
    template<core::number T,size_t L,core::number V> constexpr T y(const vector<T,L,V>& v)
    {
        return v[1];
    }
    template<core::number T,size_t L,core::number V> constexpr T z(const vector<T,L,V>& v)
    {
        return v[2];
    }

    /**
    *\brief Producto escalar entre vectores
    *
    **/
    template<core::number T,size_t L,core::number V> constexpr T scalar(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        T t = 0;
        for(size_t i = 0; i < L; i++) t += v1[i]*v2[i];

        return t;
    }

    /**
    *\brief Producto escalar entre vectores
    *
    **/
    template<core::number T,size_t L,core::number V> constexpr T dot(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        T t = 0;
        for(size_t i = 0; i < L; i++) t += v1[i]*v2[i];

        return t;
    }


    template<core::number T,size_t L,core::number V = T> constexpr vector<T,L,V> normalize(const vector<T,L,V>& v)
    {
        V l = v.length();
        vector<T,L,V> newv = v;
        for(size_t i = 0; i < L; i++) newv[i] /= l;

        return newv;
    }


    template<core::number T,size_t L,core::number V = T> constexpr vector<T,L,V> cross(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        return v1 * v2;
    }



}

#endif // OCTETOS_NUMBERS_MATH_HH
