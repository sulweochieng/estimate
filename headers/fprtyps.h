#ifndef FPRTYP_H
#define FPRTYP_H

#include "types.h"
/* This header file contains all function protypes used in this project */
void add_beg_list(node **head, node *node);
int **allocate_2D_array(unsigned long int rows, unsigned int cols);
void equilibrium(int n, ratio *equilibrium);
void equilibrium_a(int n, ratio *equilibrium);
void equilibrium_b(int n, ratio *equilibrium);
void equilibrium_c(int n, ratio *equilibrium);
void equillibrium_compute(ratio *ratioS, int devNum, node *projectName, double
		*projectCost, int levelIndex);
void free_linked_list(node **head);
void free_node(node **temp);
void free_2D_array(int **array2D, unsigned long int rowSize);
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count);
void init_levels(devLevels *levels);
void init_optimization_info(opt *info);
void list_init(node *listName);
unsigned int node_count(node *head);
void node_cost_update(node *project, ratio *ratioS, double *projectCost);
void optimum_a(int n, ratio *choice);
void optimum_b(int n, ratio *choice);
void optimum_c(int n, ratio *choice);
void print_levels(devLevels *levels);
void project_cost_calc(node *projectName, double *projectCost);
char *user_input_string(void);
node *create_list(node *newNode);
node *new_node(profession *newData);
profession *create_field(void);
#endif
