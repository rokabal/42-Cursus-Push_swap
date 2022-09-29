/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:27:21 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/16 16:38:57 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*buf;

	buf = malloc(sizeof(t_cmd));
	if (buf)
	{
		buf->cmd = cmd;
		buf->next = NULL;
	}
	return (buf);
}

void	add_cmd(t_cmd **cmds, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	tmp = *cmds;
	if (*cmds == NULL)
		*cmds = new_cmd;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

static void	free_cmds(t_cmd **cmds)
{
	t_cmd	*tmp;

	while (*cmds)
	{
		tmp = *cmds;
		*cmds = (*cmds)->next;
		free(tmp);
	}
}

void	print_cmds(t_cmd **cmds)
{
	t_cmd	*tmp;

	tmp = *cmds;
	while (tmp)
	{
		write(1, tmp->cmd, ft_strlen(tmp->cmd));
		tmp = tmp->next;
	}
	free_cmds(cmds);
}
