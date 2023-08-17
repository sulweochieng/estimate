#ifndef FPRTYP_H
#define FPRTYP_H
/* This header file contains all function protypes used in this project */
void add_beg_list(node **head, node *node);
int **allocate_2D_array(unsigned long int rows, unsigned int cols);
void equilibrium(int n, ratio *equilibrium);
void equilibriumA(int n, ratio *equilibrium);
void equilibriumB(int n, ratio *equilibrium);
void equilibriumC(int n, ratio *equilibrium);
void free_linked_list(node **head);
void free_node(node **temp);
void free_2D_array(int **array2D, unsigned long int rowSize);
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count);
unsigned int node_count(node *head);
void optimumA(int n, ratio *choice);
void optimumB(int n, ratio *choice);
void optimumC(int n, ratio *choice);
char *user_input_string(void);
node *create_list(node *newNode);
node *new_node(profession *newData);
profession *create_field(void);
#endif
