#include <stdio.h>
#include <stdlib.h>
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"

int main()
{


		Formula *f = (Formula *)malloc(sizeof(Formula));
		generateFullRandomFormula(f , 20 , 20);
		printDimacs(*f);


    return 0;
}
