#include "Backtrack.h"

// This is a special function to check the sat when changing a literal in an interpretation
/*int formulaStatus(Formula f, Interpretation I, Literal l, vecInt *vec)
{
    for (i=0;i<f.nbClauses;i++)
	{
	    if (()&&(f.clauseStatus[i]==TRUE)) continue;
	}
}*/

int backtrackR(Formula F, Interpretation I, int i)
{
    if (i>=F.nbVariables) return FALSE;
    assignVariable(I, i, FALSE);
    int status=statusFormula(F, I);
    if (status==UNDEF) status=backtrackR(F, I, i+1);
    if (status==TRUE) return status;
    // Status = false << conflict
    assignVariable(I, i, TRUE);
    status=statusFormula(F, I);
    if (status==UNDEF) status=backtrackR(F, I, i+1);
    if (status==TRUE) return status;
    // Conflict
    assignVariable(I, i, UNDEF);
    return FALSE;

}

int backtrack(Formula F)
{
    Interpretation I;
    createAndInitializeInterpretation(&I, F.nbVariables);
    int status = backtrackR(F, I, 1);
    display(I);
    return status;
}
