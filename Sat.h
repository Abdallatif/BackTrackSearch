#ifndef Sat_H
#define Sat_H

#include"vecInt.h"
#include "Interpretation.h"

#include "Sat.h"
#include "Formula.h"
#include <stdio.h>


/**
 * give the status of a clause under a given interpretation
 * @param c the clause
 * @parm I the interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusClause(Clause c,Interpretation I);


/**
 * These 3 functions are used to help the readability
 * Use statusClause with good parameters
 */

int isSatisfiedClause(Clause c,Interpretation I);
int isFalsifiedClause(Clause c,Interpretation I);
int isUndefClause(Clause c,Interpretation I);




/**
 * Say if a clause is unit (only one literal is UNDEF and all other ones are falsified
 * under a given interpretation
 * @return 1 if yes, 0 otherwise
 */
int isUnit(Clause c,Interpretation I);

/**
 * Display a clause under a given interpretation
 * You can print colors on terminal
 * see http://www.daniweb.com/software-development/c/threads/266484/how-to-print-text-into-a-different-color-in-terminal
 * For example:
 *  the literal is true in the clause : write in green
 *  the literal is false in the clause : write in red
 * the literal is undefined in the clause : write in blue
 * @param c the clause
 * @parm I the interpretation
 */
 void displayClause(Clause c,Interpretation I);



/**
 * @param f the formula
 * @param I an interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusFormula(Formula f,Interpretation I);

/**
 * These 3 functions are used to help the readability
 * Use statusFormula with good parameters
 */
int isSatisfiedFormula(Formula f,Interpretation I);
int isFalsifiedFormula(Formula f,Interpretation I);
int isUndefFormula(Formula f,Interpretation I);

/**
 * Display a Formula under a given interpretation : Display all clauses!
 * @param c the clause
 * @parm I the interpretation
 */
 void displayFormula(Formula f,Interpretation I);


#endif
