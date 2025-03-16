#include "push_swap.h"

void free_tab(char **tab)
{
    int i;

    if (!tab) return;  // ✅ Vérifie que `tab` est valide

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        tab[i] = NULL;  // ✅ Évite les doubles free
        i++;
    }
    free(tab);
}

void free_stack(t_stack **stack)
{
    t_node *current;
    t_node *tmp;

    if (!stack || !*stack)
    {
        printf("⚠️ free_stack() appelé avec stack NULL !\n");
        return;
    }

    current = (*stack)->start;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*stack);
    *stack = NULL;  // ✅ Évite un double free
}
/*
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *tmp;

    if (!stack) return;  // ✅ Vérifie que `stack` est valide

    current = stack->start;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    free(stack);
}
*/
/*
void free_full(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a)
        free_stack(stack_a);
    if (stack_b)
        free_stack(stack_b);
}*/

void free_full(t_stack **stack_a, t_stack **stack_b, **tab)
{
	if (tab && *tab)
		free_tab(tab);

	if (stack_a && *stack_a)
		free_stack(stack_a);
	
	if (stack_b && *stack_b)
		free_stack(stack_b);
}
