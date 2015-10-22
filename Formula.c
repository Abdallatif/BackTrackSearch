#include "vecInt.h"
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



/*****************************************************
 * Create the memory space for a formula f
 *
 */
void createFormula(Formula *f,int nbClauses,int nbVariables) {
   f->nbClauses = nbClauses;
   f->nbVariables = nbVariables;
   f->clauses = (Clause*) malloc(sizeof(Clause)*nbClauses);


   for(int i = 0;i<nbClauses;i++)
    createClause(*f,i);

}

void freeFormula(Formula *f) {
  for(int i = 0;i<f->nbClauses;i++)
    freeVec(&(f->clauses[i]));
  free(f->clauses);
}

/*****************************************************
 * Create space for clause
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
void createClause(Formula f,int clauseNumber) {
  assert(clauseNumber < f.nbClauses);
  createEmptyVec(DEFAULTSIZE,&(f.clauses[clauseNumber]));
}

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula f,int clauseNumber, Literal l) {
  assert(clauseNumber < f.nbClauses);
  addLast(&(f.clauses[clauseNumber]),l);

}










