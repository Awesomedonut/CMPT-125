#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#include "assignment2.h"

bool test_q1_1()  {
  char* term1 = "word";
  char* def1 = "A single distinct meaningful element of speech or writing.";
  char* other_def1 = "Some other definition...";

  char* term2 = "cat";
  char* def2 = "A small domesticated carnivorous mammal with soft fur. :: (^._.^) ::";

  int ret1 = add_term("dictionary1.txt", term1, def1);
  int ret2 = add_term("dictionary1.txt", term2, def2);
  int ret3 = add_term("dictionary1.txt", term2, other_def1);

  char* ans1 = find_term("dictionary1.txt", "hello world");
  char* ans2 = find_term("dictionary1.txt", term2);
/*
  printf("ret1 = %d\n", ret1);
  printf("ret2 = %d\n", ret2);
  printf("ret3 = %d\n", ret3);
  if (ans1) printf("ans1 = %s\n", ans1);
  else printf("ans1 is NULL\n");
  if (ans2)    printf("ans2 = %s\n", ans2);
  else printf("ans2 is NULL\n");
*/

printf("ret 1 = %d, ret 2 = %d, ret 3 = %d\n", ret1, ret2, ret3);
printf("ans1 = %s, ans2 = %s", ans1, ans2);

  if (ret1==1 && ret2==1 && ret3==0
      && ans1 == NULL // ans1 should be null
      && ans2 != NULL && strcmp(ans2, def2)==0)  {
    // no need to free ans1 because it is null
    free(ans2);
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}


bool test_q1_2()  {
  char* term1 = "Climb Mount Fuji";
  char* def1 = "Climb Mount Fuji,\nO snail,\nbut slowly, slowly.";

  char* term2 = "It's alive";
  char* def2 = "A famous quote from some movie";

  int ret1 = add_term("dict1.dat", term1, def1);
  int ret2 = add_term("dict2.dat", term2, def2);

  char* ans1 = find_term("dict1.dat", term2); // "It's alive" should not be found in dict1.dat
  char* ans2 = find_term("dict2.dat", term2); // should be here.

/*
  printf("ret1 = %d\n", ret1);
  printf("ret2 = %d\n", ret2);
  if (ans1) printf("ans1 = %s\n", ans1);
  else printf("ans1 is NULL\n");
  if (ans2) printf("ans2 = %s\n", ans2);
  else printf("ans2 is NULL\n");
*/

//printf("ret1 = %d, ret2 = %d\n",ret1, ret2);
//printf("ans1 = %s, ans2 = %s\n", ans1, ans2);

  if (ret1==1 && ret2==1 &&
      ans1 == NULL && // ans1 should be null
      ans2 != NULL && strcmp(ans2, def2)==0)  {
    // no need to free ans1 because it is null
    free(ans2);
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}

#define LEN 8
bool test_q2_1()  {
  uint64_t f[LEN];
  for (int i=0;i<LEN;i++)
    f[i] = fib3(i);

  uint64_t correct[] = {0, 1, 2, 4, 11, 25, 59, 142};

  bool check = true;
  for (int i=0;i<LEN;i++)
    if (f[i] != correct[i])
      check=false;

  if (check) {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}


bool test_q2_2()  {

  uint64_t a = fib3(20);
  uint64_t b = fib3(30);

  if (a==10771211 && b==61354575194) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}

bool test_q3_1()  {
  char* str1 = "abc EFaG hi ";
  char* str2 = "ab12ef+";
  if (count_tokens(str1)==2 && count_tokens(str2)==0) {
    printf("Q3-1 ok\n");
    return true;
  }
  else  {
    printf("Q3-1 ERROR\n");
    return false;
  }
}

bool test_q3_2()  {
  char* str1 = "Ab +  abc EF++aG hi  jkL";
  char* str2 = "This is a very famous quote";
  printf("hello1");
  int count1 = count_tokens(str1);
printf("hello2");
  int count2 = count_tokens(str2);
  
  char** tokens1 = get_tokens(str1);
  
  char** tokens2 = get_tokens(str2);

  if (count1 != 2 || count2 != 5) {
    printf("Q3-2 ERROR - wrong count\n");
    return false;
  }

/*
  printf("\n---\n");
  for (int i=0;i<count1; i++)
    printf("%d :: %s\n", i, tokens1[i]);
  printf("---\n");
  for (int i=0;i<count2; i++)
    printf("%d :: %s\n", i, tokens2[i]);
  printf("\n---\n");
*/

  bool check_tokens1 = false;
  if (tokens1 
      && tokens1[0] && strcmp(tokens1[0],"abc")==0
      && tokens1[1] && strcmp(tokens1[1],"hi")==0) {

    // free everything tokens1
    for (int i=0;i<count1;i++)
      free(tokens1[i]);
    free(tokens1);
    check_tokens1=true;
  }


  bool check_tokens2 = false;
  if (tokens2 
      && tokens2[0] && strcmp(tokens2[0],"is")==0
      && tokens2[1] && strcmp(tokens2[1],"a")==0
      && tokens2[2] && strcmp(tokens2[2],"very")==0
      && tokens2[3] && strcmp(tokens2[3],"famous")==0
      && tokens2[4] && strcmp(tokens2[4],"quote")==0) {

  
    // free everything tokens2
    for (int i=0;i<count2;i++)
      free(tokens2[i]);
    free(tokens2);
    check_tokens2=true;
    }


  if (check_tokens1 && check_tokens2) {
    printf("Q3-2 ok\n");
    return true;
  }
  else  {
    printf("Q3-2 ERROR\n");
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
  
  return 0;
}