
#if defined(__linux__)

#elif defined(_WIN32) || defined(_WIN64)

#else
	#error "Plataforma desconocida"
#endif




#include "v0.hh"
#include <numbers/0/vector.hh>


namespace oct::nums::v0::phys
{
    namespace core = oct::core::v3;
    //static float permitivity = 8.854e-12;//SI
    //static float electron = 1.60217653e-19;//SI


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


    /*template<core::number T,core::index auto L = 3>
    numbers::vector<T,L> coulomb(T q1,T x1,T y1,T q2, T x2, T y2, T e = T(8.854e-12))
    {
        T r = core::distance(x2-x1,y2-y1);
        numbers::vector<T,L> r(x2-x1,y2-y1);
        r = r.unit();
        T v1 = q1* q2;
        T v2 = -v1/std::pow(r.length(),T(2));//siguiendo el combenio de sig no negitvo para fuerza repulsiva
        return (T(1) / (4 * std::numbers::pi * e)) * v2;
    }*/
}

namespace numbers = oct::nums::v0;


void v0_FIUNSEZEKYII12_CAP21()
{
    float eje_21_1_qa = 2.f * 1.60217653e-19f; //eje_21_1_qa
    //std::cout << "q = " << eje_21_1_qa <<"\n";
    float eje_21_1_F = (std::pow(eje_21_1_qa,2.f))/(4 * std::numbers::pi * 8.854e-12f * 6.67e-11f * 6.64e-27);
    //std::cout << "F = " << eje_21_1_F <<"?\n";

    float eje_21_2_Fa = numbers::phys::coulomb(25.0e-9f,-75e-9f,0.03f);
    //std::cout << "Ejemplo 21.2 F = " << eje_21_2_Fa <<"N\n";
    CU_ASSERT(numbers::core::equal(eje_21_2_Fa,0.0187245f))


    float eje_21_3_F13 = numbers::phys::coulomb(1.0e-9f,5e-9f,0.02f);
    //std::cout << "Ejemplo 21.3 F = " << eje_21_3_F13 <<"N\n";
    CU_ASSERT(numbers::core::equal(eje_21_3_F13,-1.12e-4f,1.0e-6f))
    float eje_21_3_F23 = numbers::phys::coulomb(-3.0e-9f,5e-9f,0.04f);
    //std::cout << "Ejemplo 21.3 F = " << eje_21_3_F23 <<"N\n";
    CU_ASSERT(numbers::core::equal(eje_21_3_F23,8.4e-5f,1.0e-5f))

    float eje_21_4_d1 = numbers::core::distance(0.3f,0.4f);
    //std::cout << "Ejemplo 21.3 D1 = " << eje_21_4_d1 <<"N\n";
    float eje_21_4_f1 = numbers::phys::coulomb(2.0e-6f,4e-6f,eje_21_4_d1);
    //std::cout << "Ejemplo 21.3 F1 = " << eje_21_4_f1 <<"N\n";
    CU_ASSERT(numbers::core::equal(eje_21_4_f1,-0.28f,1.0e-2f))


    float eje_21_5_E = numbers::phys::coulomb_field(4.0e-9f,2.f);
    //std::cout << "Ejemplo 21.5 E = " << eje_21_5_E <<"N\n";
    CU_ASSERT(numbers::core::equal(eje_21_5_E,-8.98774f,1.0e-5f))


    numbers::vector<float> eje_21_6_r(1.2f,-1.6f);
    //std::cout << "Ejemplo 21.6 r = " << eje_21_6_r.length() <<"m\n";
    float eje_21_6_E = numbers::phys::coulomb_field(-8.0e-9f,eje_21_6_r.length());
    numbers::vector<float> eje_21_6_Ev;
    eje_21_6_Ev.create(eje_21_6_E,eje_21_6_r);//10.7853,-14.3804
    //eje_21_6_Ev.print(std::cout);
    CU_ASSERT(numbers::core::equal(eje_21_6_Ev.x(),10.7853f,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_21_6_Ev.y(),-14.3804f,1.0e-4f))


    float eje_21_7_ay = (-1.6e-19f * 1.0e4f)/9.11e-31f;
    //std::cout << "Ejemplo 21.7  F = " << eje_21_7_ay <<"N\n";//
    CU_ASSERT(numbers::core::equal(eje_21_7_ay,-1.76e15f,1.0e13f))//-1.75631e+15
    float eje_21_7_b_vy = 2.f * eje_21_7_ay * -1.0e-2f;
    eje_21_7_b_vy  = std::sqrt(eje_21_7_b_vy);
    //std::cout << "Ejemplo 21.7 v = " << eje_21_7_b_vy <<"m/s\n";//5.92674e+06
    CU_ASSERT(numbers::core::equal(eje_21_7_b_vy,5.9e6f,1.0e5f))//5.92674e+06
    float eje_21_7_b_K = 0.5f * 9.11e-31f * std::pow(eje_21_7_b_vy,2.f);
    //std::cout << "Ejemplo 21.7 k = " << eje_21_7_b_K <<"J\n";//5.92674e+06
    CU_ASSERT(numbers::core::equal(eje_21_7_b_K,1.6e-17f))
    float eje_21_7_b_t = eje_21_7_b_vy / eje_21_7_ay;
    //std::cout << "Ejemplo 21.7 t = " << eje_21_7_b_t <<"s\n";
    CU_ASSERT(numbers::core::equal(eje_21_7_b_t,3.4e-9f))

    float eje_21_14_b_p = 1.6e-19 * 0.125e-9;
    //std::cout << "Ejemplo 21.7 p = " << eje_21_14_b_p <<"\n";
    CU_ASSERT(numbers::core::equal(eje_21_14_b_p,2.0e-29f))
    float eje_21_14_c_t = eje_21_14_b_p * 5.0e5f * std::sin(numbers::core::degree_to_radian(35));
    //std::cout << "Ejemplo 21.7 p = " << eje_21_14_c_t <<"\n";
    CU_ASSERT(numbers::core::equal(eje_21_14_c_t,5.7e-24f))

    float eje_21_14_d_w = -eje_21_14_b_p * 5.0e5f * std::cos(numbers::core::degree_to_radian(145));
    //std::cout << "Ejemplo 21.7 p = " << eje_21_14_d_w <<"J\n";
    //CU_ASSERT(numbers::core::equal(eje_21_14_d_w,8.4e-24f))
}


