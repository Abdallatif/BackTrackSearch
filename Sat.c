#include "vecInt.h"
#include "Interpretation.h"
#include "Sat.h"
#include "Formula.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*the clause is true if there is at least one TRUE literal (theTRUE has the highest priority)
 *THe Clause is False if all the literals are False and there is no UNDEF.
 * The Clause is UNDEF if there is no TRUE and at least one UNDEF.
 **/

 /*the flaseFlag is used to check if there is at least one UNDEF. So if it becomes true then there is UNDEF so the clause
  * is UNDEF*/
int statusClause(Clause c,Interpretation I)
{
		int i,falseFlag = FALSE;

		for (i=0;i<c.size;i++)
			if( getValueLiteral(I,c.datas[i])==TRUE)
				return TRUE;
			else if(getValueLiteral(I,c.datas[i])==UNDEF)
				falseFlag = TRUE;

		if (falseFlag == FALSE )
			return FALSE ;
		else
			return UNDEF;

}

int isSatisfiedClause(Clause c,Interpretation I)
{
	return (statusClause(c,I)==TRUE);
}
int isFalsifiedClause(Clause c,Interpretation I)
{
	return (statusClause(c,I)==FALSE);
}


int isUndefClause(Clause c,Interpretation I)
{
	return (statusClause(c,I)==UNDEF);
}

/*If a clause is satisfied, it is not Unit.
 *We must count the number of UNDEF since the clause is UNIT if it has only 1 UNDEF */
int isUnit(Clause c,Interpretation I)
{
	int i,count=0;

	if(isSatisfiedClause(c,I))
		return FALSE;

	for (i=0;i<c.size;i++)
		if(getValueLiteral(I,c.datas[i])==UNDEF)
			count++;
	return(count==1);
}


 void displayClause(Clause c,Interpretation I)
 {
	int i;

	for (i=0;i<c.size;i++)
		if( getValueLiteral(I,c.datas[i])==TRUE)
			printf("\033[22;32m %d ",c.datas[i]);
		else if( getValueLiteral(I,c.datas[i])==FALSE)
			printf("\033[22;31m %d ",c.datas[i]);
		else
			printf("\033[22;34m %d ",c.datas[i]);
	printf("\033[01;37m \n");
}


int statusFormula(Formula f,Interpretation I)
{
	int i,flag=FALSE ;
	for (i=0;i<f.nbClauses;i++)
	{
		if (isUndefClause(f.clauses[i] , I ))
			flag = TRUE;
		if (isFalsifiedClause(f.clauses[i] , I ))
			return FALSE;

	}
	if(flag==TRUE)
		return UNDEF;

	return TRUE;
}


int isSatisfiedFormula(Formula f,Interpretation I)
{
	return (statusFormula(f,I) == TRUE);
}
int isFalsifiedFormula(Formula f,Interpretation I)
{
	return (statusFormula(f,I) == FALSE);
}
int isUndefFormula(Formula f,Interpretation I)
{
	return (statusFormula(f,I) == UNDEF);
}


void displayFormula(Formula f,Interpretation I)
 {
	int i;

	for (i=0;i<f.nbClauses;i++)
		displayClause(f.clauses[i],I);
 }
