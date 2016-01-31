#include <stdio.h>
#include <stdlib.h>
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"
#include "Backtrack.h"

int main()
{
		Formula *f = (Formula *)malloc(sizeof(Formula));
        importDimacs("cnf.txt" , f);

        printf("<<%d>>",backtrack(*f));
        for (int i=0; i<f->nbClauses; i++)
            printf("<%d>", f->clauseFreeVars[i]);
    return 0;
}
