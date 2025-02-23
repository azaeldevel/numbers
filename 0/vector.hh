#ifndef OCTETOS_NUMBERS_V0_VECTOR_HH
#define OCTETOS_NUMBERS_V0_VECTOR_HH

#include "common.hh"

namespace oct::nums::v0
{

    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> class vector : public core::array<T,L,I>
    {
    private:
        typedef core::array<T,L,I> BASE;
        //typedef vector<T,L,V,I> VECTOR;
    public:
        vector() = default;
        /**
        *\brief Asigna valor a todos los elementos del arreglo
        */
        constexpr vector(const T& x) : BASE(x)
        {
        }
        constexpr vector(const T& x,const T& y) : BASE(x,y)
        {
            //static_assert(L == 2);
            if constexpr (L == 3)
            {
                z() = 0;
            }
        }
        constexpr vector(const T& x,const T& y,const T& z) : BASE(x,y,z)
        {
            //static_assert(L == 3);
        }
        /*constexpr vector(const T v[L]) : sequence<T,L>(v)
        {
        }*/
        constexpr vector(const vector& v) : BASE(v)
        {
        }

        /**
        *\brief crea un vertor con los datos especificados
        *\param len longitud
        *\param angle angulo
        *\param radians true si angulo es en radianes, false si es sexagesimal
        */
        constexpr void create(const T& len, const T& angle, bool radians = true)
        {
            T a;
            if(radians)
            {
                if(angle > 0) a = angle;
                else a = (T(2) * std::numbers::pi ) - angle;
            }
            else
            {
                if(angle > 0) a =  core::degree_to_radian(angle);
                else a =  core::degree_to_radian(T(360) - angle);
            }
            BASE::data[0] = std::cos(a) * len;
            BASE::data[1] = std::sin(a) * len;
            for(size_t i = 2; i < L; i++) BASE::data[i] = T(0);
        }

        /**
        *\brief crea un vertor con los datos especificados
        *\param len longitud
        */
        constexpr void create(const T& len, const vector& v1,const vector& v2)
        {
            vector v = v2 - v1;
            v = v.unit();
            v = v * len;
            *this = v;
        }

        /**
        *\brief crea un vertor con los datos especificados
        *\param len longitud
        */
        constexpr void create(const T& len, const vector& direction)
        {
            vector v = direction.unit();
            v = v * len;
            *this = v;
        }

        /**
        *\brief crea un vector con inclinacion y longitud indicados
        */
        /*constexpr void create_from(const T& length,const T& angle,bool degree = true)
        {
            T a;
            if(degree)
            {
                a =  core::degree_to_radian(angle);
            }
            else
            {
                a = angle;
            }
            BASE::data[0] = std::cos(a) * length;
            BASE::data[1] = std::sin(a) * length;
            for(size_t i = 2; i < L; i++) BASE::data[i] = T(0);
        }*/

        /**
        *\brief
        */
        constexpr vector(const std::initializer_list<T>& l) : BASE(l)
        {
        }
        /*constexpr vector(T&& v) : BASE(std::move(v))
        {
        }*/



        constexpr bool operator == (const vector& s)
        {
            for(size_t i = 0; i < L; i++) if(not core::equal(BASE::data[i],s[i])) return false;

            return true;
        }

        constexpr bool operator != (const vector& s)
        {
            for(size_t i = 0; i < L; i++) if(core::diff(BASE::data[i],s[i])) return false;

            return true;
        }



        constexpr vector operator + (const vector& s) const
        {
            vector res = *this;
            for(size_t i = 0; i < L; i++) res[i] = BASE::data[i] + s[i];

            return res;
        }
        constexpr vector operator - (const vector& s)const
        {
            vector res = *this;
            for(size_t i = 0; i < L; i++) res[i] = res[i] - s[i];

            return res;
        }
        constexpr vector operator * (const T& s) const
        {
            vector res = *this;
            for(size_t i = 0; i < L; i++) res[i] = res[i] * s;

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
        constexpr vector operator / (const T& s) const
        {
            vector res = *this;
            for(size_t i = 0; i < L; i++) res[i] = res[i] / s;

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
        constexpr vector& operator *= (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] *= s;

            return *this;
        }


        constexpr vector& operator = (const T& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s;

            return *this;
        }

        constexpr vector& operator = (const vector& s)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] = s[i];

            return *this;
        }




