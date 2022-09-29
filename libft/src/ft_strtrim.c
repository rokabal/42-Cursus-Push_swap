/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:18:57 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/04 18:11:26 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL && end >= start)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
