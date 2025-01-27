#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // À supprimer pour la version finale

typedef struct s_stack
{
    int *array;
    int size;
    int top;
} t_stack;

// Prototypes des fonctions
void check_arguments(int argc, char **argv);
t_stack *initialize_stack(char **argv);
void sa(t_stack *stack_a);
void sort_small_stack(t_stack *stack_a, t_stack *stack_b);
int is_sorted(t_stack *stack);
void error_and_exit(char *message);

#endif
