#ifndef SOLVING_07_01_H
#define SOLVING_07_01_H
#include "vecInt.h"


// The seed for random numbers
#define SEED 100

// The different values of a variables
#define TRUE 1
#define FALSE 0
#define UNDEF -1


// Som typedef, usefull for readability
typedef vecInt Interpretation;  // For interpretation we can use a array with a fixed size
                                // I prefer that one that avoid many different structures

typedef int Variable;  // Be careful Variables starts from 1 to nbVariables
typedef int Literal;

/*******************************************************
 * return the associated variable of a literal
 * @param l the literal
 */
Variable getVariable(Literal l);


/*******************************************************
 * Create memory space for an interpretation I with n variables
 * Assign all variables to UNDEF
 * @param I the interpretation
 * @param nbVariables, the number of variables (do not forget, start from 1)
 */
void createAndInitializeInterpretation(Interpretation *I,int nbVariables);

/*******************************************************
 * Free allocated space
 * @param I the interpretation
 */
void freeInterpretation(Interpretation *I);


/**
 * Return the value of a variable in the interpretation
 * @param I the interpretation
 * @param v the variable
 * @return UNDEF, TRUE or FALSE depending the value of the variable
 */
int getValueVariable(Interpretation I,Variable v);

/*******************************************************
 * Return the value of a Literal in the interpretation
 * @param I the interpretation
 * @param l the literal
 * @return UNDEF if l is  not assigned
 * @return TRUE if l is positive and value is TRUE or l is negative and value is false
 * @return FALSE if l is negative and value is TRUE or l is positive and value is false
 */
int getValueLiteral(Interpretation I, Literal l);





/*******************************************************
 * Change the value of a variable in the interpretation
 * if I[v] == TRUE then I[v]<- FALSE (and vice versa)
 * if I[v] == UNDEF then no effect
 * @param I the interpretation
 * @param v the variable
 */
void flipValue(Interpretation I, Variable v);




/*******************************************************
 * Assign a variable to a given value
 * @param I the interpretation
 * @param v the variable
 * @param value (TRUE, FALSE, UNDEF)
 */
void assignVariable(Interpretation I,Variable v,int value);



/*******************************************************
 * Assign a literal to true
 * if l is positive then I[|l|] = TRUE
 * if l is negative then I[|l|] = FALSE
 * @param I the interpretation
 * @param l the literal
 */
void assignLiteral(Interpretation I,Literal l);



/*******************************************************
 * assign TRUE or FALSE for ALL literals
 * @param I the interpretation
 */
void generateRandomComplete(Interpretation I);

#endif
