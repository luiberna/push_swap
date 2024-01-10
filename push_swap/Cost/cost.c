/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:08:21 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/05 15:47:46 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_cost(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*curr_b;

	curr_b = *stack_b;
	while (curr_b != NULL)
	{
		curr_b->cost = bestfriend_moves(stack_a, *stack_b, curr_b);
		curr_b = curr_b->next;
	}
}

t_stack	*less_cost(t_stack *stack_b)
{
	t_stack	*curr;

	curr = stack_b;
	while (stack_b != NULL)
	{
		if (curr->cost > stack_b->cost)
			curr = stack_b;
		stack_b = stack_b->next;
	}
	return (curr);
}
