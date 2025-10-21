/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:41:33 by smolines          #+#    #+#             */
/*   Updated: 2024/07/15 15:26:02 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	sc1 = (unsigned char *) s1;
	sc2 = (unsigned char *) s2;
	while ((sc1[i] || sc2[i]) && (i < n))
	{
		if (sc1[i] != sc2[i])
			return (sc1[i] - sc2[i]);
		i++;
	}
	return (0);
}
