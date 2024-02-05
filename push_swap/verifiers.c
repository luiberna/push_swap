/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:49:13 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/05 17:40:59 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n(char *a, char *b)
{
	while (*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if (*a == '+')
		a++;
	if (!a[0])
		return (1);
	return (ft_strncmp(a, b, ft_strlen(a)));
}

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
		if (check_n(args[j], temp_itoa))
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

void	normalize_nb(t_stack *stack_a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = stack_a;
		while (tmp2)
		{
			if (tmp->real > tmp2->real)
				tmp->content++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
