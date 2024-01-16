/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestfriend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:31:07 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/10 16:34:03 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_bestfriend(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*curr;
	t_stack	*curr2;

	curr = (*stack_a);
	while (curr != NULL)
	{
		if (curr->content > stack_b->content)
		{
			curr2 = curr;
			while (curr2 != NULL)
			{
				if (curr->content > curr2->content
					&& curr2->content > stack_b->content)
					curr = curr2;
				curr2 = curr2->next;
			}
			return (curr);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	assign_bestfriend(t_stack **stack_a, t_stack *stack_b)
{
	while (stack_b != NULL)
	{
		stack_b->bestfriend = get_bestfriend(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

int	bestfriend_moves_a(t_stack *stack_a, t_stack *curr_b)
{
	int		i;
	int		j;
	t_stack	*curr;

	curr = stack_a;
	i = 0;
	j = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	curr = stack_a;
	while (curr != curr_b->bestfriend)
	{
		curr = curr->next;
		j++;
	}
	if (j < i / 2)
		return (j);
	else
		return (i - j);
}

int	bestfriend_moves(t_stack *stack_a, t_stack *stack_b, t_stack *curr_b)
{
	int		i;
	int		n;
	int		j;
	t_stack	*curr;

	curr = stack_b;
	i = 0;
	n = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	curr = stack_b;
	while (curr != curr_b && curr != NULL)
	{
		curr = curr->next;
		n++;
	}
	j = bestfriend_moves_a(stack_a, curr_b);
	if (n <= i / 2)
		return (n + j);
	else
		return ((i - n) + j);
}
