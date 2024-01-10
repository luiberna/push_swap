/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:12:56 by luiberna          #+#    #+#             */
/*   Updated: 2023/12/21 18:41:17 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rerotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *curr;

    curr = (*stack);
    while (curr->next->next)
        curr = curr->next;
    temp = curr->next;
    curr->next = NULL;
    temp->next = *stack;
    *stack = temp;
}
void	rerotate_a(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	rerotate(stack_a);
}

void	rerotate_b(t_stack **stack_b)
{
	write(1, "rrb\n", 4);
	rerotate(stack_b);
}
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 4);
	rerotate(stack_a);
	rerotate(stack_b);
}