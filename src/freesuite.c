/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesuite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:58:05 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 14:22:49 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd_only(char *arg, int fd, int pipe_child)
{
	error_cmd (arg);
	close(fd);
	close (pipe_child);
	exit(127);
}

void	free_all_cmd(char *cmd_one, char *cmd_two)
{
	if (cmd_one)
		free (cmd_one);
	if (cmd_two)
		free (cmd_two);
}

void	f_err_ch(int pipe_one, int pipe_two, char *nom_fonction)
{
	close (pipe_one);
	close (pipe_two);
	error_errno (nom_fonction);
}

void	free3(int fd, int pipe_child, char *cmd_free, char *fct_errno)
{
	error_errno (fct_errno);
	if (pipe_child)
		close(pipe_child);
	if (fd)
		close(fd);
	if (cmd_free)
		free (cmd_free);
}

void	free4(int fd, int pipe_child, char *cmd_free, char *fct_errno)
{
	error_cmd_exec (fct_errno);
	close(pipe_child);
	close(fd);
	if (cmd_free)
		free (cmd_free);
	exit (126);
}
