#ifndef OCTETOS_NUMBERS_VECTOR_HH
#define OCTETOS_NUMBERS_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<number T,size_t L,number V = T> class vector : public sequence<T,L>
    {
    private:
        typedef sequence<T,L> BASE;
    public:
        vector() = default;
        constexpr vector(const T v[L]) : sequence<T,L>(v)
        {
        }
        constexpr vector(const vector& v) : sequence<T,L>(v)
        {
        }
        constexpr vector(const std::initializer_list<T>& l) : sequence<T,L>(l)
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
        constexpr vector operator - (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] - s[i];

            return res;
        }
        constexpr vector operator * (const T& s)
        {
            vector res;
            for(size_t i = 0; i < L; i++) BASE::data[i] *= s;

            return res;
        }


        //>>>>>
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
        V length(const T& s)
        {
            V v = 0;
            for(size_t i = 0; i < L; i++) v += pow(BASE::data[i],V(2));

            return sqrt(v);
        }


        constexpr vector& normalize()
        {
            V l = length();
            for(size_t i = 0; i < L; i++) BASE::data[i] /= l;

            return *this;
        }
    };


    template<number T,size_t L,number V> constexpr T x(const vector<T,L,V>& v)
    {
        return v[0];
    }
    template<number T,size_t L,number V> constexpr T y(const vector<T,L,V>& v)
    {
        return v[1];
    }
    template<number T,size_t L,number V> constexpr T z(const vector<T,L,V>& v)
    {
        return v[2];
    }

    /**
    *\brief Producto escalar entre vectores
    *
    **/
    template<number T,size_t L,number V> constexpr T scalar(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        T t = 0;
        for(size_t i = 0; i < L; i++) t += v1[i]*v2[i];

        return t;
    }



    template<number T,number V> class vector<T,2,V> : public sequence<T,2>
    {
    private:
        typedef sequence<T,2> BASE;

    public:
    vector() = default;
        constexpr vector(const T v[2]) : BASE(v)
        {
        }
        constexpr vector(const vector& v) : BASE(v)
        {
        }
        constexpr vector(const T& x, const T& y)
        {
            BASE::data[0] = x;
            BASE::data[1] = y;
        }
        constexpr vector(const std::initializer_list<T>& l) : BASE(l)
        {
        }

        constexpr bool operator == (const vector& s)
        {
            for(size_t i = 0; i < 2; i++) if(BASE::data[i] != s[i]) return false;

            return true;
        }


        constexpr vector operator + (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < 2; i++) res[i] = BASE::data[i] + s[i];

            return res;
        }
        constexpr vector operator - (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < 2; i++) res[i] = BASE::data[i] - s[i];

            return res;
        }
        constexpr vector operator * (const T& s)
        {
            vector res;
            for(size_t i = 0; i < 2; i++) BASE::data[i] *= s;

            return res;
        }


        //>>>>>
        /**
        *\brief Tranformacion de translacion
        *
        **/
        void transl(const vector& v)
        {
            for(size_t i = 0; i < 2; i++) BASE::data[i] += v[i];
        }
        /**
        *\brief tranformacion de scalado
        *
        **/
        void scale(const T& s)
        {
            for(size_t i = 0; i < 2; i++) BASE::data[i] *= s;
        }
        /**
        *\brief Longitud
        *
        **/
        V length() const
        {
            V v = 0;
            for(size_t i = 0; i < 2; i++) v += pow(BASE::data[i],V(2));

            return sqrt(v);
        }



        constexpr T& x()
        {
            return BASE::data[0];
        }
        constexpr T& y()
        {
            return BASE::data[1];
        }

        //>>>>>
        /**
        *\brief Transformacion de rotacion, solamente plano xy
        *
        **/
        void rotate(const T& angle)
        {
#ifdef OCTETOS_NUMBERS_V0_TTD
#endif
            T x1 = BASE::data[0], y1 = BASE::data[1];
            BASE::data[0] = x1 * cos(angle) - y1 * sin(angle);
            BASE::data[1] = x1 * sin(angle) + y1 * cos(angle);
        }
    };


    template<number T,number V> class vector<T,3,V> : public sequence<T,3>
    {
    private:
        typedef sequence<T,3> BASE;

    public:
    vector() = default;
        constexpr vector(const T v[3]) : BASE(v)
        {
        }
        constexpr vector(const vector& v) : BASE(v)
        {
        }
        constexpr vector(const T& x, const T& y)
        {
            BASE::data[0] = x;
            BASE::data[1] = y;
        }
        constexpr vector(const T& x, const T& y, const T& z)
        {
            BASE::data[0] = x;
            BASE::data[1] = y;
            BASE::data[2] = z;
        }
        constexpr vector(const std::initializer_list<T>& l) : BASE(l)
        {
        }

        constexpr bool operator == (const vector& s)
        {
            for(size_t i = 0; i < 3; i++) if(BASE::data[i] != s[i]) return false;

            return true;
        }


        constexpr vector operator + (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < 3; i++) res[i] = BASE::data[i] + s[i];

            return res;
        }
        constexpr vector& operator += (const vector& s)
        {
            for(size_t i = 0; i < 3; i++) BASE::data[i] += s[i];

            return *this;
        }
        constexpr vector operator - (const vector& s)
        {
            vector res;
            for(size_t i = 0; i < 3; i++) res[i] = BASE::data[i] - s[i];

            return res;
        }
        constexpr vector& operator -= (const vector& s)
        {
            for(size_t i = 0; i < 3; i++) BASE::data[i] -= s[i];

            return *this;
        }
        constexpr vector operator * (const T& s)
        {
            vector res;
            for(size_t i = 0; i < 3; i++) BASE::data[i] *= s;

            return res;
        }
        //https://es.wikipedia.org/wiki/Producto_vectorial
        constexpr vector operator * (const vector& s)
        {
            vector res;
            res[0] = BASE::data[1] * s[2] - BASE::data[2] * s[1];
            res[1] = BASE::data[2] * s[0] - BASE::data[0] * s[2];
            res[2] = BASE::data[0] * s[1] - BASE::data[1] * s[0];

            return res;
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
            return BASE::data[0];
        }
        constexpr T& y()
        {
            return BASE::data[1];
        }
        constexpr T& z()
        {
            return BASE::data[2];
        }

        //>>>>>
        /**
        *\brief Transformacion de rotacion
        *\param axis Eje de rotacion
        **/
        void rotate(const T& angle,axis a)
        {
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


        constexpr vector& normalize()
        {
            V l = length();
            for(size_t i = 0; i < 3; i++) BASE::data[i] /= l;

            return *this;
        }

    };

    template<number T,size_t L,number V = T> constexpr vector<T,L,V> normalize(const vector<T,L,V>& v)
    {
        V l = v.length();
        vector<T,L,V> newv = v;
        for(size_t i = 0; i < L; i++) newv[i] /= l;

        return newv;
    }


    template<number T,size_t L,number V = T> constexpr vector<T,L,V> cross(const vector<T,L,V>& v1,const vector<T,L,V>& v2)
    {
        vector<T,L,V> newv;


        return newv;
    }


}

#endif // OCTETOS_NUMBERS_MATH_HH
