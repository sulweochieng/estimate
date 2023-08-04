#ifndef FPRTYP_H
#define FPRTYP_H
/* This header file contains all function protypes used in this project */
void add_beg_list(node **head, node *node);
int **allocate_2D_array(unsigned long long int rows, unsigned int cols);
unsigned long long int binomial_coefficient(int n, int k);
void find_max_shares(int ratios[][SALARYLEVELS], int totalCombinations, int
		*aMaxIndex, int *bMaxIndex, int *cMaxIndex);
void free_2D_array(int **array2D, unsigned long long int rowSize);
int gcd(int a, int b);
int *generate_ratio(int a, int b, int c);
int **generate_ratio_list(int n);
unsigned int node_count(node *head);
int **optimum_ratios(node *_name);
float share_of_a(int a, int b, int c);
float share_of_b(int a, int b, int c);
float share_of_c(int a, int b, int c);
char *user_input_string(void);
node *create_list(node *_new);
node *new_node(profession *pointer);
profession *create_field(void);

#endif
