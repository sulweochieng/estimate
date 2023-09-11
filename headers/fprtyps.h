#ifndef FPRTYP_H
#define FPRTYP_H

#include "types.h"
/* This header file contains all function protypes used in this project */
void clear_input_buffer(void);
void clearScreen(void);
void create_database(node **head);
void create_project(node **database, proj **project, double *projectCost, int
		*devNum);
void display_opt_info(opt *optInfo, int *index);
void display_project(proj **project);
void display_project_details(proj **project, double *projectCost, int *devNum);
void display_db(node **db);
void equilibrium(int n, ratio *equilibrium);
void equilibrium_a(int n, ratio *equilibrium);
void equilibrium_b(int n, ratio *equilibrium);
void equilibrium_c(int n, ratio *equilibrium);
void equillibrium_compute(ratio *ratioS, int *devNum, proj **projectName,
		int *levelIndex);
void free_list(node *head);
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count);
void init_levels(devLevels *levels);
void init_optimization_info(opt *info);
bool is_node_in_project(proj *project, node *selectedNode);
void list_init(node **head, profession *newData);
int node_count(node **head);
double node_cost_update(proj **projectNode, ratio *ratioS);
void optimum_a(int n, ratio *choice);
void optimum_b(int n, ratio *choice);
void optimum_c(int n, ratio *choice);
int opt_info_set(proj **projNode, opt *optInfo);
void print_levels(devLevels *levels);
int prof_num(proj **project, int *profNum, int nodNum);
double project_costing(proj **project, double *projectCost);
void project_cost_calc(proj **projectName, double *projectCost, int *profNum);
double project_cost_reduce(proj **projectNode, double *projectCost);
void rm_from_db(node **db);
void rm_from_project(proj **project, double *projectCost);
void salut(void);
void unit_sum(proj **nod, ratio *rat, double *nCost);
char *user_input_string(void);
profession *create_field(void);
profession **prof_list(void);
#endif
