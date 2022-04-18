#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

int sum_interval(int x, int y){
  int sum = 0;
    if (x < y){
      while(x <= y){
        sum = sum + x;
        x++;
      }
      return sum;
    }else if (x == y){
      sum = x;
      return sum;
    }else{
      while(y <= x){
        sum = sum + y;
        y++; 
        }
        return sum;
      }  
}


int hide_letters(char* str){
  int lettersmodi = 0;
    
  for (int i = 0; i < strlen(str); i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      // upper
      str[i] = '$';
      lettersmodi++;
    }else if(str[i] >= 'a' && str[i] <= 'z'){
      //lower
      str[i] = '*';
      lettersmodi++;
    }
  }
  return lettersmodi;
}


int count_max(const int* arr, int n){
    int maxnum = arr[0];
    int amtofmax = 0;

    for(int i = 0; i < n; i++){
        if (arr[i] > maxnum){
          maxnum = arr[i];
        }
    }
    for(int j = 0; j < n; j++){
      if (arr[j] == maxnum){
        amtofmax++;
      }
    }
    return amtofmax;
}


char* mult_number_by_digit(const char* num, int digit) {
    int length = strlen(num);
   // printf("length of num is %d", length);
    char* output = (char*)malloc(length+2);
    output[length+2] = '\0';
    int temp = 0;
    int current_digit;

    for(int i = length - 1; i > 0; i--){
        current_digit = num[i] - '0';
        current_digit = current_digit * digit + temp;

        printf("when i = %d current digit is %d\n", i, current_digit);

   // printf("current_digit % 10 is %d, temp is %d \n", current_digit % 10, temp);
     

  //    printf("current digit line 33 %d \n", current_digit);
    
    output[i + 1] = (current_digit % 10) + '0';
       
        temp = (current_digit - (current_digit % 10)) / 10;
 
        printf("40 temp is %d\n", temp);
    }

printf("output line 43 is %s\n", output);
  current_digit = (num[0] - '0') * digit + temp;

    if(current_digit / 10 == 0){
        output[1] = current_digit + '0';
        printf("output[1] is %c", output[1]);
      
        char* new_output = (char*)malloc(length + 1);
        for(int i = 0; i <= length + 1; i++){
            new_output[i] = output[i+1];
        }
        return new_output;
   printf("new output is %s\n", new_output);

    }else{
        output[0] = (current_digit / 10) + '0';
        output[1] = (current_digit - (current_digit / 10) * 10) + '0';
      
        printf("output is %s\n", output);
    }

    return output;

}

char* mult_digits(const int* digits, int n) {
    char* ans = (char*) malloc(1);
    ans[0] = digits[0] + '0';
    for(int i = 1; i < n; i++){
      ans = mult_number_by_digit(ans,digits[i]);
    }
  return ans;
}