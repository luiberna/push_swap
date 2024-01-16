/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:40:17 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/16 15:19:51 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_stack **stack_a)
{
	t_stack	*curr;

	while ((*stack_a) != NULL)
	{
		curr = (*stack_a)->next;
		free((*stack_a));
		(*stack_a) = curr;
	}
}
