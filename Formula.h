#ifndef SOLVING_07_02_H
#define SOLVING_07_02_H
#include <stdio.h>
#include "vecInt.h"
#include "Interpretation.h"

#define DEFAULTSIZE 20
// Typedef usefull for readbility
typedef vecInt Clause;
typedef struct {
  int nbClauses;
  int nbVariables;
  Clause* clauses;
  Clause* occ;        //occurences
  int* clauseFreeVars;
  int* clauseStatus;
} Formula;



/*****************************************************
 * Create the memory space for a formula f
 * @param f the formula
 * @param nbClauses
 * @param nbVariables
 */
void createFormula(Formula *f,int nbClauses,int nbVariables);

/*****************************************************
 * Free the dynamic memory allocation

 *
 */
void freeFormula(Formula *f);



/*****************************************************
 * Create space for clause
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
void createClause(Formula f,int clauseNumber);

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula f,int clauseNumber, Literal l);
/// maintain free variable in the formula after changing variable
void maintainFV(Formula f, Variable v, int increament);


/*
 * @param name of file
 * @param pointer to formula
 *
 * this function read formula and store it in a formula data structure
 */
void importDimacs(char *name,Formula *formula);

/**
 * Print in a DIMACS format a formula
 * @param f the formula to print
 */
void printDimacs(Formula f);

int extractWord(FILE *f,char *buffer) ;
int str2int(char *str,int *value) ;


#endif
