#include <stdio.h>
#include <stdlib.h>
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"

int main()
{


	    printf("hello");
		Formula *f = (Formula *)malloc(sizeof(Formula));
		printf("hello");
		importDimacs("cnf.txt" , f);
		printf("hello");
		printDimacs(*f);
		printf("hello");



    return 0;
}
