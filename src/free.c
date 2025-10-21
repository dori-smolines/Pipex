/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:58:05 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 14:05:24 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_cmd(char *cmd_free, char **tab)
{
	free(cmd_free);
	free_tab (tab);
}

void	free1(char *argv, int pipe_child, int exit_nb)
{
	error_errno (argv);
	close(pipe_child);
	exit (exit_nb);
}

void	free2(char *argv, int pipe_child, int fd)
{
	error_cmd (argv);
	close(pipe_child);
	close(fd);
}

void	free2b(char *argv, int pipe_child, int fd, int exit_nb)
{
	error_cmd (argv);
	close(pipe_child);
	close(fd);
	exit (exit_nb);
}
