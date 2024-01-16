/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:14:29 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/16 15:41:10 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **src_stack, t_stack **dest_stack)
{
	t_stack	*temp;

	temp = (*src_stack)->next;
	(*src_stack)->next = *dest_stack;
	*dest_stack = *src_stack;
	*src_stack = temp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
}
