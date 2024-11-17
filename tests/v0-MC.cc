
#if defined(__linux__)

#elif defined(_WIN32) || defined(_WIN64)

#else
	#error "Plataforma desconocida"
#endif




#include "v0.hh"
#include <numbers/0/vector.hh>


namespace oct::nums::v0::mc
{
    namespace core = oct::core::v3;

    /**
    *\brief Relaciones
    */
    template<core::number T>
    struct Relation
    {
    };

    /**
    *\brief Relacion Tiempo-Posicion
    */
    template<core::number T>
    struct TP //: public Relation<T>
    {
        T time;
        T position;

        T velocity(const TP<T>& d2)
        {
            return (d2.position - position)/(d2.time - time);
        }

    };

    /**
    *\brief Relacion Tiempo-Velocidad
    */
    template<core::number T>
    struct TV //: public Relation<T>
    {
        T time;
        T velocity;

        T acceleration(const TV<T>& d2)
        {
            return (d2.velocity - velocity)/(d2.time - time);
        }
    };


    /**
    *\brief RMovimiento de acelercion constante
    */
    template<core::number T>
    struct MAC
    {
        T p0,v0,t,a,p;

        T position(T p0,T v0, T t, T a)
        {
            this->p0 = p0;
            this->v0 = v0;
            this->t = t;
            this->a = a;
            this->p = (p0 + (v0 * t) + ((a*std::pow(t,T(2))/2.f)));
            return this->p;
        }
    };


    //velocidad
    template<core::number T,core::index auto L = 3>
    constexpr T velocity(const vector<T,L>& p1, T t1,const vector<T,L>& p2, T t2)
    {
        T d = p2.distance(p1);
        T t = t2 - t1;
        return d/t;
    }
    template<core::number T,core::index auto L = 3>
    constexpr T velocity(const T dx, const T dt)
    {
        return dx/dt;
    }
    /**
    *\brief Velocidad Media
    */
    template<core::number T,core::index auto L = 3>
    constexpr T velocity(const TP<T>* data, size_t s)
    {
        T dm = 0, tm = 0;
        for(size_t i = 1; i <  s; i++)
        {
            dm += data[i].posistion - data[i - 1].posistion;
            tm += data[i].time - data[i - 1].time;
        }
        dm /= T(s);
        tm /= T(s);
        return dm/tm;
    }
    template<core::number T>
    constexpr T velocity(const TP<T>& d1, T t1,const TP<T>& d2)
    {
        return d1.velocity(d2);
    }


    template<core::number T>
    constexpr T velocity(T (*movil)(const T),const T t1,const T t2)
    {
        T p1 = movil(t1);
        T p2 = movil(t2);
        return (p2-p1)/(t2-t1);
    }
    template<core::number T>
    constexpr T displacement(T (*movil)(const T),const T t1,const T t2)
    {
        T p1 = movil(t1);
        T p2 = movil(t2);
        return (p2-p1);
    }
    template<core::number T>
    constexpr T position(T v, T t)
    {
        return (v*t);
    }
    template<core::number T>
    constexpr T position(T p0, T v, T t)
    {
        return p0 + (v*t);
    }





    //aceleracion
    template<core::number T,core::index auto L = 3>
    constexpr T acceleration(const T v1, T t1,const T v2, T t2)
    {
        T v = v2 - v1;
        T t = t2 - t1;
        return v/t;
    }
    template<core::number T>
    constexpr T acceleration(T (*velocity)(const T),const T t1,const T t2)
    {
        T v1 = velocity(t1);
        T v2 = velocity(t2);
        return (v2 - v1)/(t2-t1);
    }
    template<core::number T>
    constexpr T acceleration(const TV<T>& d1,const TV<T>& d2)
    {
        return d1.acceleration(d2);
    }

    /**
    *\brief Aumneto de velocidad en el tiempo t
    *\param v0 Velocidad inicial
    *\param a acelaracion
    *\param t tiempo
    */
    template<core::number T>
    constexpr T velocity(T v0, T a, T t)
    {
        return v0 + ( a * t);
    }
    /**
    *\brief Optiene la posicion de un movil acelerado
    *\param p0 Posicion inicial
    *\param v0 Velocidad inicial
    *\param a acelaracion
    *\param t tiempo
    */
    template<core::number T>
    constexpr T position(T p0, T v0, T a, T t)
    {
        return p0 + (v0 * t) + ((a * std::pow(t,T(2))) / T(2));
    }

    /**
    *\brief Optiene la posicion de un movil acelerado
    *\param p0 Posicion inicial
    *\param v0 Velocidad inicial
    *\param a acelaracion
    *\param t tiempo
    */
    template<core::number T>
    constexpr T position2(T p0, T v0, T v, T a)
    {
        return p0 + (std::pow(v,T(2)) - std::pow(v0,T(2)))/(T(2) * a);
    }

}

namespace numbers = oct::nums::v0;








