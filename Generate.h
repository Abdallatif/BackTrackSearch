#ifndef SOLVING_01_04_MOFIFY_H
#define SOLVING_01_04_MOFIFY_H
#include "Interpretation.h"
#include "Formula.h"
#include "Sat.h"
#include "vecInt.h"
/**
 * This is a modified version of problem solving session 01
 * exercice 4.
 * Here we continue to generate a random formula, but we do not print
 * it, but store it inside Formula
 */


/**
 * Generate and print a random clause with nbLiterals literals
 * @param f the formula
 * @param clauseNumber : the clause to generate
 * @param : the number of literals that contain the clause

 */
void generateClause(Formula f,int clauseNumber, int nbLiterals);

/**
 * Generate and print nbClauses
 * @param f the formula
 * @param clauseNumber the clause to genrate
 * @param nbLiterals the number of literals in the clause
 * @param nbVariablesInFormula the number of variables in the formula

 */

void generateAllClauses(Formula f);

/**
 * Generate a full random formula
 * @param number of variables
 * @param number of clauses
 * @return the formula
 */

void generateFullRandomFormula(Formula *f,int nbVars,int nbClauses);


/**
 * Generate a 3-SAT random formula
 * Each clause have to contain exactly 3 literals
 * @param number of variables
 * @param number of clauses
 * Return the formula
 */

void generate3RandomFormula(Formula *f,int nbVars,int nbClauses);



#endif

