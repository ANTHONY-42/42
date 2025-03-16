#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


// 	STRUCTURE
typedef struct	s_node
{
	int		value;
	int		index;
	struct	s_node	*next;
} t_node;

typedef struct	s_stack
{
	t_node	*start;
	int	size;
} t_stack;

//----------------------------------------------------------------------
//	PARSING
//----------------------------------------------------------------------

//	PARSING
void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b);
int	check_arg(char **tab);

// 	CHECK_ARG
int	check_arg(char **tab);
int	check_number(char **tab, char *arg, int i);
int	is_number(char *str);
int	is_int(char *str);
int	is_double(char **tab, int nbr, int i);

//	FT_SPLIT
char	**ft_split(char *str);
char	*epurstr(char *str);
int	count_word(char *str);
int	count_letter(char *str);
int	is_sep(char c);

//	CREATE_STACK
t_stack	*create_stack_a(char **av);
t_stack	*create_stack_b(void);
t_node	*create_node(int value);
void	add_node(t_stack *stack, t_node *new_node);

//----------------------------------------------------------------------
//	PUSH_SWAP
//----------------------------------------------------------------------

//	PUSH_SWAP
void	push_swap(t_stack *stack_a, t_stack *stack_b);
int	is_sorted(t_stack *stack_a);

//	SORT_5
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack_a);
int	min(t_stack *stack);

//	RADIX_SORT
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	index_stack(t_stack *stack);
int	count_bits(int size);

//	K_SORT
void    k_sort(t_stack *stack_a, t_stack *stack_b);
void    pb_min(t_stack *stack_a, t_stack *stack_b);
void    pa_max(t_stack *stack_a, t_stack *stack_b);
int     pos_max(t_stack *stack_a, int max);
int    define_tolerance(t_stack *stack_a);

//----------------------------------------------------------------------
//	OPERATION
//----------------------------------------------------------------------

//	SWAP
int     swap(t_stack *stack);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);

//	PUSH
int     push(t_stack *stack_1, t_stack *stack_2);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);

//	ROTATE
int     rotate(t_stack *stack);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);

//	REVERSE_ROTATE
int     reverse_rotate(t_stack *stack);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);


//	UTILS
long	ft_atol(const char *str);
int	ft_atoi(const char *str);
void	print_stack(t_stack *stack);
int	ft_strlen(char *str);

//----------------------------------------------------------------------
//	FREE
//----------------------------------------------------------------------

void free_full(t_stack **stack_a, t_stack **stack_b);
void    free_stack(t_stack **stack);
void    free_tab(char **tab);

#endif
