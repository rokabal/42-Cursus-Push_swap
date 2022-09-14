/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:49:24 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/14 14:40:27 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_pow(int base, int exp)
{
	int	result;

	result = base;
	while (--exp > 0)
		result *= base;
	return (result);
}

int	rotate(t_list **indexed, t_list **head, int i)
{
	int		rot;
	t_list	*tmp;

	rot = 0;
	tmp = *indexed;
	while (tmp != NULL)
	{
		if ((tmp->content) & (1 << i))
			rot++;
		else
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		while (rot > 0)
		{
			if (*head == NULL)
				*head = *indexed;
			ft_ra(indexed, 0);
			rot--;
		}
		return (1);
	}
	return (0);
}

void	radix_sort(t_list **indexed, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	t_list	*head;

	size = ft_lstsize(*indexed);
	i = 3;
	while (ft_pow(2, i) <= size)
		i++;
	j = -1;
	while (++j < i)
	{
		head = NULL;
		while (rotate(indexed, &head, j))
			ft_pb(indexed, stack_b);
		while (head->content != (*indexed)->content)
			ft_ra(indexed, 0);
		while (ft_lstsize(*stack_b))
			ft_pa(indexed, stack_b);
	}
}
