#ifndef CONFIG_H
#define	CONFIG_H


#include <xc.h> // include processor files - each processor file is guarded.
#include"globalDefinitions.h"

void configPIC();
void wait_5seg();
void wait_ms(unsigned int);
#endif	

