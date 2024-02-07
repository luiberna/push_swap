/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:35:18 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/07 16:45:22 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int argc, char **argv)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	**result;

	i = 1;
	temp3 = ft_calloc(1, sizeof(char));
	while (i < argc)
	{
		temp1 = ft_strjoin(argv[i], " ");
		temp2 = ft_strjoin(temp3, temp1);
		free(temp1);
		free(temp3);
		temp3 = temp2;
		i++;
	}
	result = ft_split(temp3, ' ');
	free(temp3);
	return (result);
}

t_stack	*create_node(char *args)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->real = ft_atoi(args);
	node->content = 0;
	node->next = NULL;
	return (node);
}

t_stack	*set_stack(int argc, char **argv)
{
	t_stack	*start_a;
	t_stack	*curr;
	char	**args;
	int		i;

	i = 1;
	args = get_args(argc, argv);
	start_a = create_node(args[0]);
	curr = start_a;
	while (args[i])
	{
		curr->next = create_node(args[i]);
		curr = curr->next;
		i++;
	}
	free_split(args);
	return (start_a);
}

void	print_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		ft_putnbr_fd(curr->content, 1);
		if ((curr->next != NULL))
			ft_putchar_fd(' ', 1);
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*start_a;
	t_stack	*start_b;
	char	**args;

	start_b = NULL;
	if (argc < 2)
		return (0);
	args = get_args(argc, argv);
	if (!args || !args[0])
		return (free(args), 1);
	if (veri_not_nb(args))
		return (write(2, "Error\n", 6));
	start_a = set_stack(argc, argv);
	normalize_nb(start_a);
	stack_a = &start_a;
	stack_b = &start_b;
	if (veri_dup(stack_a))
		return (free_stack(stack_a), write(2, "Error\n", 6));
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	else
		sort(stack_a, stack_b);
	free_stack(stack_a);
}
