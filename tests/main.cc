
#include <cstring>
#include <string>
#include <iomanip>

#ifdef OCTETOS_NUMBERS_V0_TTD
	#include "v0.hh"
#endif


int main(int argc, char *argv[])
{
    std::string mode;
    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], "--mode") == 0)
        {
            mode = argv[++i];
        }
    }

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

#ifdef OCTETOS_NUMBERS_V0_TTD
	CU_pSuite pSuite_v0 = CU_add_suite("Testing for Numbers v0", v0_init, v0_clean);
	if (NULL == pSuite_v0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Developing..", v0_developing)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "sequence..", v0_sequence)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Vector..", v0_vector)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Equation..", v0_equation)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Matrix..", v0_matrix)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Aritmetica..", v0_arithmetic)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Algebra..", v0_algebra)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Formas geometricas..", v0_shapes)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_v0, "Funciones..", v0_funtions)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	std::setprecision(6);

	CU_pSuite FIUNSEZEKYI12_v0 = CU_add_suite("Testing for FIUNSEZEKYI12..", v0_FIUNSEZEKYI12_init, v0_FIUNSEZEKYI12_clean);
	if (NULL == FIUNSEZEKYI12_v0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(FIUNSEZEKYI12_v0, "Cinemticb..", v0_FIUNSEZEKYI12_CINEMATIC)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(FIUNSEZEKYI12_v0, "Dinamic..", v0_FIUNSEZEKYI12_DINAMIC)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(FIUNSEZEKYI12_v0, "Trabajo y Energia Cinetica..", v0_FIUNSEZEKYI12_WE)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(FIUNSEZEKYI12_v0, "Rotacion de Cuerpos Rigidos..", v0_FIUNSEZEKYI12_RCR)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(FIUNSEZEKYI12_v0, "Dinamica del Movimiento de Rotacion..", v0_FIUNSEZEKYI12_DMR)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}


	CU_pSuite FIUNSEZEKYII12_v0 = CU_add_suite("Testing for FIUNSEZEKYI12..", v0_FIUNSEZEKYI12_init, v0_FIUNSEZEKYI12_clean);
	if (NULL == FIUNSEZEKYI12_v0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(FIUNSEZEKYII12_v0, "Carga Electrica y Campo Magnetico", v0_FIUNSEZEKYII12_CAP21)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(FIUNSEZEKYII12_v0, "Ley de Gauss..", v0_FIUNSEZEKYII12_CAP22)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(FIUNSEZEKYII12_v0, "Potencial Electrico..", v0_FIUNSEZEKYII12_CAP23)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(FIUNSEZEKYII12_v0, "Capacitacia y Dielectricos..", v0_FIUNSEZEKYII12_CAP24)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

#endif

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

