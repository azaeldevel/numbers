#ifndef PHYCIS_HH_INCLUDED
#define PHYCIS_HH_INCLUDED

namespace oct::nums::v0::phys
{


    /**
    *\brief Ley de Coulomnb
    *\param q1 carga
    *\param q2 carga
    *\param r distance
    *\param e constante de permimeatvidad relativa
    */
    template<core::number T>
    T coulomb(T q1,T q2, T r, T e = T(8.854e-12))
    {
        T v1 = q1* q2;
        T v2 = -v1/std::pow(r,T(2));//siguiendo el combenio de sig no negitvo para fuerza repulsiva
        return (T(1) / (4 * std::numbers::pi * e)) * v2;
    }

    template<core::number T>
    T coulomb_field(T q, T r, T e = T(8.854e-12))
    {
        T v2 = -q/std::pow(r,T(2));//siguiendo el combenio de sig no negitvo para fuerza repulsiva
        return (T(1) / (4 * std::numbers::pi * e)) * v2;
    }
}

#endif // PHYCIS_HH_INCLUDED
