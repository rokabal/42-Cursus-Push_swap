/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:17:24 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 23:31:17 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_smallest(t_list **stack)
{
	int		smallest;
	t_list	*tmp;

	smallest = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

void	index_lst(t_list **stack)
{
	t_list	*index;

	return ;
}
