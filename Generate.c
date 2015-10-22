
#include "Interpretation.h"
#include "Sat.h"
#include "Formula.h"
#include "Generate.h"
#include<stdlib.h>
#include<stdio.h>


/**
 * Generate and print a random clause with nbLiterals literals
 * @param f the formula
 * @param clauseNumber : the clause to generate
 * @param : the number of literals that contain the clause

 */
void generateClause(Formula f,int clauseNumber, int nbLiterals) {
  for(int i = 0;i<nbLiterals;i++) {
    int sign = rand()%2 ? 1 : -1;
    Literal l = sign*(rand()%f.nbVariables+1);
    addLast(&(f.clauses[clauseNumber]),l);
  }
}

/**
 * Generate and print nbClauses
 * @param f the formula
 * @param
 */

void generateAllClauses(Formula f) {
  for(int i = 0;i<f.nbClauses;i++)
    generateClause(f,i,rand()%5+1);
}

/**
 * Generate a full random formula
 * @param number of variables
 * @param number of clauses
 * @return the formula
 */

void generateFullRandomFormula(Formula *f,int nbVars,int nbClauses) {
  createFormula(f,nbClauses,nbVars);
  generateAllClauses(*f);


}
/**
 * Generate a 3-SAT random formula
 * Each clause have to contain exactly 3 literals
 * @param number of variables
 * @param number of clauses
 * Return the formula
 */

void generate3RandomFormula(Formula *f,int nbVars,int nbClauses)
{
	int i ;
		for ( i = 0 ; i < f->nbClauses ; i++){
			int ranNbLiterals=3;
			generateClause(*f,i,f->nbVariables);

		}

}

/**
 * Print in a DIMACS format a formula
 * @param f the formula to print
 */

void printDimacs(Formula f)
{
	int i , j ;
	for(i = 0; i<f.nbClauses ; i++)
	{
		for ( j = 0 ; j < f.clauses[i].size ; j++)
			printf("%d ", f.clauses[i].datas[j]);
		printf("0\n");

   }

}



