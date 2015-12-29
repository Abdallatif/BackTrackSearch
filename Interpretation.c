#include "vecInt.h"
#include "Interpretation.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/*******************************************************
 * return the associated variable of a literal
 * @param l the literal
 */
Variable getVariable(Literal l) {
  return l>0 ? l  : -1 * l;
}

Variable getIndexLiteral(Literal l) {
    if (l>0)
        return (l-1)*2;
    return ((-1*l-1)*2)+1;
}
/*******************************************************
 * Create memory space for an interpretation I with n variables
 * @param I the interpretation
 * @param nbVariables, the number of variables (do not forget, start from 1)
 */
void createAndInitializeInterpretation(Interpretation *I,int nbVariables) {
  createEmptyVec(nbVariables+1,I);
  for(int i = 0;i <= nbVariables;i++)
    addLast(I,UNDEF);
}


/*******************************************************
 * Free allocated space
 * @param I the interpretation
 */
void freeInterpretation(Interpretation *I) {
  freeVec(I);
}

/**
 * Return the value of a variable in the interpretation
 * @param I the interpretation
 * @param v the variable
 * @return UNDEF, TRUE or FALSE depending the value of the variable
 */
int getValueVariable(Interpretation I,Variable v) {
  assert(v>0 && v <=I.size);
  return I.datas[v];
}

/*******************************************************
 * Return the value of a Literal in the interpretation
 * @param I the interpretation
 * @param l the literal
 * @return UNDEF if l is  not assigned
 * @return TRUE if l is positive and value is TRUE or l is negative and value is false
 * @return FALSE if l is negative and value is TRUE or l is positive and value is false
 */
int getValueLiteral(Interpretation I, Literal l) {
  assert(l!=0);
  assert(l>=-I.size && l<=I.size);
  Variable v = getVariable(l);
  if(getValueVariable(I,v)==UNDEF) return UNDEF;
  if((getValueVariable(I,v)==TRUE && l>0) || (getValueVariable(I,v)==FALSE && l<0)) return TRUE;
  return FALSE;
}



/*******************************************************
 * Change the value of a variable in the interpretation
 * if I[v] == TRUE then I[v]<- FALSE (and vice versa)
 * if I[v] == UNDEF then no effect
 * @param I the interpretation
 * @param v the variable
 */
void flipValue(Interpretation I, Variable v) {
  assert(v>0 && v <=I.size);
  if(I.datas[v]==UNDEF) return;
  if(I.datas[v]==TRUE) I.datas[v]=FALSE;
  else I.datas[v] = TRUE;
}




/*******************************************************
 * Assign a variable to a given value
 * @param I the interpretation
 * @param v the variable
 * @param value (TRUE, FALSE, UNDEF)
 */
void assignVariable(Interpretation I,Variable v,int value) {
  assert(v>0 && v <=I.size);
  I.datas[v] = value;
}



/*******************************************************
 * Assign a literal to true
 * if l is positive then I[|l|] = TRUE
 * if l is negative then I[|l|] = FALSE
 * @param I the interpretation
 * @param l the literal
 */
void assignLiteral(Interpretation I,Literal l) {
  assert(l!=0);
  assert(l>=-I.size && l<=I.size);
  if(l>0) I.datas[l] = TRUE;
  else I.datas[-l] = FALSE;
}



/*******************************************************
 * assign TRUE or FALSE for ALL literals
 * @param I the interpretation
 */
void generateRandomComplete(Interpretation I) {
  for(int i = 1;i<=I.size;i++) {
    int value;
    int v= rand()%2;
    if(v==0) value=FALSE;
    else value=TRUE;
    assignVariable(I,i,value);
  }
}

