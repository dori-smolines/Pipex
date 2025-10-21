/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:01:55 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 15:18:52 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//recupere PATH dans les variables env
char	*recup_path(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) != 0)
			i++;
		else
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
	}
	return (NULL);
}

//test l'existence des commamdes
void	*verif_path(char **path_split, char *cmd)
{
	int		i;
	char	*verif;
	char	*temp;

	i = 0;
	verif = NULL;
	if (!path_split)
		return (NULL);
	while (path_split[i])
	{
		temp = ft_strjoin(path_split[i], "/");
		verif = ft_strjoin(temp, cmd);
		free(temp);
		if (access (verif, F_OK | X_OK) == 0)
			return (verif);
		free(verif);
		i++;
	}
	return (NULL);
}

//creer l'adresse absolue de la commade sans argument
char	*create_cmd(char **envp, char *arg, int fd, int pipe_child)
{
	char	**path_split;
	char	*path;
	char	*cmd;
	char	**cmd_only;

	cmd = NULL;
	cmd_only = ft_split(arg, ' ');
	if (cmd_only[0] == NULL)
	{
		free_tab(cmd_only);
		free_cmd_only (arg, fd, pipe_child);
	}	
	if (ft_strrchr(cmd_only[0], '/') != 0)
		cmd = ft_strndup(cmd_only[0], ft_strlen(cmd_only[0]));
	else
	{
		path = recup_path(envp);
		path_split = ft_split(path, ':');
		free(path);
		cmd = verif_path(path_split, cmd_only[0]);
		free_tab(path_split);
	}
	free_tab(cmd_only);
	return (cmd);
}

//creer le char** des arguments de la commande
char	**cmd_arg(char *arg)
{
	char	**cmd_arg;

	cmd_arg = ft_split(arg, ' ');
	return (cmd_arg);
}

void	close_pipe(int pipe_one, int pipe_two)
{
	close (pipe_one);
	close (pipe_two);
}