void v0_FIUNSEZEKYII12_CAP22()
{
    float eje_22_a_fi = 2.0e3f * (std::numbers::pi * std::pow(0.1f,2.f)) * std::cos(numbers::core::degree_to_radian(30.f));
    //std::cout << "Ejemplo 22.1 flujo = " << eje_22_a_fi <<"\n";
    CU_ASSERT(numbers::core::equal(eje_22_a_fi,54.414f,1.0e-3f))

    float eje_22_a_fi90 = 2.0e3f * (std::numbers::pi * std::pow(0.1f,2.f)) * std::cos(numbers::core::degree_to_radian(90.f));
    //std::cout << "Ejemplo 22.1 flujo = " << eje_22_a_fi90 <<"\n";
    CU_ASSERT(numbers::core::equal(eje_22_a_fi90,0.0f,1.0e-4f))
    float eje_22_a_fi0 = 2.0e3f * (std::numbers::pi * std::pow(0.1f,2.f)) * std::cos(numbers::core::degree_to_radian(0.f));
    //std::cout << "Ejemplo 22.1 flujo = " << eje_22_a_fi0 <<"\n";
    CU_ASSERT(numbers::core::equal(eje_22_a_fi0,62.8319f,1.0e-4f))

    float eje_22_a_E = numbers::phys::coulomb_field(3.0e-6f,0.2f);
    //std::cout << "Ejemplo 22.3 flujo = " << eje_22_a_E <<"\n";
    CU_ASSERT(numbers::core::equal(eje_22_a_E,-674081.f,1.0f))
    float eje_22_3_a_fi = eje_22_a_E  * 4.f * std::numbers::pi * std::pow(0.2f,2.f);
    //std::cout << "Ejemplo 22.3 flujo = " << eje_22_3_a_fi <<"\n";
    CU_ASSERT(numbers::core::equal(eje_22_3_a_fi,-338830.f,1.0f))


}

void v0_FIUNSEZEKYII12_CAP23()
{
    float eje_23_3_F =  1.602e-19f * 1.5e7f;
    //std::cout << "Ejemplo 22.3 F " << eje_23_3_F <<"\Nn";
    CU_ASSERT(numbers::core::equal(eje_23_3_F,2.4e-12f,1.0e-13f))
    float eje_23_3_W = eje_23_3_F * 0.5f;
    //std::cout << "Ejemplo 22.3 W " << eje_23_3_W <<"J\n";
    CU_ASSERT(numbers::core::equal(eje_23_3_W,1.2e-12f,1.0e-13f))
    float eje_23_3_eV = eje_23_3_W / 1.602e-19f;
    //std::cout << "Ejemplo 22.3 W " << eje_23_3_eV <<"eV\n";
    CU_ASSERT(numbers::core::equal(eje_23_3_eV,7.5e6f,1.0e5f))

}


void v0_FIUNSEZEKYII12_CAP24()
{
    float eje_24_1_a = (1.0f * 1.0e-3f)/(8.85e-12f);
    //std::cout << "Ejemplo 24.1 A = " << eje_24_1_a <<"\n";
    CU_ASSERT(numbers::core::equal(eje_24_1_a,1.1e8f,1.0e9f))

    float eje_24_2_a_C = (8.85e-12f * 2.f)/5.0e-3;
    //std::cout << "Ejemplo 24.1 C = " << eje_24_2_a_C <<"\n";
    CU_ASSERT(numbers::core::equal(eje_24_2_a_C,3.54e-9f,1.0e-10f))
    float eje_24_2_b = eje_24_2_a_C * 1.0e4;
    //std::cout << "Ejemplo 24.1 Q = " << eje_24_2_b <<"\n";
    CU_ASSERT(numbers::core::equal(eje_24_2_b,3.54e-5f,1.0e-6f))
    float eje_24_2_c = eje_24_2_b/(8.85e-12f * 2.f);
    //std::cout << "Ejemplo 24.1 Q = " << eje_24_2_c <<"\n";
    CU_ASSERT(numbers::core::equal(eje_24_2_c,2.0e6f,1.0e5f))
}
