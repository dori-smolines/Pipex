/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:58:05 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 14:03:53 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(const char *src, int size)
{
	char	*src2;
	int		i;

	src2 = (char *)malloc(sizeof(char) * (size + 1));
	if (src2 == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		count = 0;
	else if (str[0] != c)
		count = 1;
	while (str[i])
	{
		if ((str[i] == c) && ((str[i + 1] != c) && (str[i + 1] != '\0')))
			count++;
		i++;
	}
	return (count);
}

static int	get_size(const char *str, char c)
{
	int	taille;

	taille = 0;
	while ((str[taille] != c) && (str[taille] != '\0'))
		taille++;
	return (taille);
}

static void	ft_split_content(char **split, char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			split[j] = ft_strndup(&str[i], get_size(&str[i], c));
			if (!split[j])
			{
				while (j > 0)
					free (split[j--]);
				free (split);
				return ;
			}
			j++;
			i = get_size(&str[i], c) + i;
		}
		else
			i++;
	}
	split[j] = NULL;
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		nb_words;

	if (str == 0)
		return (NULL);
	nb_words = count_words(str, c);
	split = (char **)malloc (sizeof(char *) * (nb_words + 1));
	if (split == NULL)
		return (0);
	ft_split_content(split, str, c);
	return (split);
}
