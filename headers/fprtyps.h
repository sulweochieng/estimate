#ifndef FPRTYP_H
#define FPRTYP_H

#include "types.h"
/* This header file contains all function protypes used in this project */
void choice_check(int *input, int range);
void clear_input_buffer(void);
void clearScreen(void);
void create_database(node **head);
void create_project(node **database, proj **project, double *projectCost, int
		*devNum);
int db_entry_check(node **db, char *entry);
void delete_item_select(proj **project, int *index);
void display_opt_info(opt *optInfo, int *index);
void display_project(proj **project);
void display_project_details(proj **project, double *projectCost, int *devNum,
		int *months, double *tProjectCost);
void display_db(node **db);
void equilibrium(int n, ratio *equilibrium);
void equilibrium_a(int n, ratio *equilibrium);
void equilibrium_b(int n, ratio *equilibrium);
void equilibrium_c(int n, ratio *equilibrium);
void equillibrium_compute(ratio *ratioS, int *devNum, int *levelIndex);
void free_list(node *head);
void free_proj(proj *head);
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count);
void init_func(node **database, proj **project, double *projectCost, int
		*devNum, double *tProjectCost, int *months, int *action, char
		*menu[], int menuSize);
void init_levels(devLevels *levels);
void init_optimization_info(opt *info);
bool is_node_in_project(proj *project, node *selectedNode);
void lf_check(double *input);
void list_init(node **head, profession **newData);
void nod_assign(proj **project, node **selectedNode, proj **projectNode, double
		*projectCost, int *devNum);
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
void project_sum(double *projectCost,double *tProjectCost, int *months);
int proj_count(proj **head);
void rm_from_db(node **db);
void rm_from_project(proj **project, double *projectCost, int *devNum, int
		*months, double *tProjectCost);
void salut(void);
int string_input_check( char *buffer);
void to_upper(char *buffer);
void unit_sum(proj **nod, ratio *rat, double *nCost);
void user_input_string(node **db, char **buffer);
void create_field(node **db, profession **newfield);
profession **prof_list(void);
#endif
