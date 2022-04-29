#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment3.h"

// generic swap
// assumption: the memory segments don't overlap
void swap(void* a, void* b, size_t s)  {
  char* char_a = (char*)a;
  char* char_b = (char*)b;

  for (int i=0;i<s;i++) {
    char tmp = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = tmp;
  }

 // ALTERNATIVE, requires extra space
 /* void* tmp = malloc(s);
  memcpy(tmp, a, s);
  memcpy(a, b, s);
  memcpy(b, tmp, s);
  free(tmp);*/

} 

int comp(const void* a, const void* b){

  point2d first = *(point2d*)a;
  point2d second = *(point2d*)b;

  //printf("first.x %d\n", first.x);
 // printf("first.y %d\n", first.y);

  int first_sum = abs(first.x) + abs(first.y);
  int second_sum = abs(second.x) + abs(second.y);

  if(first_sum != second_sum){
    return first_sum - second_sum;
  }else if(first.x != second.x){
    return first.x - second.x;
  }else{
    return first.y - second.y;
  }
}

void sort_points(point2d* ar, int n) {
  qsort(ar, n, sizeof(point2d), comp);
}  

/*int* rand = 4294;
  printf("%p\n", &rand);
  printf("%d\n",*(&rand));
  return 0;*/

int gen_insertion_sort(void* ar, int n, size_t size, int compare(const void*, const void*)) {
  int swap_num = 0;
  void* curr;
  void* prev;
  int j;

  for(int i = 1; i < n; i++){
    j = i;
    curr = (unsigned char*)(ar+(size*j));
    prev = (unsigned char*)(ar+(size*(j-1)));
    while (compare(prev, curr) >= 0 && j > 0) {
      swap(prev, curr, size);
      swap_num++;
      j--;

    curr = (unsigned char*)(ar+(size*j));
    prev = (unsigned char*)(ar+(size*(j-1)));
    }
  }
  return swap_num;
}  

int find(int* A, int start, int end, bool (*pred)(int)) {
  for(int i = start; i <= end; i++){
    if(pred(A[i]) == true){
      return i;
    }
  }
  return -1;
}  


int count(int* A, int start, int end, bool (*pred)(int)) {
  int counter = 0;
  for(int i = start; i <= end; i++){
    if(pred(A[i]) == true){
      counter++;
    }
  }
  return counter;
}  


void map(int* A, int start, int end, int (*f)(int)) {
  for(int i = start; i <= end; i++){
    A[i] = f(A[i]);
  }
}  


int reduce(int* A, int start, int end, int (*f)(int,int)) {
  int accu = A[start];
  if(start == end){
    return accu;
  }
  for(int i = start + 1; i <= end; i++){
    accu = f(accu, A[i]);
  }
  return accu;
}