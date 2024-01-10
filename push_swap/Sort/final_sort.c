/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:56:55 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/10 17:00:45 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	go_down(t_stack **stack_a, t_stack *current)
{
	while ((*stack_a) != current)
		rerotate_a(stack_a);
}

t_stack	*find_small(t_stack *stack_a)
{
	t_stack	*curr;

	curr = stack_a;
	while (stack_a != NULL)
	{
		if (curr->content > stack_a->content)
			curr = stack_a;
		stack_a = stack_a->next;
	}
	return (curr);
}

void	final_sort(t_stack **stack_a)
{
	t_stack	*curr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	curr = (*stack_a);
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	curr = (*stack_a);
	while (curr != find_small(*stack_a))
	{
		curr = curr->next;
		n++;
	}
	if (n < i / 2)
	{
		while ((*stack_a) != curr)
			rotate_a(stack_a);
	}
	else
		go_down(stack_a, curr);
}
