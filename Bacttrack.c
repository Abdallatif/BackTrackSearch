#include "Backtrack.h"

void checkClause(Formula f, Clause c, Interpretation I, int clauseIndex)
{
    int i;
    int flag = FALSE;
    for (i=0;i<c.size;i++)
        if(getValueLiteral(I,c.datas[i])==TRUE)
            flag=TRUE;
        else if(getValueLiteral(I,c.datas[i])==UNDEF)
            if (flag!=TRUE) flag = UNDEF;
    f.clauseStatus[clauseIndex]=flag;
}

// This is a special function to check the sat when changing a literal in an interpretation
int formulaStatus(Formula f, Interpretation I, Variable v)
{
    int siz=f.occ[getIndexLiteral(v)].size;
    int index=getIndexLiteral(v);
    for (int i=0; i<siz; i++) {
        int clauseIndex = f.occ[index].datas[i];
        checkClause(f,f.clauses[clauseIndex], I, clauseIndex);
    }
    siz=f.occ[getIndexLiteral(-v)].size;
    index=getIndexLiteral(-v);
    for (int i=0; i<siz; i++) {
        int clauseIndex = f.occ[index].datas[i];
        checkClause(f,f.clauses[clauseIndex], I, clauseIndex);
    }
    int status=TRUE;
    for (int i=0; i<f.nbClauses; i++) {
        if (f.clauseStatus[i]==FALSE)
            return FALSE;
        if (f.clauseStatus[i]==UNDEF)
            status=f.clauseStatus[i];
    }
    printf("\n");

    return status;
}

int backtrackR(Formula F, Interpretation I, int i)
{
    if (i>=F.nbVariables) return FALSE;
    assignVariable(I, i, FALSE);
    int status=formulaStatus(F, I, i);
    if (status==UNDEF) status=backtrackR(F, I, i+1);
    if (status==TRUE) return status;
    // Status = false << conflict
    assignVariable(I, i, TRUE);
    status=formulaStatus(F, I, i);
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