typedef float (*movil)(const float);
typedef float (*velocity)(const float);
void v0_FIUNSEZEKYI12_MC()
{
    //FIUNSEZEKYI12 : Pag 40,Ejemplo 2.1
    movil movil_eje_2_1 = [](const float t) -> float
    {
        return 20.f + (5.f * t * t);
    };
    float movil_eje_2_1_v1 = numbers::mc::velocity(movil_eje_2_1,1.f,2.f);
    float movil_eje_2_1_d1 = numbers::mc::displacement(movil_eje_2_1,1.f,2.f);
    CU_ASSERT(numbers::core::equal(movil_eje_2_1_v1,15.f));
    CU_ASSERT(numbers::core::equal(movil_eje_2_1_d1,15.f));
    //std::cout << "Ejemplo 2.1 : Velocidad : " << movil_eje_2_1_v1 << "\n";
    //std::cout << "Ejemplo 2.1 : Desplazamiento : " << movil_eje_2_1_d1 << "\n";
    movil movil_eje_2_1_inst = [](const float t) -> float
    {
        return (10 * t);
    };
    float movil_eje_2_1_inst_v1 = movil_eje_2_1_inst(1.f);
    float movil_eje_2_1_inst_v2 = movil_eje_2_1_inst(2.f);
    //std::cout << "Ejemplo 2.1 : Velocidad inetantanea 1: " << movil_eje_2_1_inst_v1 << "\n";
    //std::cout << "Ejemplo 2.1 : Velocidad inetantanea 2: " << movil_eje_2_1_inst_v2 << "\n";
    CU_ASSERT(numbers::core::equal(movil_eje_2_1_inst_v1,10.f));
    CU_ASSERT(numbers::core::equal(movil_eje_2_1_inst_v2,20.f));

    CU_ASSERT(numbers::core::equal(numbers::mc::acceleration(0.8f,1.f,1.2f,3.f),0.2f))
    CU_ASSERT(numbers::core::equal(numbers::mc::acceleration(1.2f,3.f,1.6f,5.f),-0.2f))

    velocity velocity_eje_2_3 = [](const float t) -> float
    {
        return 60.f + (0.5f * t * t);
    };
    //std::cout << "Ejemplo 2.3 : V1  : " << velocity_eje_2_3(1.f) << "\n";
    //std::cout << "Ejemplo 2.3 : V2  : " << velocity_eje_2_3(3.f) << "\n";
    float movil_eje_2_3_a1 = numbers::mc::acceleration(velocity_eje_2_3,1.f,3.f);
    //std::cout << "Ejemplo 2.3 : Acelaraion  : " << movil_eje_2_3_a1 << "\n";
    CU_ASSERT(numbers::core::equal(velocity_eje_2_3(1.f),60.5f))
    CU_ASSERT(numbers::core::equal(velocity_eje_2_3(3.f),64.5f))
    CU_ASSERT(numbers::core::equal(movil_eje_2_3_a1,2.f))

    numbers::mc::TV<float> movil_eje_2_2_a2[8];
    movil_eje_2_2_a2[0].time = 1.0;
    movil_eje_2_2_a2[0].velocity = 0.8;
    movil_eje_2_2_a2[1].time = 3.0;
    movil_eje_2_2_a2[1].velocity = 1.2;
    movil_eje_2_2_a2[2].time = 5.0;
    movil_eje_2_2_a2[2].velocity = 1.6;
    movil_eje_2_2_a2[3].time = 7.0;
    movil_eje_2_2_a2[3].velocity = 1.2;
    movil_eje_2_2_a2[4].time = 9.0;
    movil_eje_2_2_a2[4].velocity = -0.4;
    movil_eje_2_2_a2[5].time = 11.0;
    movil_eje_2_2_a2[5].velocity = -1.0;
    movil_eje_2_2_a2[6].time = 13.0;
    movil_eje_2_2_a2[6].velocity = -1.6;
    movil_eje_2_2_a2[7].time = 15.0;
    movil_eje_2_2_a2[7].velocity = -0.8;
    float movil_eje_2_2_a3 = movil_eje_2_2_a2[0].acceleration(movil_eje_2_2_a2[1]);
    float movil_eje_2_2_a4 = movil_eje_2_2_a2[2].acceleration(movil_eje_2_2_a2[3]);
    float movil_eje_2_2_a5 = movil_eje_2_2_a2[5].acceleration(movil_eje_2_2_a2[5]);
    float movil_eje_2_2_a6 = movil_eje_2_2_a2[6].acceleration(movil_eje_2_2_a2[7]);
    //std::cout << "Ejemplo 2.2 : Acelaraion  : " << movil_eje_2_2_a3 << "\n";
    //std::cout << "Ejemplo 2.2 : Acelaraion  : " << movil_eje_2_2_a4 << "\n";
    //std::cout << "Ejemplo 2.2 : Acelaraion  : " << movil_eje_2_2_a5 << "\n";
    CU_ASSERT(numbers::core::equal(movil_eje_2_2_a3,0.2f))
    CU_ASSERT(numbers::core::equal(movil_eje_2_2_a4,-0.2f))
    CU_ASSERT(numbers::core::equal(movil_eje_2_2_a5,-0.3f))
    CU_ASSERT(numbers::core::equal(movil_eje_2_2_a6,0.4f))



    //Ejemplo 2.4
    //a)
    float eje_2_4_a1 = numbers::mc::position(5.f, 15.f,4.f,2.f);
    //std::cout << "Ejemplo 2.4 : a) " << eje_2_4_a1 << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_4_a1,43.f))
    float eje_2_4_a2 = numbers::mc::velocity(15.f,4.f,2.f);
    //std::cout << "Ejemplo 2.4 : a) " << eje_2_4_a2 << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_4_a2,23.f))

    float eje_2_4_b = numbers::mc::position2(5.f,15.f,25.f,4.f);
    std::cout << "Ejemplo 2.4 : b) " << eje_2_4_b << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_4_b,55.f))
}


