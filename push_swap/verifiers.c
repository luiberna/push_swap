/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:49:13 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/23 14:16:33 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	veri_not_nb(char **args)
{
	int		j;
	int		temp_atoi;
	char	*temp_itoa;

	j = 0;
	while (args[j])
	{
		temp_atoi = ft_atoi(args[j]);
		temp_itoa = ft_itoa(temp_atoi);
		if (ft_strncmp(temp_itoa, &args[j][args[j][0] == '+'], \
		ft_strlen(args[j]) - args[j][0] == '+'))
			return (free(temp_itoa), free_split(args), 1);
		else
			j++;
		free(temp_itoa);
	}
	free_split(args);
	return (0);
}

int	veri_dup(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack_a;
	temp = *stack_a;
	while (curr->next != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (curr->content == temp->content)
				return (1);
		}
		curr = curr->next;
		temp = curr;
	}
	return (0);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*curr;

	curr = *stack_a;
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->content < curr->next->content)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}
