#include <stdio.h>
#include <stdlib.h>
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"

int main()
{


		Formula *f = (Formula *)malloc(sizeof(Formula));
		importDimacs("cnf.txt" , f);
		printDimacs(*f);



    return 0;
}
