/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:53:04 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/23 18:18:04 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_len(t_stack *stack_a)
{
	int		len;
	t_stack	*curr;

	len = 0;
	curr = stack_a;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

int	get_sum(t_stack *curr)
{
	long long int	sum;

	sum = 0;
	while (curr)
	{
		sum = sum + (curr->content);
		curr = curr->next;
	}
	return (sum);
}

void	short_sort(t_stack **stack)
{
	if ((*stack)->content > ((*stack)->next)->content)
		swap_a(stack);
	if (((*stack)->next)->content > (((*stack)->next)->next)->content)
	{
		if ((((*stack)->next)->next)->content > (*stack)->content)
		{
			rerotate_a(stack);
			swap_a(stack);
		}
		else
			rerotate_a(stack);
	}
}

void	push_all_b(t_stack **stack_a, t_stack **stack_b)
{
	int			len;
	int			avg;
	long long	sum;

	len = get_len(*stack_a);
	while (len > 3)
	{
		sum = get_sum(*stack_a);
		avg = (sum / len);
		if ((*stack_a)->content < avg)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		len = get_len(*stack_a);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	(void)stack_b;
	len = get_len(*stack_a);
	if (len == 2)
		swap_a(stack_a);
	else if (len == 3)
		short_sort(stack_a);
	else
	{
		push_all_b(stack_a, stack_b);
		short_sort(stack_a);
		while ((*stack_b) != NULL)
		{
			assign_bestfriend(stack_a, (*stack_b));
			assign_cost((*stack_a), stack_b);
			move_less_cost(stack_a, stack_b);
		}
	}
	final_sort(stack_a);
}
