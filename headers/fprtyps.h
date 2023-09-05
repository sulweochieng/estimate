#ifndef FPRTYP_H
#define FPRTYP_H

#include "types.h"
/* This header file contains all function protypes used in this project */
void clear_input_buffer(void);
void create_database(node **head);
void create_project(node **database, node **project);
void display_project(node **project);
void display_db(node **db);
void equilibrium(int n, ratio *equilibrium);
void equilibrium_a(int n, ratio *equilibrium);
void equilibrium_b(int n, ratio *equilibrium);
void equilibrium_c(int n, ratio *equilibrium);
void equillibrium_compute(ratio *ratioS, int devNum, node *projectName, double
		*projectCost, int levelIndex);
void free_list(node *head);
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count);
void init_levels(devLevels *levels);
void init_optimization_info(opt *info);
void list_init(node **head, profession *newData);
int *node_count(node **head, int *counter);
void node_cost_update(node *project, ratio *ratioS, double *projectCost);
void optimum_a(int n, ratio *choice);
void optimum_b(int n, ratio *choice);
void optimum_c(int n, ratio *choice);
void print_levels(devLevels *levels);
void project_cost_calc(node *projectName, double *projectCost);
void rm_from_project(node **project);
char *user_input_string(void);
profession *create_field(void);
profession **prof_list(void);
#endif
