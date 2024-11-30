
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

    namespace constans
    {
        static const float gravity = 9.81;
    }

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
    constexpr T velocity(const T p1, T t1,const T p2, T t2)
    {
        T d = p2 - p1;
        T t = t2 - t1;
        return d/t;
    }
    template<core::number T,core::index auto L = 3>
    constexpr vector<T,L> velocity(const vector<T,L>& p1, T t1,const vector<T,L>& p2, T t2)
    {
        auto d = p2 - p1;
        auto t = t2 - t1;
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
    template<core::number T,core::index auto L = 3>
    constexpr vector<T,L> acceleration(const vector<T,L>& v1, T t1,const vector<T,L>& v2, T t2)
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
    constexpr T position_from_velicities(T p0, T v0, T v, T a)
    {
        return p0 + (std::pow(v,T(2)) - std::pow(v0,T(2)))/(T(2) * a);
    }

    /**
    *\brief Tiempo de interseccion de de dos moviles (m1 velocidad constrante) movil 2 (aceleracion constante)
    *\param v velocidad del movil 1
    *\param a aceleracion del movil 2
    */
    template<core::number T>
    constexpr T intersecction(T v, T a)
    {
        return T(2) * (v/a);
    }

    template<core::number T>
    constexpr T distance(const T& x, const T& y)
    {
        return std::sqrt(std::pow(x,T(2)) + std::pow(y,T(2)));
    }

    /**
    *\brief Aumneto de velocidad en el tiempo t
    *\param v0 Velocidad inicial
    *\param a acelaracion
    *\param t tiempo
    */
    template<core::number T,core::index auto L = 3>
    constexpr vector<T,L> velocity(const vector<T,L>& v0, T t)
    {
        return v0 * t;
    }

    /**
    *\brief Aumneto de velocidad en el tiempo t
    *\param v0 Velocidad inicial
    *\param a acelaracion
    *\param t tiempo
    */
    template<core::number T,core::index auto L = 3>
    constexpr vector<T,L> velocity(const vector<T,L>& v0, const vector<T,L>& a, T t)
    {
        return v0 + ( a * t);
    }


    /**
    *\brief Veloz
    *\param T tipo de dato
    *\param L cantidad de coordenadas
    */
    template<core::number T,core::index auto L = 3>
    struct Fast
    {
    public:
        Fast() = default;
        Fast(const vector<T,L>& v) : velocity(v),vector<T,L>(0),time(0)
        {
        }
        Fast(const vector<T,L>& v,const vector<T,L>& p) : velocity(v),position(p),time(0)
        {
        }
        Fast(const vector<T,L>& v,const vector<T,L>& p,const T t) : velocity(v),position(p),time(t)
        {
        }

    public:
        void displace(const T time)
        {
            this->time += time;
            position += velocity * time;
        }

    public:
        vector<T,L> velocity;
        vector<T,L> position;
        T time;

    };


    /**
    *\brief Veloz
    *\param T tipo de dato
    *\param L cantidad de coordenadas
    */
    template<core::number T,core::index auto L = 3>
    struct Accelerated : public Fast<T,L>
    {
    public:
        typedef Fast<T,L> BASE;
    public:
        Accelerated() = default;
        Accelerated(const vector<T,L>& v0, const vector<T,L>& a) : BASE(vector<T,L>(0),vector<T,L>(0),0),velocity_initial(v0),acceleration(a)
        {
        }

        /**
        *\brief avanza el tiempo indicado
        */
        void displace(const T& time)
        {
            this->time = time;
            this->position.x() = this->velocity_initial.x() * time;
            this->position.y() = (this->velocity_initial.y() * time) + (this->acceleration.y() * std::pow(this->time,T(2)))/T(2);
        }
    public:
        vector<T,L> acceleration;
        vector<T,L> velocity_initial;
    };


    /**
    *\brief Prjectil (FIUN-SEZEKY-I-12 pag 80)
    *\param T tipo de dato
    *\param L cantidad de coordenadas
    */
    template<core::number T,core::index auto L = 3>
    struct Projectile : public Accelerated<T,L>
    {
    public:
        typedef Accelerated<T,L> BASE;
        typedef Accelerated<T,L> ACCELERATED;
        typedef Fast<T,L> FAST;
    public:

    public:
        Projectile() = default;
        Projectile(const vector<T,L>& v0, const vector<T,L>& a) : BASE(v0,a)
        {
        }

    public:
        void displace(const T time)
        {
            ACCELERATED::displace(time);
            //
            this->velocity.x() = this->velocity_initial.x();
            this->velocity.y() = this->velocity_initial.y() + (this->acceleration.y() * this->time);
        }
        /**
        *\brief tiempo en llegar a la cima
        */
        T time_top() const
        {
            return this->velocity_initial.y()/-this->acceleration.y();
        }
        /**
        *\brief altura de la cima
        */
        T high_top() const
        {
            return std::pow(this->velocity_initial.y(),T(2)) / (T(2) * -this->acceleration.y());
        }
        /**
        *\brief punto de caida
        */
        T time_fall() const
        {
            return (T(2) * this->velocity_initial.y()) / -this->acceleration.y();
        }

        /**
        *\brief tiempo e caida(debajo de la horizontal)
        */
        core::array<T,L> time_desplace(T y) const
        {
            core::array<T,2> ret;
            T v = this->velocity_initial.length() * std::sin(this->velocity_initial.angle(false));
            T radical = std::pow(v,T(2)) - (T(2) * -this->acceleration.y() * y);
            radical = std::sqrt(std::abs(radical));
            T t1 = (v - radical)/(-this->acceleration.y());
            T t2 = (v + radical)/(-this->acceleration.y());
            ret[0] = t1;
            ret[1] = t2;
            return ret;
        }

    };


    //typedef float (*fC)(const float& t);
    //template<core::number T,core::index auto L = 3> T (*MF)(const T&);
    //template<core::number T,core::index auto L = 3> using T (*MF)(const T&);

    template<core::number T,core::index auto L = 3>
    struct Movil
    {
    public:


    public:
        Movil() = default;

        /**
        *\brief funciones personalizadas
        **/
        Movil(const T& v,T (*x)(const T& t),T (*y)(const T& t))
        {
        }

        /**
        *\brief velocidad constante, desplzandose sobre x
        **/
        Movil(const T& x,const T& v)
        {
        }

        /**
        *\brief aceleracion constante con velocidad inicial sobre x
        **/
        Movil(const T x0,const T& v0,const T& a) //: time(0),position(0)
        {
        }

        /**
        *\brief aceleracion constante
        **/
        Movil(const vector<T,L>& p,const vector<T,L>& v) : position(p),velocity(v)
        {
            /*funcs[0] = [this](const T& t) -> T
            {
                return position.x() + (velocity.x() * t);
            };*/
        }

        /**
        *\brief aceleracion constante
        **/
        Movil(const vector<T,L>& position,const vector<T,L>& velocity,const vector<T,L>& acceleration) //: time(0),position(0)
        {
        }

        vector<T,L> displace(const T& t)
        {
            vector<T,L> p;
            p.x() = funcs[0](t);
            p.y() = funcs[1](t);
            if constexpr ( L >= 3)
            {
                p.z() = funcs[2](t);
            }

            return p;
        }

    public:
        T (*funcs[L])(const T&);
        vector<T,L> position;
        vector<T,L> velocity;

    };


}

