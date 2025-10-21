/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:21:45 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 12:25:07 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*s2;
	unsigned int	s_len;

	s_len = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len - 1)
		len = 0;
	if (len > (s_len - start))
		len = s_len - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
