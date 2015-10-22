#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<assert.h>
#include "vecInt.h"

void createEmptyVec(int initialMaxSize,vecInt *vec) {

  vec->datas = (int*) malloc(sizeof(int)*initialMaxSize);
  vec->size = 0;
  vec->maxSize = initialMaxSize;

}

void freeVec(vecInt *vec) {
  free(vec->datas);
  vec->size = 0;
  vec->maxSize = 0;
}

void increaseVec(vecInt *vec) {
  if(VERBOSE) printf("Change allocation from %d to %d (current size=%d)\n",vec->maxSize,vec->maxSize*GROWFACTOR,vec->size);
  vec->datas = realloc(vec->datas,vec->maxSize*GROWFACTOR*sizeof(int));
  vec->maxSize = vec->maxSize*GROWFACTOR;
}

void addLast(vecInt *vec,int elt) {
  if(vec->size == vec->maxSize) // One wants to add an element
    increaseVec(vec);  // But there is not enough place
  assert(vec->size < vec->maxSize);
  vec->datas[vec->size++] = elt;
}

void add(vecInt *vec,int elt,int pos) {
  shiftRight(vec,pos,1);
  vec->datas[pos] = elt;
}

void deleteLast(vecInt *vec) {
  assert(vec->size>=0);
  vec->size--;
}

void delete(vecInt *vec,int pos) {
  assert(vec->size>0);
  vec->datas[pos] = vec->datas[vec->size-1];
  vec->size--;
}

void deleteKeepOrder(vecInt *vec,int pos) {
  assert(vec->size>=1);
  shiftLeft(vec,pos,1);
}

void shiftRight(vecInt *vec,int pos,int nb) {
  if(vec->size +nb > vec->maxSize) // One wants to add nb element
    increaseVec(vec);  // But there is not enough place
  assert(vec->size + nb < vec->maxSize);

  for(int i = vec->size -1 ; i>= pos ; i--)
    vec->datas[i+nb] = vec->datas[i];
  vec->size = vec->size + nb;
}


void shiftLeft(vecInt *vec,int pos,int nb) {
  assert(vec->size >=nb);

  for(int i = pos ; i < vec->size-nb ; i++)
    vec->datas[i] = vec->datas[i+nb];
  vec->size = vec->size - nb;
}

void display(vecInt vec) {
  for(int i = 0;i<vec.size;i++)
    printf("%d ",vec.datas[i]);
   printf("\n");
}

void addSorted(vecInt *vec,int elt) {
  int i = 0;
  while(i<vec->size && vec->datas[i] < elt)  // find the good position
    i++;
  shiftRight(vec,i,1); // shift right
  vec->datas[i] = elt;
}
