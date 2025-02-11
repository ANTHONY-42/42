#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // À supprimer pour la version finale
# include <limits.h> // Pour INT_MAX et INT_MIN

// STRUCTURE POUR LA LISTE CHAÎNÉE
typedef struct s_node
{
	int             value;
	int		index;
	struct s_node   *next;
} t_node;

typedef struct s_stack
{
	t_node  *head;
	int     size;
} t_stack;

// ✅ PROTOTYPES DES FONCTIONS

// check_number.c
int     is_number(char *str);
int     is_int(char *str);
int     is_double(int nb, t_stack *a);
int     number_valid(char *argv, t_stack *a);

// parsing.c
t_stack *init_stack_a(char **argv);
t_stack *create_stack_b(int size);
t_node  *create_node(int value);
void    add_node_back(t_stack *stack, t_node *new_node);
void    free_stack(t_stack *stack);
int     is_sorted(t_stack *stack);

// utils.c
int     ft_atoi(const char *str);
long    ft_atol(const char *str);
void	print_stack(t_stack *stack);

// opérations (à implémenter)
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

// sort min
void sort_3(t_stack *stack_a);
void sort_4_5(t_stack *stack_a, t_stack *stack_b);
int find_min(t_stack *stack);

#endif
