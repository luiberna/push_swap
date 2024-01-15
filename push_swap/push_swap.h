/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:35:35 by luiberna          #+#    #+#             */
/*   Updated: 2024/01/15 14:23:23 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./Libft/libft.h"

typedef struct s_stack
{
    struct s_stack	*next;
    int				content;
    struct s_stack	*bestfriend;
    int				cost;
}                  t_stack;

//verifiers
int     veri_not_nb(char **args);
int     veri_dup(t_stack **stack_a);
int     is_sorted(t_stack **stack_a);

//moves
    //swap
void    swap(t_stack **stack);
void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
    //push
void    push(t_stack **src_stack, t_stack **dest_stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
    //rotate
void    rotate(t_stack **stack);
void    rotate_a(t_stack **stack_a);
void    rotate_b(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
    //rerotate
void    rerotate(t_stack **stack);
void	rerotate_a(t_stack **stack_a);
void    rerotate_b(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

//sort
int     get_len(t_stack *stack_a);
void    sort(t_stack **stack_a, t_stack **stack_b);
void    short_sort(t_stack **stack);
void    push_all_b(t_stack **stack_a, t_stack **stack_b);
int     get_sum(t_stack *curr);
void	go_down(t_stack **stack_a, t_stack *current);
t_stack	*find_small(t_stack *stack_a);
void	final_sort(t_stack **stack_a);

//bestfriend
t_stack *get_bestfriend(t_stack **stack_a, t_stack *stack_b);
void	assign_bestfriend(t_stack **stack_a, t_stack *stack_b);
int     bestfriend_moves_a(t_stack *stack_a, t_stack *curr_b);
int	    bestfriend_moves(t_stack *stack_a, t_stack *stack_b, t_stack *curr_b);

//cost
void	assign_cost(t_stack *stack_a, t_stack **stack_b);
t_stack	*less_cost(t_stack *stack_b);
void	move_down_a(t_stack **stack_a, t_stack *node_b);
void	move_down_b(t_stack **stack_b, t_stack *node_b);
void	move_up_b(t_stack **stack_b, t_stack *node_b);
void	move_stack_a(t_stack **stack_a, t_stack **stack_b);
void	move_less_cost(t_stack **stack_a, t_stack **stack_b);

//free
void	free_stack(t_stack **stack_a);
void free_split(char **args);

#endif