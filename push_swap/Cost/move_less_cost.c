/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_less_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:48:48 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/16 15:18:48 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_down_a(t_stack **stack_a, t_stack *node_b)
{
	while ((*stack_a) != node_b->bestfriend)
	{
		rerotate_a(stack_a);
	}
}

void	move_down_b(t_stack **stack_b, t_stack *node_b)
{
	while ((*stack_b) != node_b)
	{
		rerotate_b(stack_b);
	}
}

void	move_up_b(t_stack **stack_b, t_stack *node_b)
{
	while ((*stack_b) != node_b)
	{
		rotate_b(stack_b);
	}
}

void	move_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		n;
	t_stack	*curr;

	curr = (*stack_a);
	n = 0;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	curr = (*stack_a);
	while (curr != (*stack_b)->bestfriend)
	{
		curr = curr->next;
		n++;
	}
	if (n <= i / 2)
	{
		while ((*stack_a) != (*stack_b)->bestfriend)
			rotate_a(stack_a);
	}
	else
		move_down_a(stack_a, (*stack_b));
}

void	move_less_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr;
	int		i;
	int		n;

	n = 0;
	i = 0;
	curr = (*stack_b);
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	curr = (*stack_b);
	while (curr != less_cost((*stack_b)))
	{
		curr = curr->next;
		n++;
	}
	if (n <= i / 2)
		move_up_b(stack_b, less_cost((*stack_b)));
	else
		move_down_b(stack_b, less_cost((*stack_b)));
	move_stack_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
