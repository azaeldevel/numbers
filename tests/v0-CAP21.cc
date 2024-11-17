
#if defined(__linux__)

#elif defined(_WIN32) || defined(_WIN64)

#else
	#error "Plataforma desconocida"
#endif




#include "v0.hh"
#include <numbers/0/vector.hh>


namespace oct::nums::v0::elec
{
    namespace core = oct::core::v3;
    static float epsilon = 8.854e-12;//SI
    static float electron = 1.60217653e-19;//SI


    /**
    *\brief Ley de Coulomnb
    *\param q1 carga
    *\param q2 carga
    *\param r distance
    *\param e constante de permimeatvidad relativa
    */
    template<core::number T>
    T coulomb_force(T q1,T q2, T r, T e = epsilon)
    {
        T v1 = q1* q2;
        T v2 = v1/std::pow(r,T(2));
        return (T(1) / (4 * std::numbers::pi * epsilon)) * v2;
    }
}

namespace numbers = oct::nums::v0;


void v0_FIUNSEZEKYI12_CAP21()
{
    //FIUNSEZEKYI12 - Ejempl0 21.1

}


