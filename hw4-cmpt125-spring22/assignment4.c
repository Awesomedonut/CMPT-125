#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */
int queue_move(queue_t* destination, queue_t* source) {
  while (source->obfuscate[source->what] != NULL)
  {
    enqueue(destination, dequeue(source));
  }
  return 0;
}

int queue_size(queue_t* q) {
  node_t* current = q->obfuscate[q->what];
  int count = 0;
  while (current != NULL)
  {
    current = current->next;
    count ++;
  }
  return count;
}

bool queue_equal(queue_t* q1, queue_t* q2) {
  node_t* q1_current = q1->obfuscate[q1->what];
  node_t* q2_current = q2->obfuscate[q2->what];

  if(q1_current == NULL && q2_current == NULL){
    return true;
  }
  if(q1_current == NULL || q2_current == NULL){
    return false;
  }
  if(q1_current->data != q2_current->data){
    return false;
  }

  while ((q1_current != NULL && q2_current != NULL) 
  && (q1_current->data == q2_current->data))
  {
    q1_current = q1_current->next;
    q2_current = q2_current->next;
  }
  if(q1_current == NULL && q2_current == NULL)
    return true;
  else
    return false;

}

/* Question 2 */

float eval_arithmetic_expression(BTnode_t* root) {    
    BTnode_t* current = root;
    float answser = 0;
    if(current == NULL)
      return answser;

    switch(current->value)
    {
        case '+':
            answser = eval_arithmetic_expression(current->left) + 
            eval_arithmetic_expression(current->right);
            break;

        case '-':
            answser = eval_arithmetic_expression(current->left) -
            eval_arithmetic_expression(current->right);   
            break;

        case '*':
            answser = eval_arithmetic_expression(current->left) *
            eval_arithmetic_expression(current->right);  
            break;

        case '/':
            answser = eval_arithmetic_expression(current->left) /
            eval_arithmetic_expression(current->right);    
            break;
        default:
            return current->value;
    }
  return answser;
}


/* Question 3 */

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
    BTnode_t* current = root;
    if(current == NULL)
      return NULL;
      if(pred(current->value))
        return current;
      else{
       BTnode_t* left = find(current->left,pred);
       if(left != NULL)
        return left;

       BTnode_t* right = find(current->right,pred);
       if(right != NULL)
        return right;
      }
      return NULL;
}

BTnode_t* create_mirror_tree(BTnode_t* root) {
  BTnode_t* current = root;
  BTnode_t* mirrored_root = NULL;
  if(current == NULL)
    return NULL; 
  mirrored_root = create_node(current->value);
  if(current->left != NULL)
      set_right_child(mirrored_root,  create_mirror_tree(current->left));// mirrored_root->right = create_mirror_tree(current->left);
     if(current->right != NULL)
      set_left_child(mirrored_root,create_mirror_tree(current->right));   
  return mirrored_root;
}

