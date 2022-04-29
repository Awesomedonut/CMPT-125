#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment2.h"

char* find_term(const char* file_name, const char* term){
  FILE *file_content;
  file_content = fopen(file_name,"r");
  int term_len;
  int defn_len;
  int found = 0;

  rewind(file_content);
   //printf("%d",fscanf(file_content, "%d<", &term_len));

   while(fscanf(file_content, "%d<", &term_len)!= EOF && found != 1){
    //fscanf(file_content, "%d<", &term_len);
    char* current_term = (char*)malloc(term_len+1);
    current_term[term_len] = '\0';
   
    fread(current_term, term_len, 1, file_content);
 
 //  printf("Read int |%d|\n", term_len );
 //  printf("Read string |%s|\n", current_term );
   fscanf(file_content, "%d<", &defn_len);

 char* current_defn = (char*)malloc(defn_len);
 fread(current_defn, defn_len, 1, file_content);
   if(strcmp (current_term, term) == 0){
       found = 1;
       free(current_term);

       fclose(file_content);
       return current_defn;
   }
   free(current_term);
   free(current_defn);
   } 
   fclose(file_content);
   return(NULL);
}

int add_term(const char* file_name, const char* term, const char* definition){
  FILE *file_content;
  int return_value = 0;
  file_content = fopen(file_name, "r");
  if(file_content != NULL && find_term(file_name, term) != NULL){ //term alr in
    fclose(file_content);
    return_value = 0;
  }else{
    //if(file_content != NULL){
      fclose(file_content);
    //}
    file_content = fopen(file_name,"a");
  //  fprintf(file_content,"%ld<%s",strlen(term),term);
   // fprintf(file_content,"%ld<%s",strlen(definition),definition);
    fclose(file_content);
    return_value = 1;
  }
return return_value;
}

uint64_t fib3(unsigned int n){
    if(n < 3){
        return n;
    }

uint64_t minus_one = fib3(n-1);
    uint64_t minus_two = 2 * (fib3(n-2));
  uint64_t minus_three = 3 * (fib3(n-3));
  uint64_t nth = minus_one + minus_two + minus_three;

  return nth;
}


int is_lower(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return 1;
    }else{
        return 0;
    }
}

int count_tokens(const char* str) {
    int token_count = 0;
    int inside_token = 0;
    int only_lower = 1;
    char delimiter = ' ';
    for (int i = 0; i < strlen(str); i++){
        if(is_lower(str[i]) == 1 && only_lower == 1){
            inside_token = 1;
            if(i == strlen(str) - 1){
            //    printf("line 22: %c\n",str[i]);
                token_count++;
            }
        }else if(str[i] == delimiter){
            if(only_lower == 1 && inside_token == 1){
           //     printf("line 27: %c\n",str[i]);
                token_count++;
            }
            inside_token = 0;
            only_lower = 1;
        }else{
            inside_token = 1;
            only_lower = 0;
        }
    }
        //printf("%c",str[i]);
       
//     char* str = (char*)malloc(strlen(str));
    return token_count;
} 

char** get_tokens(const char* str){
   int array_length = count_tokens(str);

    char **tokens = (char**) malloc(array_length * 255);

    int token_count = 0;
    int inside_token = 0;
    int indiv_char = 0;
    int only_lower = 1;
    char delimiter = ' ';
 
    for (int i = 0; i < strlen(str); i++){
        if(is_lower(str[i]) == 1 && only_lower == 1){
            if(indiv_char == 0){
              tokens[token_count] = malloc(255);
            }
            inside_token = 1;
      
            tokens[token_count][indiv_char] = str[i];
            indiv_char++;
            if(i == strlen(str) - 1){
                //printf("line 22: %c\n",str[i]);
               
      
                tokens[token_count][indiv_char] = '\0';
                //printf("token %s", tokens[token_count]);
                         indiv_char = 0;
                          token_count++;
            }
        }else if(str[i] == delimiter){
            if(only_lower == 1 && inside_token == 1){
                //printf("line : %c\n",str[i]);
    
                
                tokens[token_count][indiv_char] = '\0';
                //printf("token %s", tokens[token_count]);
                            token_count++;
            }
            indiv_char = 0;
            inside_token = 0;
            only_lower = 1;
        }else{
            inside_token = 1;
            only_lower = 0;
            indiv_char = 0;
        }
    }
return tokens;
}