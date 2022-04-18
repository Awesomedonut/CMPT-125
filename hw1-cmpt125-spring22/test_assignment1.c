#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment1.h"

bool test_q1_1()  {
  if (sum_interval(1, 4)==10 && sum_interval(10, 3)==52)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

bool test_q1_2()  {
  if (sum_interval(2, -1)==2 && sum_interval(-1, -1)==-1){
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}

bool test_q2_1()  {
  char s[] = "12ab0";
  hide_letters(s);

  if (strcmp(s, "12**0")==0) {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}


bool test_q2_2()  {
  char s[] = "abcd123XYZw";
  hide_letters(s);

  if (strcmp(s, "****123$$$*")==0) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}

bool test_q3_1()  {
  int ar1[] = {1,7,-3,7,4,7};
  int ar2[] = {111};
  if (count_max(ar1,6)==3 && count_max(ar2,1)==1)   {
    printf("Q3-1 ok\n");
    return true;
  }
  else  {
    printf("Q3-1 ERROR\n");
    return false;
  }
}

bool test_q3_2()  {
  int ar[] = {-2, -3, -3};
  if (count_max(ar,3)==1)  {
    printf("Q3-2 ok\n");
    return true;
  }
  else  {
    printf("Q3-2 ERROR\n");
    return false;
  }
}

bool test_q4_1()  {
  char* res = mult_number_by_digit("12340", 6);

  if (res!=NULL && strcmp(res, "74040") == 0)  {
    free(res);
    printf("Q4-1 ok\n");
    return true;
  }
  else  {
    printf("Q4-1 ERROR\n");
    free(res);
    return false;
  }
}

bool test_q4_2()  {
  char* res = mult_number_by_digit("99999999999999999999999999999999999", 4);

  if (res!=NULL && strcmp(res, "399999999999999999999999999999999996") == 0)  {
    free(res);
    printf("Q4-2 ok\n");
    return true;
  }
  else  {
    printf("Q4-2 ERROR\n");
    free(res);
    return false;
  }
}


bool test_q5_1()  {
  int digs[] = {1,2,5,6,6,5};
  char* product = mult_digits(digs, 6);

  if (product!=NULL && strcmp(product, "1800")==0) {
    free(product);
    printf("Q5-1 ok\n");
    return true;
  }
  else  {
    free(product);
    printf("Q5-1 ERROR\n");
    return false;
  }
}


bool test_q5_2()  {
  int digs[20];
  int i;
  for (i=0;i<20;i++) digs[i] = 9;
  char* product = mult_digits(digs, 20);

  if (product!=NULL && strcmp(product, "12157665459056928801")==0) {
    free(product);
    printf("Q5-2 ok\n");
    return true;
  }
  else  {
    free(product);
    printf("Q5-2 ERROR\n");
    return false;
  }
}


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main()  {
  test_q1_1();
  test_q1_2();
  
  test_q2_1();
  test_q2_2();
  
  test_q3_1();
  test_q3_2();
  
  test_q4_1();
  test_q4_2();
  
  test_q5_1();
  test_q5_2();
 
  return 0;
}