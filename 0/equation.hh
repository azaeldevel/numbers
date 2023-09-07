#ifndef OCTETOS_NUMBERS_EQUATION_HH
#define OCTETOS_NUMBERS_EQUATION_HH

#include "common.hh"

namespace oct::nums::v0
{


    /**
    *\brief Representa una equacion con todos los termino no constantes en el lado izq
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param G El grado de la ecuacion
    *\param V Tipo de datos usado para calculos
    **/
    template<typename T,size_t L,size_t G,core::number V> class equation : public core::array<T,L>
    {
    private:
        typedef core::array<T,L> BASE;
    protected:
        T _c_;

    public:
        equation() = default;
        constexpr equation(const std::initializer_list<T>& l,const T& c) : BASE(l),_c_(c)
        {
        }
        constexpr equation(const std::initializer_list<T>& l) : BASE(l),_c_(0)
        {
        }
        constexpr equation(const BASE& s,const T& c) : BASE(s),_c_(c)
        {
        }
        constexpr equation(const BASE& s) : BASE(s),_c_(0)
        {
        }

        constexpr equation& operator = (const T& c)
        {
            _c_ = c;

            return *this;
        }
        constexpr equation& operator = (const equation& e)
        {
            ((BASE*)this)->operator =((const BASE&)e);
            _c_ = e._c_;

            return *this;
        }


        constexpr T& c()
        {
            return _c_;
        }
        constexpr const T& c() const
        {
            return _c_;
        }
        constexpr T& a(size_t i)
        {
            if(i < L) return BASE::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
        constexpr const T& a(size_t i) const
        {
            if(i < L) return BASE::data[i];

            throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        }
    };




    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param G Grado de la ecuacion
    *\param V Tipo de datos usado para calculos
    *\param i variable que sera resuelta
    **/
    template<typename T,core::natural L,core::natural G,core::number V> V resolve();


    template<core::number T,core::number V> V resolve(const equation<T,1,1,V>& eq)
    {
        return V(eq.c())/V(eq[0]);
    }
    template<core::number T,core::number V> V resolve(const equation<T,2,1,V>& eq, size_t index, const T& v)
    {
        if(index == 0) return (eq.c() - (eq[1] * v)) / V(eq[0]);
        else if(index == 1) return V(eq.c() - (eq[0] * v)) / V(eq[1]);

        throw core_here::exception("La cantidad de datos execede la capacidad del objeto");
        return 0;
    }

    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param V Tipo de datos usado para calculos
    **/
    template<core::number T,size_t L,core::number V> V clearance(const equation<T,L,1,V>& eq, size_t index)
    {


        return 0;
    }

    /**
    *\brief Resuelve un ecuacion
    *\param T Tipo de dato
    *\param L La cantidad de variables
    *\param V Tipo de datos usado para calculos
    **/
    template<core::number T,size_t L,core::number V> V resolve(const equation<T,L,1,V>* eqs, size_t leng)
    {
        std::cout << "Resolviendo ecuacion de " << L << "º\n";

        return 0;
    }


}

#endif // OCTETOS_NUMBERS_MATH_HH
