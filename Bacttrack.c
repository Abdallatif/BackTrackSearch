#include "Backtrack.h"

stack s;

void checkClause(Formula f, Clause c, Interpretation I, int clauseIndex)
{
    int i;
    int flag = FALSE;
    for (i=0;i<c.size;i++)
        if(getValueLiteral(I,c.datas[i])==TRUE)
            flag=TRUE;
        else if(getValueLiteral(I,c.datas[i])==UNDEF)
            if (flag!=TRUE) flag = UNDEF;
    f.clauseStatus[clauseIndex]= flag ;
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

int chooseVar(Formula F, Interpretation I ){
    /* Find  the clause that have minmum free varible */
    int temp = 0, minfree = F.clauseFreeVars[0] , index=0 ;
    for (temp=0; temp< F.nbClauses ; temp++)
    {
        if ( F.clauseFreeVars[temp] < minfree && F.clauseFreeVars[temp] != 0 && F.clauseFreeVars[temp] != 1)
        {
            minfree=F.clauseFreeVars[temp];
            index=temp;
        }
    }
    /* Find the varible that is undef */
    for (int i=0; i<F.clauses[index].size; i++)
    {
        if (I.datas[getVariable(F.clauses[index].datas[i])] == UNDEF)
            return F.clauses[index].datas[i];
    }

    return 0 ;
}

/// this function try to propagate the variables on unit clauses
/// and if it found an empty clause it return false
int propagate(Formula f, Interpretation I, int dl) {
    for (int i=0; i<f.nbClauses; i++)
        if (F.clauseFreeVars[i]==0)
            return 0;
        else if (F.clauseFreeVars[i]==1)
            for (int j=0; j<F.clauses[i].size; j++)
                if (I.datas[getVariable(F.clauses[i].datas[j])] == UNDEF){
                    v=getVariable(F.clauses[i].datas[j]);
                    value=F.clauses[i].datas[j]*2-1;
                    assignVariable(I, v, value);
                    maintainFV(F, v, -1);
                    push(s, v, dl);
                }
    return 1;
}

// dl -> ddecision level
int backtrackR(Formula F, Interpretation I, int dl)
{
    //assert(dl<F.nbVariables);
    Variable v = chooseVar(F, I);
    printf("%d", v);
    if (v>=F.nbVariables || v<=0) return FALSE;
    assignVariable(I, v, FALSE);
    maintainFV(F, v, -1);
    propagate(F, I, dl);
    int status=formulaStatus(F, I, v);
    if (status==UNDEF) status=backtrackR(F, I, dl+1);
    if (status==TRUE) return status;
    // Status = false << conflict
    /// CheckOut propagations
    assignVariable(I, v, TRUE);
    status=formulaStatus(F, I, v);
    if (status==UNDEF) status=backtrackR(F, I, dl+1);
    if (status==TRUE) return status;
    // Conflict
    propagate(F, I, dl);
    assignVariable(I, v, UNDEF);
    maintainFV(F, v, 1);
    /// CheckOut propagations
    return FALSE;
}

int backtrack(Formula F)
{
    Interpretation I;
    createAndInitializeInterpretation(&I, F.nbVariables);
    s=createEmptyStack();
    int status = backtrackR(F, I, 1);
    display(I);
    return status;
}