        //[[deprecated("Inutil cuando se usan tranformaciones o planos distintos")]]
        constexpr T& x()
        {
            static_assert(L > 0);
            return BASE::data[0];
        }
        //[[deprecated("Inutil cuando se usan tranformaciones o planos distintos")]]
        constexpr const T& x() const
        {
            static_assert(L > 0);
            return BASE::data[0];
        }
        //[[deprecated("Inutil cuando se usan tranformaciones o planos distintos")]]
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
        void translate(const vector& v)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] += v[i];
        }
        /**
        *\brief Tranformacion de translacion
        *
        **/
        void translate(const T& t)
        {
            for(size_t i = 0; i < L; i++) BASE::data[i] += t;
        }
        /**
        *\brief Tranformacion de translacion
        *
        **/
        void translate(const T& t, size_t i)
        {
            BASE::data[i] += t;
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
        V distance(vector const& p) const
        {
            V v = 0;
            for(size_t i = 0; i < L; i++) v += pow(p.data[i] - BASE::data[i],V(2));

            return sqrt(v);
        }

        /**
        *\brief Longitud
        *
        **/
        V distance(T x, T y) const
        {
            V v = 0;
            v += pow(x - BASE::data[0],V(2));
            v += pow(y - BASE::data[1],V(2));

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
            //static_assert(L == 2,"Solo para vectores de 2D");

            T x1 = BASE::data[0], y1 = BASE::data[1];
            BASE::data[0] = x1 * std::cos(angle) - y1 * std::sin(angle);
            BASE::data[1] = x1 * std::sin(angle) + y1 * std::cos(angle);
        }

        /**
        *\brief Vertor ortogonal en plano XY
        */
        vector orthogonal()const
        {
            vector v;
            v[0] = -BASE::data[1];
            v[1] = BASE::data[0];

            for(size_t i = 2; i < L; i++) v[i] = BASE::data[i];

            return v;
        }


        /*constexpr vector normalize()const
        {
            vector v = *this;
            V l = length();
            for(size_t i = 0; i < L; i++) v[i] /= l;

            return v;
        }*/
        constexpr vector unit()const
        {
            vector v = *this;
            V l = length();
            for(size_t i = 0; i < L; i++) v[i] /= l;

            return v;
        }
        /*constexpr void normalize(vector& v)
        {
            V l = v.length();
            for(size_t i = 0; i < L; i++) v[i] /= l;
        }*/
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
            if constexpr (L == 2) if(core::equal(dot(v),(V)0)) return false;

            return true;
        }

        /**
        *\brief Determina si los vectores son paralelos
        *
        **/
        constexpr bool is_orthogonal(const vector& v)const
        {
            if constexpr (L == 2) if (core::equal(dot(v),V(0))) return true;

            return false;
        }

        /**
        *\brief Obtiene el seno entre el vector y eje x
        *
        **/
        constexpr V sin() const
        {
            return BASE::data[1]/length();
        }

        /**
        *\brief Obtiene el coseno entre el vector y eje x
        *
        **/
        constexpr V cos() const
        {
            return BASE::data[0]/length();
        }

        /**
        *\brief Obtiene el tan entre el vector y eje x
        *
        **/
        constexpr V tan() const
        {
            return BASE::data[1]/BASE::data[0];
        }

        /**
        *\brief Obtiene el csc entre el vector y eje x
        *
        **/
        constexpr V csc() const
        {
            return length()/BASE::data[1];
        }

        /**
        *\brief Obtiene el sec entre el vector y eje x
        *
        **/
        constexpr V sec() const
        {
            return length()/BASE::data[0];
        }

        /**
        *\brief Obtiene el cot entre el vector y eje x
        *
        **/
        constexpr V cot() const
        {
            return BASE::data[0]/BASE::data[1];
        }

        /**
        *\brief Area entre los vectores
        *
        **/
        constexpr V area(const vector& v) const
        {
            return dot(v.orthogonal()) / V(2);
        }

        /**
        *\brief Componente del vector en la direccion de b
        */
        V component(const vector& b)const
        {
            return (dot(b)/b.length());
        }



        /**
        *\brief Componente del vector en la direccion de b
        */
        V component_parellel()const
        {
            return cos();
        }

        /**
        *\brief Proeyeccion del vector en la direccion de b
        */
        vector proyection(const vector& b)const
        {
            return b.unit() * component(b);
        }

        template<core::index auto S> void line(const vector& direction, core::array<vector,S>& l)const
        {
            static_assert(L > 1);

            l[0] = *this;
            for(size_t i = 1; i < S; i++)
            {
                l[i] = this->operator + (direction * i);
            }
        }

        /**
        *\brief Expresa el vector como una combinacion lineal de a y b
        */
        core::array<T,L> lineal(const vector& a, const vector&b) const
        {
            static_assert(L == 2);

            V t = (a.orthogonal().dot(*this))/(a.orthogonal().dot(b));
            V s = (b.orthogonal().dot(*this))/(b.orthogonal().dot(a));
            core::array<T,L> res;
            res[0] = t;
            res[1] = s;
            return res;
        }


        constexpr T angle(bool radian = true) const
        {
            T angle = std::atan(BASE::data[1]/BASE::data[0]);
            if(radian)
            {
                return angle;
            }
            else
            {
                if(BASE::data[0] > 0 and BASE::data[1] > 0) return core::radian_to_degree(angle);//primer cuiadrante
                else if(BASE::data[0] < 0 and BASE::data[1] > 0) return T(90) - core::radian_to_degree(angle);//segundo cuiadrante
                else if(BASE::data[0] < 0 and BASE::data[1] < 0) return T(180) + core::radian_to_degree(angle);//tercer cuiadrante
                else if(BASE::data[0] > 0 and BASE::data[1] < 0) return T(270) - core::radian_to_degree(angle);//cuarto cuiadrante
            }

            return T(0);
        }


