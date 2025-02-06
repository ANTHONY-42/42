#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return;

	t_node *tmp;  // Variable temporaire
	tmp = stack_a->head->next; // Stocke le deuxième élément
	
	stack_a->head->next = tmp->next; // Le premier pointe sur le troisième
	tmp->next = stack_a->head; // Le deuxième devient le premier
	stack_a->head = tmp; // Met `tmp` en tête
}

void    sb(t_stack *stack_b)
{
        if (!stack_b || !stack_b->head || !stack_b->head->next)
                return;

        t_node *tmp;  // Variable temporaire
        tmp = stack_b->head->next; // Stocke le deuxième élément

        stack_b->head->next = tmp->next; // Le premier pointe sur le troisième
        tmp->next = stack_b->head; // Le deuxième devient le premier
        stack_b->head = tmp; // Met `tmp` en tête
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
/*
stack_a->head
   ⬇
  [5] → [3] → [2] → [1] → NULL

t_node *tmp = stack_a->head->next;
stack_a->head = [5] → [3] → [2] → [1] → NULL
tmp           = [3] → [2] → [1] → NULL

stack_a->head->next = tmp->next;
stack_a->head = [5] → [2] → [1] → NULL
tmp           = [3] → [2] → [1] → NULL

tmp->next = stack_a->head;
tmp           = [3] → [5] → [2] → [1] → NULL
stack_a->head = [5] → [2] → [1] → NULL

stack_a->head = tmp;
stack_a->head
   ⬇
  [3] → [5] → [2] → [1] → NULL
*/ 
