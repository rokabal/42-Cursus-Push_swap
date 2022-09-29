/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:49:24 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/29 16:15:12 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_bits(int size)
{
	int	bits;
	int	result;

	result = 2;
	bits = 1;
	while (result < size)
	{
		result *= 2;
		++bits;
	}
	return (bits);
}

static int	rotate(t_ps *ps, t_list **head, int i)
{
	int		rot;
	t_list	*tmp;

	rot = 0;
	tmp = ps->indexed;
	while (tmp != NULL)
	{
		if ((tmp->content) & (1 << i))
			++rot;
		else
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		while (rot > 0)
		{
			if (*head == NULL)
				*head = ps->indexed;
			ft_ra(ps, 0);
			--rot;
		}
		return (1);
	}
	return (0);
}

void	radix_sort(t_ps *ps)
{
	int		i[2];
	t_list	*head;

	i[0] = get_bits(ps->size);
	i[1] = -1;
	while (++i[1] < i[0])
	{
		head = NULL;
		while (rotate(ps, &head, i[1]))
			ft_pb(ps);
		while (head->content != ps->indexed->content)
			ft_ra(ps, 0);
		head = NULL;
		while (ft_lstsize(ps->stack_b) && ps->stack_b != head)
		{
			if (((ps->stack_b->content >> (i[1] + 1)) & 1) || i[1] == i[0] -1)
				ft_pa(ps);
			else
			{
				if (head == NULL)
					head = ps->stack_b;
				ft_rb(ps, 0);
			}
		}
	}
}
