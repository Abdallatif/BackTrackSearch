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
   f->occ = (Clause*) malloc(sizeof(Clause)*nbVariables*2);
   f->clauseFreeVars = calloc(nbClauses,sizeof(int));
   f->clauseStatus = calloc(nbClauses,sizeof(int));
   for(int i = 0;i<nbClauses;i++) {
     createClause(*f,i);
     f->clauseStatus[i]=UNDEF;
   }
   for(int i = 0;i<nbVariables*2;i++) {
     createEmptyVec(DEFAULTSIZE,&(f->occ[i]));
   }
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
    addLast(&(f.occ[getIndexLiteral(l)]),clauseNumber);
    f.clauseFreeVars[clauseNumber]+=1;
}

/// maintain free variable in the formula after changing variable
void maintainFV(Formula f, Variable v, int increament) {
    int var=(v-1)*2;
    for (int i=0; i<f.occ[var].size; i++)
        f.clauseFreeVars[f.occ[var].datas[i]]+=increament;
    var++;
    for (int i=0; i<f.occ[var].size; i++)
        f.clauseFreeVars[f.occ[var].datas[i]]+=increament;
}

//--------------------------------------------------------------------
// Function for  read a DIMACS formula
void importDimacs(char *name,Formula *formula) {
  FILE *file = fopen(name,"r");
  int nbC,nbV;
  if(file==NULL) exit(1);

  char buffer[1024]; // A Buffer. One can increase the buffer size

  // skip all comment lines
  extractWord(file,buffer);
  while(buffer[0]=='c') {
    skipLine(file);
    extractWord(file,buffer);

  }

  //  extractWord(file,buffer); // p
  extractWord(file,buffer); // cnf
  extractWord(file,buffer); // nbV
  if(str2int(buffer,&nbV)!=-1)
    exit(1);

  extractWord(file,buffer); // nbC
  if(str2int(buffer,&nbC)!=-1)
    exit(1);
  createFormula(formula,nbC,nbV);

  int clauseIndex = 0;
  while(1) {
    int lit;
    extractWord(file,buffer); // nbV
    if(str2int(buffer,&lit)!=-1)
      exit(1);
    if(lit==0) {
      clauseIndex++;
      if(clauseIndex>=nbC)
	break;
    } else {
      addLiteralInClause(*formula,clauseIndex,lit);
    }

  }

  fclose(file);


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



/**
 * We suppose the string is trimmed
 * Otherwise: http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
 * @return -1 if OK, the position of the error otherwise
 */
int str2int(char *str,int *value) {
  *value = 0;
  int sign=(str[0]=='-' ? -1 : 1);
  for(int i=(str[0]=='-' ? 1 : 0);str[i]!=0;i++) {
    if(!(str[i]>=48 && str[i]<=57)) // Ascii char 0 to 9
      return i;
    *value= *value*10+(str[i]-48);
  }
  *value = *value * sign;
  return -1;
}

int extractWord(FILE *f,char *buffer) {
  int i = 0;char c;
  // skip space, tab, \n...
  do {
    c = fgetc(f);
  } while(c==' '  || c==10  || c==13 || c=='\t');
  if(c==EOF) {
    buffer[i]=0;// Finish the empty word
    return 1;
  }
  do {
    buffer[i++] = c;
    c = fgetc(f);
    if(c==EOF) break;
  } while(c!=' ' && c!=10 && c!='\t' && c!=13);

  buffer[i] = 0;
  return c==EOF;
}
void skipLine(FILE *f) {
  for (;;){
    if (feof(f)) return;
    char c = fgetc(f);
    if (c == '\n')
      return;
  }
}







