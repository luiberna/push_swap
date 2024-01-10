/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:40:17 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/10 15:42:27 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack		*curr;

	while ((*stack_a) != NULL)
	{
		curr = (*stack_a)->next;
		free ((*stack_a));
		(*stack_a) = curr;
	}
}
