#ifndef OCTETOS_NUMBERS_SHAPES_V0_HH
#define OCTETOS_NUMBERS_SHAPES_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include "vector.hh"

namespace oct::nums::v0
{
    /**
    *\brief Figura
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param P Cantidad de vertises que tiene
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D, size_t P,number V = C>
    class Shape : public core::array<vector<C,D>,P>
    {
    public:
        typedef core::array<vector<C,D>,P> BASE;

    public:
        Shape() = default;

        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Shape(const vector<C,D> vs[2]) : BASE(vs)
        {
        }

        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        Shape(size_t s, const C& v) : BASE(s,v)
        {
        }

        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        Shape(size_t s, C* v) : BASE(s,v)
        {
        }

        /**
        *\brief Contrulle un line desde un arreglo de puntos(shape)
        **/
        static Shape<C,D,0,V> from(size_t s,Shape<C,D,0,V>& shape)
        {
            return Shape<C,D,0,V>(s,&shape);
        }

        operator C*()
        {
            return &BASE::data;
        }
        operator const C*() const
        {
            return &BASE::data;
        }

        operator void*()
        {
            return &BASE::data;
        }
        operator const void*() const
        {
            return &BASE::data;
        }



#if OCTETOS_NUMBERS_TTD == 0
        void print(std::ostream& out, bool delim = true) const
        {
            for(size_t i = 0; i < P; i++)
            {
                if(i > 0) out << ",";
                BASE::data[i].print(out,delim);
            }
        }
        void printLn(std::ostream& out, bool delim = true) const
        {
            for(size_t i = 0; i < P; i++)
            {
                BASE::data[i].printLn(out,delim);
            }
            out << "\n";
        }
#endif
    };

    /**
    *\brief Line
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Line : public Shape<C,D,2,V>
    {
    public:
        typedef Shape<C,D,2,V> BASE;
    public:
        Line() = default;

        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Line(const vector<C,D> vs[2]) : BASE(vs)
        {
        }
    };

    /**
    *\brief Figura Plana
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param P Cantidad de vertises que tiene
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D,size_t P,number V = C>
    class Plane : public Shape<C,D,P,V>
    {
    public:
        typedef Shape<C,D,P,V> BASE;
        Plane() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Plane(const vector<C,D> vs[3]) : BASE(vs)
        {
        }

    public:

    };


    /**
    *\brief Figuras espacial
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param P Cantidad de vertises que tiene
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D,size_t P,number V = C>
    class Spatial : public Shape<C,D,P,V>
    {
    public:
        typedef Shape<C,D,P,V> BASE;
        Spatial() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Spatial(const vector<C,D> vs[3]) : BASE(vs)
        {
        }

    public:

    };


    /*
                    P1
                   /   \
                  /  *  \
                 /       \
                P3-------P2
    */
    /**
    *\brief Triangulo
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Triangle : public Plane<C,D,3,V>
    {
    public:
        typedef Plane<C,D,3,V> BASE;
    public:
        Triangle() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Triangle(const vector<C,D> vs[3]) : BASE(vs)
        {
        }
        /**
        *\brief Contrulle un triangulo equilatero con centro geometro en O y la longitud indicada
        **/
        constexpr Triangle(const vector<C,D>& O, const C& length)
        {
            equilateral(O,length);
        }
        /**
        *\brief Contrulle un triangulo equilatero con centro geometro en O y la longitud indicada
        **/
        constexpr void equilateral(const vector<C,D>& O, const C& length)
        {
            V h = length * (sqrt(V(3))/V(2));
            V w = length / V(2);

            //asignado coordenas en x
            BASE::data[0][0] = O.x();
            BASE::data[1][0] = O.x() + w;
            BASE::data[2][0] = O.x() - w;

            //asignado coordenas en y
            BASE::data[0][1] = O.y() + (h/V(2));
            BASE::data[1][1] = O.y() - (h/V(2));
            BASE::data[2][1] = O.y() - (h/V(2));

            //asignado coordenas en z
            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
        }

    };


    /**
    *\brief Triangulo
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Equilateral : public Triangle<C,D,V>
    {
    public:
        typedef Triangle<C,D,V> BASE;
    public:
        Equilateral() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Equilateral(const vector<C,D> vs[3]) : BASE(vs)
        {
        }
        /**
        *\brief Contrulle un triangulo equilatero con centro geometro en O y la longitud indicada
        **/
        constexpr Equilateral(const vector<C,D>& O, const C& length)
        {
            BASE::equilateral(O,length);
        }

    };


    /**
    *\brief Triangulo
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Scalene : public Triangle<C,D,V>
    {
    public:
        typedef Triangle<C,D,V> BASE;
    public:
        Scalene() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Scalene(const vector<C,D> vs[3]) : BASE(vs)
        {
        }
        /**
        *\brief Contrulle un triangulo rectagulo
        **/
        constexpr Scalene(const vector<C,D>& O, const C& opposite, const C& adjacent)
        {
            create(O,opposite,adjacent);
        }
        /**
        *\brief Contrulle un triangulo rectagulo
        **/
        constexpr void create(const vector<C,D>& O, const C& opposite, const C& adjacent)
        {
            V h = opposite /V(2);
            V w = adjacent / V(2);

            //asignado coordenas en x
            BASE::data[0][0] = O.x() - w;
            BASE::data[1][0] = O.x() + w;
            BASE::data[2][0] = O.x() - w;

            //asignado coordenas en y
            BASE::data[0][1] = O.y() + h;
            BASE::data[1][1] = O.y() - h;
            BASE::data[2][1] = O.y() - h;

            //asignado coordenas en z
            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
        }
    };


    /**
    *\brief Triangulo
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Isosceles : public Triangle<C,D,V>
    {
    public:
        typedef Triangle<C,D,V> BASE;
    public:
        Isosceles() = default;
        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Isosceles(const vector<C,D> vs[3]) : BASE(vs)
        {
        }
        /**
        *\brief Contrulle un triangulo rectagulo
        **/
        constexpr Isosceles(const vector<C,D>& O, const C& height, const C& width)
        {
            create(O,height,width);
        }
        /**
        *\brief Contrulle un triangulo rectagulo
        **/
        constexpr void create(const vector<C,D>& O, const C& height, const C& width)
        {
            V h = height / V(2);
            V w = height / V(2);

            //asignado coordenas en x
            BASE::data[0][0] = O.x();
            BASE::data[1][0] = O.x() + w;
            BASE::data[2][0] = O.x() - w;

            //asignado coordenas en y
            BASE::data[0][1] = O.y() + h;
            BASE::data[1][1] = O.y() - h;
            BASE::data[2][1] = O.y() - h;

            //asignado coordenas en z
            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
        }
    };




    //https://es.wikipedia.org/wiki/Pir%C3%A1mide_(geometr%C3%ADa)
    /**
    *\brief Piramide
    *\param C tipo de dato para la coordenada
    *\param B Cantidad de vetices en la base
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D, size_t B,number V = C>
    class Pyramid : public Spatial<C,D,B + 1,V>
    {
    public:
        typedef Shape<C,D,B + 1,V> BASE;

        //const size_t vertex_count = B + 1;

    public:
        Pyramid() = default;

        /**
        *\brief Contrulle una piramide
        **/
        constexpr Pyramid(const vector<C,D> vs[B + 1]) : BASE(vs)
        {
        }

        /**
        *\brief Contrulle una piramide
        **/
        constexpr Pyramid(const vector<C,D> vs[B],const vector<C,D>& cusp) : BASE(vs)
        {
        }

        /**
        *\brief Contrulle una piramide
        **/
        constexpr Pyramid(const Plane<C,D,B,V>& base,const vector<C,D>& cusp)
        {
            for(size_t i = 0; i < B; i++)
            {
                BASE::data[i] = base[i];
            }
            BASE::data[B] = cusp;
        }

        /**
        *\brief Contrulle una piramide
        **/
        constexpr Pyramid(const Triangle<C,D,V>& base,const vector<C,D>& cusp)
        {
            for(size_t i = 0; i < B; i++)
            {
                BASE::data[i] = base[i];
            }
            BASE::data[B] = cusp;
        }

    };

    /*
                P1-------P2
                |        |
                |        |
                |        |
                P4-------P3
    */
    /**
    *\brief Cuadrilatero
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D = 3,number V = C>
    class Rectangle : public Plane<C,D,4,V>
    {
    public:
        typedef Plane<C,D,4,V> BASE;
    public:
        Rectangle() = default;

        /**
        *\brief Contrulle un triangulo con los 3 puntos indicados
        **/
        constexpr Rectangle(const vector<C,D> vs[4]) : BASE(vs)
        {
        }

        /**
        *\brief Contrulle un triangulo equilatero con centro geometro en O y la longitud indicada
        **/
        constexpr Rectangle(const vector<C,D>& O, const C& length)
        {
            create(O,length);
        }


        /**
        *\brief Contrulle un rectangulo con centro geometro en O y la longitud indicada
        **/
        constexpr void create(const vector<C,D>& O, const C& length)//const C& height, const C& width
        {
            V m = length / V(2);

            //asignado coordenas en x
            BASE::data[0][0] = O.x() - m;
            BASE::data[1][0] = O.x() + m;
            BASE::data[2][0] = O.x() + m;
            BASE::data[3][0] = O.x() - m;

            //asignado coordenas en y
            BASE::data[0][1] = O.y() + m;
            BASE::data[1][1] = O.y() + m;
            BASE::data[2][1] = O.y() - m;
            BASE::data[3][1] = O.y() - m;

            //asignado coordenas en z
            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
            BASE::data[3][2] = O.z();
        }

        /**
        *\brief Contrulle un rectangulo con centro geometro en O y la longitudes indicadas
        **/
        constexpr void create(const vector<C,D>& O, const C& height, const C& width)//const C& height, const C& width
        {
            V w = width / V(2);
            V h = height / V(2);

            //asignado coordenas en x
            BASE::data[0][0] = O.x() - w;
            BASE::data[1][0] = O.x() + w;
            BASE::data[2][0] = O.x() + w;
            BASE::data[3][0] = O.x() - w;

            //asignado coordenas en y
            BASE::data[0][1] = O.y() + h;
            BASE::data[1][1] = O.y() + h;
            BASE::data[2][1] = O.y() - h;
            BASE::data[3][1] = O.y() - h;

            //asignado coordenas en z
            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
            BASE::data[3][2] = O.z();
        }

    };



    /**
    *\brief Piramide
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param P Cantidad de vertices en la base
    *\param V Tipo de datos para calculos
    **/
    template<number C, size_t D, size_t P,number V = C>
    class Circle : public Plane<C,D,P,V>
    {
    public:
        typedef Shape<C,D,P,V> BASE;
        //const size_t vertex_count = B + 1;

    public:
        Circle() = default;

        /**
        *\brief Contrulle una Circulo
        **/
        constexpr Circle(const vector<C,D> vs[P]) : BASE(vs)
        {
        }

        /**
        *\brief Contrulle una Circulo
        **/
        constexpr Circle(const vector<C,D>& O,const C& radio)
        {
            create(O,radio);
        }

        /**
        *\brief Contrulle una Circulo
        **/
        constexpr void create(const vector<C,D>& O,const C& radio)
        {
            const C slice = (radio * 2)/C(P/2);
            C x = O.x() + radio,y = 0;
            const C r2 = pow(radio,C(2));

            BASE::data[0].x() = x;
            BASE::data[0].y() = O.y();
            BASE::data[0].z() = O.z();

            size_t i = 1;
            for(; i < P/2; i++)
            {
                BASE::data[i].x() = x;
                y = pow(x - O.x(),C(2));
                y = sqrt(r2 - y) + O.y();
                BASE::data[i].y() = y;
                BASE::data[i].z() = O.z();
                x -= slice;
            }

            x = O.x() - radio;
            BASE::data[i].x() = x;
            BASE::data[i].y() = O.y();
            BASE::data[i].z() = O.z();
            i++;
            for(; i < P - 1; i++)
            {
                BASE::data[i].x() = x;
                y = pow(x - O.x(),C(2));
                y = sqrt(r2 - y) + O.y();
                BASE::data[i].y() = -y;
                BASE::data[i].z() = O.z();
                x += slice;
            }
            i = P - 1;
            BASE::data[i].x() = O.x() + radio;
            BASE::data[i].y() = O.y();
            BASE::data[i].z() = O.z();
        }

    };

}

#endif // OCTETOS_NUMBERS_MATH_HH