namespace numbers = oct::nums::v0;








typedef float (*movil)(const float);
typedef float (*velocity)(const float);
typedef float (*position)(const float);

void v0_FIUNSEZEKYI12_CINEMATIC()
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

    //pag 44
    float eje_2_2_a1 = numbers::mc::acceleration(0.8f,1.f,1.2f,3.f);
    float eje_2_2_a2 = numbers::mc::acceleration(1.6f,5.f,1.2f,7.f);
    //std::cout << "Ejemplo 2.2 : " << eje_2_2_a1 << "\n";
    //std::cout << "Ejemplo 2.2 : " << eje_2_2_a2 << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_2_a1,0.2f))
    CU_ASSERT(numbers::core::equal(eje_2_2_a2,-0.2f))

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

    float eje_2_4_b = numbers::mc::position_from_velicities(5.f,15.f,25.f,4.f);
    //std::cout << "Ejemplo 2.4 : b) " << eje_2_4_b << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_4_b,55.f))

    struct Ejemplo_2_4
    {
        float v0 = 15;
        float p0 = 5;
        float a = 4;

        float position(float t)
        {
            return numbers::mc::position(p0, v0,a,t);
        }
        float velocity(float t)
        {
            return numbers::mc::velocity(v0,a,t);
        }
        float position2(float v)
        {
            return numbers::mc::position_from_velicities(p0,v0,v,a);
        }
    };

    Ejemplo_2_4 eje_2_4;
    CU_ASSERT(numbers::core::equal(eje_2_4.position(2.f),43.f))
    CU_ASSERT(numbers::core::equal(eje_2_4.velocity(2),23.f))
    CU_ASSERT(numbers::core::equal(eje_2_4.position2(25),55.f))

    float eje_2_5_a = numbers::mc::intersecction(15.f,3.f);
    //std::cout << "Ejemplo 2.5 : a) " << eje_2_5_a << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_5_a,10.f))
    float eje_2_5_b = numbers::mc::velocity(0.f,3.f,10.f);
    //std::cout << "Ejemplo 2.5 : b) " << eje_2_5_b << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_5_b,30.f))
    float eje_2_5_c = numbers::mc::position(15.f,10.f);
    //std::cout << "Ejemplo 2.5 : c) " << eje_2_5_c << "\n";
    CU_ASSERT(numbers::core::equal(eje_2_5_c,150.f))


    //3
    position eje_3_1_fx = [](float t) -> float
    {
        return 2.f - (0.25f * std::pow(t,2.f));
    };
    position eje_3_1_fy = [](float t) -> float
    {
        return t + (0.025f * std::pow(t,3.f));
    };
    position eje_3_1_vx = [](float t) -> float
    {
        return -0.25f * 2.f * t;
    };
    position eje_3_1_vy = [](float t) -> float
    {
        return 1 + (0.025f * 3.f * std::pow(t,2.f));
    };
    position eje_3_1_ax = [](float t) -> float
    {
        return -0.5f;
    };
    position eje_3_1_ay = [](float t) -> float
    {
        return 0.075f * 2.f * t;
    };

    float eje_3_1_a_x_0 = eje_3_1_fx(0.f);
    float eje_3_1_a_y_0 = eje_3_1_fy(0.f);
    float eje_3_1_a_x_2 = eje_3_1_fx(2.f);
    float eje_3_1_a_y_2 = eje_3_1_fy(2.f);
    CU_ASSERT(numbers::core::equal(eje_3_1_a_x_2,1.f))
    //std::cout << "Ejemplo 3.1 : " << eje_3_1_a_x << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_1_a_y_2,2.2f))
    //std::cout << "Ejemplo 3.1 : " << eje_3_1_a_y << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_1_a_x_0,2.f))
    CU_ASSERT(numbers::core::equal(eje_3_1_a_y_0,0.f))

    numbers::vector<float,2> eje_3_1_a_r_0(eje_3_1_a_x_0,eje_3_1_a_y_0);
    numbers::vector<float,2> eje_3_1_a_r_2(eje_3_1_a_x_2,eje_3_1_a_y_2);
    numbers::vector<float,2> eje_3_1_a_r_delta = eje_3_1_a_r_2 - eje_3_1_a_r_0;
    //eje_3_1_a_r_delta.print(std::cout);
    bool eje_3_1_a_r_delta_v = eje_3_1_a_r_delta == numbers::vector<float,2>(-1.f,2.2f);
    CU_ASSERT(eje_3_1_a_r_delta_v)
    numbers::vector<float,2> eje_3_1_b_velocity = numbers::mc::velocity(eje_3_1_a_r_0,0.f,eje_3_1_a_r_2,2.f);
    bool eje_3_1_b_velocity_b = eje_3_1_b_velocity == numbers::vector<float,2>(-0.5f,1.1f);
    CU_ASSERT(eje_3_1_b_velocity_b)
    numbers::vector<float,2> eje_3_1_a_v_2(eje_3_1_vx(2),eje_3_1_vy(2));
    //eje_3_1_a_v_2.print(std::cout);
    bool eje_3_1_a_v_2_b = eje_3_1_a_v_2 == numbers::vector<float,2>(-1.f,1.3f);
    CU_ASSERT(eje_3_1_a_v_2_b)
    //std::cout << "Length : " << eje_3_1_a_v_2.length() << "\n";
    CU_ASSERT(1.6f - eje_3_1_a_v_2.length() < 1.0e-1f )
    //std::cout << "Tang : " << eje_3_1_a_v_2.tan() << "\n";

    float eje_3_2_a_vx_0 = eje_3_1_vx(0.f);
    float eje_3_2_a_vy_0 = eje_3_1_vy(0.f);
    float eje_3_2_a_vx_2 = eje_3_1_vx(2.f);
    float eje_3_2_a_vy_2 = eje_3_1_vy(2.f);
    float eje_3_2_a_ax_2 = eje_3_1_ax(2.f);
    float eje_3_2_a_ay_2 = eje_3_1_ay(2.f);
    CU_ASSERT(numbers::core::equal(eje_3_2_a_vx_0,0.f))
    CU_ASSERT(numbers::core::equal(eje_3_2_a_vy_0,1.f))
    CU_ASSERT(numbers::core::equal(eje_3_2_a_vx_2,-1.f))
    CU_ASSERT(numbers::core::equal(eje_3_2_a_ax_2,-0.5f))
    CU_ASSERT(numbers::core::equal(eje_3_2_a_ay_2,0.3f))
    numbers::vector<float,2> eje_3_2_a_a_2(eje_3_2_a_ax_2,eje_3_2_a_ay_2);
    CU_ASSERT(numbers::core::equal(eje_3_2_a_a_2.length(),0.58f,1.0e-2f))



    numbers::vector<float,2> eje_3_3_a_proyx = eje_3_2_a_a_2.proyection(eje_3_1_a_v_2);
    numbers::vector<float,2> eje_3_3_a_proyy = eje_3_2_a_a_2.proyection(eje_3_1_a_v_2.orthogonal());
    //eje_3_3_a_proyy.printLn(std::cout);
    //std::cout << "Ejemplo 3.3 : " << eje_3_3_a_proyx.length() << "\n";
    //std::cout << "Ejemplo 3.3 : " << eje_3_3_a_proyy.length() << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_3_a_proyx.length(),0.54f,1.0e-2f))
    CU_ASSERT(numbers::core::equal(eje_3_3_a_proyy.length(),0.21f,1.0e-2f))



    //proyectil
    //ejemplo 3.6
    float eje_3_6_position_x = numbers::mc::position(9.f,0.5f);
    //std::cout << "Ejemplo 3.6 : " << eje_3_6_position_x << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_6_position_x,4.5f))
    float eje_3_6_position_y = numbers::mc::position(0.f,0.f,-9.81f,0.5f);
    CU_ASSERT(numbers::core::equal(eje_3_6_position_y,-1.2f,1.0e-1f))
    //std::cout << "Ejemplo 3.6 y: " << eje_3_6_position_y << "\n";
    float eje_3_6_distance = numbers::mc::distance(eje_3_6_position_x,eje_3_6_position_y);
    //std::cout << "Ejemplo 3.6 distance: " << eje_3_6_distance << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_6_distance,4.66408f,1.0e-5f))
    float eje_3_6_velocity_y = -9.81f * 0.5f;//velocidad inicial es 0
    //std::cout << "Ejemplo 3.6 velocidad en y en t = 0.5s: " << eje_3_6_velocity_y << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_6_velocity_y,-4.905f))
    float eje_3_6_velocity_angle = eje_3_6_velocity_y/9.f;//velocidad inicial es 0
    eje_3_6_velocity_angle = std::atan(eje_3_6_velocity_angle);
    float eje_3_6_velocity_degree = eje_3_6_velocity_angle * (180.f/std::numbers::pi);
    CU_ASSERT(numbers::core::equal(eje_3_6_velocity_degree,-28.5904f,1.0e-4f))
    //std::cout << "Ejemplo 3.6 angul de vector velocidad : " << eje_3_6_velocity_angle << "\n";
    //std::cout << "Ejemplo 3.6 angul de vector velocidad : " << eje_3_6_velocity_degree << "\n";

    numbers::vector<float,2> eje_3_7_velocity;
    eje_3_7_velocity.create(37.f,53.1f,false);
    //eje_3_7_velocity.print(std::cout);
    bool eje_3_7_b = eje_3_7_velocity == numbers::vector<float,2>(22.2155f,29.5883f);

    float eje_3_7_posistion_x = eje_3_7_velocity.x() * 2.f;
    float eje_3_7_posistion_y = eje_3_7_velocity.y() * 2.f - (9.8*std::pow(2.f,float(2))/2.f);
    //std::cout << "Ejemplo 3.7 posicion : " << eje_3_7_posistion_x << "," << eje_3_7_posistion_y << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_posistion_x,44.4311f,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_7_posistion_y,39.5767f,1.0e-4f))
    float eje_3_7_velocity_x2 = eje_3_7_velocity.x();
    float eje_3_7_velocity_y2 = eje_3_7_velocity.y() - ( 2.f * 9.8);
    CU_ASSERT(numbers::core::equal(eje_3_7_velocity_x2,22.2155f,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_7_velocity_y2,9.98833f,1.0e-5f))
    //std::cout << "Ejemplo 3.7 velocity 2: " << eje_3_7_velocity_x2 << "," << eje_3_7_velocity_y2 << "\n";
    float eje_3_7_length = numbers::mc::distance(eje_3_7_velocity_x2,eje_3_7_velocity_y2);
    float eje_3_7_angle = eje_3_7_velocity_y2/eje_3_7_velocity_x2;
    eje_3_7_angle = std::sin(eje_3_7_angle) * (180.f/std::numbers::pi);
    //std::cout << "Ejemplo 3.7 angle : " << eje_3_7_angle << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_angle,24.9016f,1.0e-4f))
    float eje_3_7_time_in_top = eje_3_7_velocity.y()/9.8f;
    //std::cout << "Ejemplo 3.7 tiempo en la cima : " << eje_3_7_time_in_top << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_time_in_top,3.01922f,1.0e-4f))
    float eje_3_7_high = eje_3_7_velocity.y() * eje_3_7_time_in_top - (9.8 * std::pow(eje_3_7_time_in_top,float(2)))/2.f;
    //std::cout << "Ejemplo 3.7 altura en la cima : " << eje_3_7_high << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_high,44.6668f,1.0e-4f))
    float eje_3_7_time_2 = (2.f * eje_3_7_velocity.y())/9.8f;
    //std::cout << "Ejemplo 3.7 de caida : " << eje_3_7_time_2 << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_time_2,6.03843f,1.0e-4f))
    float eje_3_7_alcance = eje_3_7_velocity.y() * eje_3_7_time_2;
    //std::cout << "Ejemplo 3.7 alacance horizontal : " << eje_3_7_alcance << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_alcance,178.667f,1.0e-3f))

    numbers::mc::Projectile<float,2> eje_3_7_proy(eje_3_7_velocity,numbers::vector<float,2>(0,-9.8,0));
    //eje_3_7_proy.velocity_initial.create_from(37,53.1);
    //bool eje_3_7_proy_b = eje_3_7_proy.velocity_initial == numbers::vector<float>(22.2155f,29.5883f);
    //CU_ASSERT(eje_3_7_proy_b)
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity_initial.x(),22.2155f,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity_initial.y(),29.5883f,1.0e-4f))
    //eje_3_7_proy.velocity_initial.print(std::cout);
    eje_3_7_proy.displace(2);
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.position.x(),eje_3_7_posistion_x,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.position.y(),eje_3_7_posistion_y,1.0e-4f))
    //eje_3_7_proy.position.print(std::cout);
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity.x(),eje_3_7_velocity_x2,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity.y(),eje_3_7_velocity_y2,1.0e-5f))
    //eje_3_7_proy.velocity.print(std::cout);
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity.length(),eje_3_7_length))
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.velocity.angle(true),24.2092f,1.0e-4f))
    //std::cout << "Ejemplo 3.7 angle : " << eje_3_7_proy.velocity.angle(true) << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.time_top(),eje_3_7_time_in_top))
    //std::cout << "Ejemplo 3.7 cima : " << eje_3_7_proy.time_top() << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.high_top(),eje_3_7_high,1.0e-4f))
    //std::cout << "Ejemplo 3.7 cima : " << eje_3_7_proy.high_top() << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.time_fall(),eje_3_7_time_in_top * 2.f,1.0e-4f))
    //std::cout << "Ejemplo 3.7 cima : " << eje_3_7_proy.high_top() << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_7_proy.time_fall(),eje_3_7_time_in_top * 2.f,1.0e-4f))
    //std::cout << "Ejemplo 3.7 cima : " << eje_3_7_proy.high_top() << "\n";

    numbers::vector<float,2> eje_3_9_velocity;
    eje_3_9_velocity.create(10.f,-20.f,false);
    numbers::mc::Projectile<float,2> eje_3_9_proy(eje_3_9_velocity,numbers::vector<float,2>(0,-9.8,0));
    auto eje_3_9_times = eje_3_9_proy.time_desplace(-8);
    //std::cout << "Ejemplo 3.9 time : (" << eje_3_9_times[0] << "," << eje_3_9_times[1] << ")\n";
    CU_ASSERT(numbers::core::equal(eje_3_9_times[0],-1.67356f,1.0e-4f))
    CU_ASSERT(numbers::core::equal(eje_3_9_times[1],0.975558f,1.0e-4f))
    float eje_3_9_distance = eje_3_9_proy.velocity_initial.length() * std::sin(eje_3_9_proy.velocity_initial.angle()) * eje_3_9_times[1];
    CU_ASSERT(numbers::core::equal(eje_3_9_distance,-8.90631f,1.0e-4f))
    //std::cout << "Ejemplo 3.9 distansia : " << eje_3_9_distance << "\n";

    //Ejemplo 3.11
    float eje_3_11_r = std::pow(40.f,float(2))/9.4f;
    //std::cout << "Ejemplo 3.11 : " << eje_3_11_r << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_11_r,170.213f,1.0e-3f))


    //Ejemplo 3.2
    float eje_3_12_a1 = (4.f * std::pow(std::numbers::pi,2.f) * 5.f)/std::pow(4.f,2.f);
    //std::cout << "Ejemplo 3.12 : " << eje_3_12_a1 << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_12_a1,12.337f,1.0e-3f))

    //Ejemplo 3.14
    float eje_3_14_velocity = std::pow(240.f,2.f) + std::pow(100.f,2.f);
    eje_3_14_velocity = std::sqrt(eje_3_14_velocity);
    //std::cout << "Ejemplo 3.14 : " << eje_3_14_velocity << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_14_velocity,260.f))
    float eje_3_14_angle = std::atan(100.f/240.f);
    eje_3_14_angle = numbers::core::radian_to_degree(eje_3_14_angle);
    //std::cout << "Ejemplo 3.14 : " << eje_3_14_angle << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_14_angle,22.6199f,1.0e-4f))


    //Ejemplo 3.15
    float eje_3_15_velocity = std::pow(240.f,2.f) - std::pow(100.f,2.f);
    eje_3_15_velocity = std::sqrt(eje_3_15_velocity);
    //std::cout << "Ejemplo 3.15 : " << eje_3_15_velocity << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_15_velocity,218.174f,1.0e-3f))
    float eje_3_15_angle = std::asin(100.f/240.f);
    eje_3_15_angle = numbers::core::radian_to_degree(eje_3_15_angle);
    //std::cout << "Ejemplo 3.15 : " << eje_3_15_angle << "\n";
    CU_ASSERT(numbers::core::equal(eje_3_15_angle,24.6243f,1.0e-4f))
}


void v0_FIUNSEZEKYI12_DINAMIC()
{
    float eje_4_1_rx = -150 + 50;
    float eje_4_1_ry = 200 -120;
    CU_ASSERT(numbers::core::equal(eje_4_1_rx,-100.f))
    CU_ASSERT(numbers::core::equal(eje_4_1_ry,80.f))
    float eje_4_1_distance = numbers::core::distance(eje_4_1_rx,eje_4_1_ry);
    //std::cout << "Ejemplo 4.1 : " << eje_4_1_distance << "\n";//
    CU_ASSERT(numbers::core::equal(eje_4_1_distance,128.062f,1.0e-3f))
    float eje_4_1_tan = eje_4_1_ry/eje_4_1_rx;
    float eje_4_1_angle = std::atan(eje_4_1_tan);
    eje_4_1_angle = numbers::core::radian_to_degree(eje_4_1_angle);
    //std::cout << "Ejemplo 4.1 : " << eje_4_1_angle << "\n";
    CU_ASSERT(numbers::core::equal(eje_4_1_angle,-38.6598f,1.0e-4f))


}
