#ifndef FPRTYP_H
#define FPRTYP_H
/* This header file contains all function protypes used in this project */
void add_beg_list(node **head, node *node);
int **allocate_2D_array(unsigned long long int rows, unsigned int cols);
unsigned long long int binomial_coefficient(int n, int k);
int gcd(int a, int b);
int *generate_ratio(int a, int b, int c);
int **generate_ratio_list(int n);
unsigned int node_count(node *head);
int **optimum_ratios(node *name);
float share_of_a(int a, int b, int c);
float share_of_b(int a, int b, int c);
float share_of_c(int a, int b, int c);
char *user_input_string(void);
node *create_list(node *new);
node *new_node(Profession *pointer);
Profession *create_field(void);

#endif
