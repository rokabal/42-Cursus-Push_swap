/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:38:07 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 14:42:35 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rra(t_list **stack_a, int rrr)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	tmp->next = NULL;
	if (!rrr)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b, int rrr)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
	if (!rrr)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
