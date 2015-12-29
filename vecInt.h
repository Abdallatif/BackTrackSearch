#ifndef VECINT_H
#define VECINT_H

#define GROWFACTOR 2
#define VERBOSE 1

typedef struct {
  int size;         // The current size of the array
  int maxSize;  // The max size of the array
  int* datas;     // The datas stored
} vecInt;

void createEmptyVec(int initialMaxSize,vecInt*a); // create the data structure
void   freeVec(vecInt *vec); // free the data structure
void increaseVec(vecInt *vec); // increase the Maxsize of the array

void addLast(vecInt *vec,int elt); // Add element elt at the end
void add(vecInt *vec,int elt,int pos); // Add element elt at position pos
void addSorted(vecInt *vec,int elt); // Add at good position in a sorted array

void deleteLast(vecInt *vec); //delete the last element
void delete(vecInt *vec,int pos); //delete element at position pos
void deleteKeepOrder(vecInt *vec,int pos); // delete but keep order of elements

void shiftRight(vecInt *vec,int pos,int nb); //shift nb elts on right starting from pos
void shiftLeft(vecInt *vec,int pos,int nb); //shift nb elts on left until pos

void display(vecInt vec); // Display it

#endif
