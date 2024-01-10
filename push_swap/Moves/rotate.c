/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:50:01 by luiberna          #+#    #+#             */
/*   Updated: 2023/12/21 18:46:36 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *curr;
    t_stack *temp;

    curr = (*stack);
    temp = (*stack);
    (*stack) = (*stack)->next;
    if(!((*stack)->next))
        (*stack)->next = temp;
    else
    {
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
    temp->next = NULL;
}
void rotate_a(t_stack **stack_a)
{
    write(1, "ra\n", 3);
    rotate(stack_a);
}
void rotate_b(t_stack **stack_b)
{
    write(1, "rb\n", 3);
    rotate(stack_b);
}
void rr(t_stack **stack_a, t_stack **stack_b)
{
    write(1, "rr\n", 3);
    rotate(stack_a);
    rotate(stack_b);
}
