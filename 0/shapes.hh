#ifndef OCTETOS_NUMBERS_SHAPES_V0_HH
#define OCTETOS_NUMBERS_SHAPES_V0_HH

#ifdef OCTETOS_NUMBERS_V0_TTD
    #include <iostream>
#endif

#include "vector.hh"

namespace oct::nums::v0
{
    template<number C, size_t D, size_t P,number V = C>
    class Shape : public sequence<vector<C,D>,P>
    {
    public:

    };


    /*
                    P3
                   /   \
                  /  *  \
                 /       \
                P1-------P2
    */
    /**
    *\brief Triangulo
    *\param C tipo de dato para la coordenada
    *\param D dimension del espacio
    *\param L La cantidad de datos
    **/
    template<number C, size_t D = 3,number V = C>
    class Triangle : public Shape<C,D,3,V>
    {
    public:
        typedef Shape<C,D,3,V> BASE;
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
            V h = length * (sqrt(V(3))/V(2));
            V w = length / V(2);
            //asignado coordenas en x
            BASE::data[0][0] = O.x() - w;
            BASE::data[1][0] = O.x() + w;
            BASE::data[2][0] = O.x();

            BASE::data[0][1] = O.y() - (h/V(2));
            BASE::data[1][1] = O.y() - (h/V(2));
            BASE::data[2][1] = O.y() + (h/V(2));

            BASE::data[0][2] = O.z();
            BASE::data[1][2] = O.z();
            BASE::data[2][2] = O.z();
        }
    };


}

#endif // OCTETOS_NUMBERS_MATH_HH