#if OCTETOS_NUMBERS_TTD == 0
        void print(std::ostream& out, bool delim = true) const
        {
            if(delim) out << "(";
                if(L == 2)
                {
                    out << BASE::data[0] << "," << BASE::data[1];
                }
                else if(L == 3)
                {
                    out << BASE::data[0] << "," << BASE::data[1] << "," << BASE::data[2];
                }
                else
                {
                    for(size_t i = 0; i < L ; i++)
                    {
                        out << "," << BASE::data[i];
                    }
                }
            if(delim) out << ")";
        }
        void printLn(std::ostream& out, bool delim = true) const
        {
            if(delim) out << "(";
                if(L == 2)
                {
                    out << BASE::data[0] << "," << BASE::data[1];
                }
                else if(L == 3)
                {
                    out << BASE::data[0] << "," << BASE::data[1] << "," << BASE::data[2];
                }
                else
                {
                    for(size_t i = 0; i < L ; i++)
                    {
                        out << "," << BASE::data[i];
                    }
                }
            if(delim) out << ")\n";
        }
#endif

    };

    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> vector<T,L,V,I> operator * (const T& s,const vector<T,L,V,I>& v)
    {
        vector<T,L,V,I> res(0);
        for(size_t i = 0; i < L; i++)
        {
            res[i] = v[i] * s;
        }

        return res;
    }

    template<core::number T,core::index auto L = 3,core::number V = core::convertion_to_real<T>::type,core::index I = size_t> bool equal(const vector<T,L,V,I>& v1,const vector<T,L,V,I>& v2, const T& epsilon = std::numeric_limits<T>::epsilon())
    {
        for(size_t i = 0; i < L; i++)
        {
            if(not core::equal(v1[i],v2[i],epsilon)) return false;
        }

        return true;
    }

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
