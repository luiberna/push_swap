/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:08:14 by luiberna          #+#    #+#             */
/*   Updated: 2023/12/18 18:13:39 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_stack **stack)
{
    t_stack *temp1;
    t_stack *temp2;

    temp1 = (*stack);
    temp2 = (*stack)->next;
    *stack = (*stack)->next->next;
    temp1->next = *stack;
    *stack = temp1;
    temp2->next = *stack;
    *stack = temp2;
}
void swap_a(t_stack **stack_a)
{
    write(1, "sa\n", 3);
    swap(stack_a);
}
void swap_b(t_stack **stack_b)
{
    write(1, "sb\n", 3);
    swap(stack_b);
}
void ss(t_stack **stack_a, t_stack **stack_b)
{
    write(1, "ss\n", 3);
    swap(stack_a);
    swap(stack_b);
}