/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:42:08 by smolines          #+#    #+#             */
/*   Updated: 2024/07/17 19:49:42 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)&(s[s_len]));
	while (s_len)
	{
		if (s[s_len - 1] == (char)c)
			return ((char *)(s + s_len - 1));
		s_len--;
	}
	return (0);
}
