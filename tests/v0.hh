

#ifndef OCTETOS_NUMBERS_V0_HH
#define OCTETOS_NUMBERS_V0_HH

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#define infimium 0.0001
#define CU_ASSERT_DECIMAL(V,R,I) CU_ASSERT(abs(V - R) < infimium)

int v0_init(void);
int v0_clean(void);

void v0_developing();
void v0_matrix();
void v0_equation();
void v0_sequence();
void v0_vector();
void v0_funtions();
void v0_arithmetic();
void v0_algebra();
void v0_shapes();


int v0_FIUNSEZEKYI12_init(void);
int v0_FIUNSEZEKYI12_clean(void);
void v0_FIUNSEZEKYI12_CINEMATIC();
void v0_FIUNSEZEKYI12_DINAMIC();
void v0_FIUNSEZEKYI12_CAP21();
void v0_FIUNSEZEKYI12_WE();


#endif
