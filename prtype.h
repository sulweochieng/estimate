#ifndef PRTYPE_H
#define PRTYPE_H

#include "header.h"

field *create_newField(void);
void free_new(field *new);
fieldNode *create_node(field *newData);
fieldNode *create_new_list(void);
fieldNode *add_node_last(fieldNode *head, fieldNode *newNode);
fieldNode *add_node_beginning(fieldNode *head, fieldNode *newNode);
void printList(fieldNode *head);
void add_to_list(void);
void clear_input_buffer(void);

#endif
