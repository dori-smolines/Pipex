/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:58:05 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 14:07:08 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int error)
{
	if (error == 1)
		write (2, "Error\nInvalid number of arguments\n", 34);
	exit(1);
}

void	error_errno(char *nom_fonction)
{
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, " : ", 3);
	write(2, nom_fonction, strlen(nom_fonction));
	write(2, "\n", 1);
}

void	error_cmd(char *nom_fonction)
{
	write(2, "Command not found", 17);
	write(2, " : ", 3);
	write(2, nom_fonction, strlen(nom_fonction));
	write(2, "\n", 1);
}

void	error_cmd_exec(char *nom_fonction)
{
	write(2, "Permission denied", 17);
	write(2, " : ", 3);
	write(2, nom_fonction, strlen(nom_fonction));
	write(2, "\n", 1);
}

void	free5(int fd, int pipe_child, char *fct_errno, char *cmd)
{
	error_cmd_exec (fct_errno);
	free(cmd);
	close(pipe_child);
	close(fd);
	exit (126);
}
