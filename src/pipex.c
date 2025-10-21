/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:52:00 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 15:18:24 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//execute la commande 1 dans enfant 1
int	exec_cmd1(char **argv, char **envp, int *pipe_child)
{
	int		fd1;
	char	**cmd_arg;
	char	*cmd_one;

	close (pipe_child[0]);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		free1(argv[1], pipe_child[1], 1);
	cmd_one = create_cmd (envp, argv[2], fd1, pipe_child[1]);
	if (!cmd_one)
		free2(argv[2], pipe_child[1], fd1);
	if (access(cmd_one, X_OK) == -1)
		free4(fd1, pipe_child[1], cmd_one, argv[2]);
	if (dup2(pipe_child[1], STDOUT_FILENO) == -1)
		return (free3(fd1, pipe_child[1], cmd_one, "dup2"), -1);
	if (dup2(fd1, STDIN_FILENO) == -1)
		return (free3(fd1, pipe_child[1], cmd_one, "dup2"), -1);
	close (pipe_child[1]);
	cmd_arg = ft_split(argv[2], ' ');
	close (fd1);
	if (execve(cmd_one, cmd_arg, envp) == -1)
		perror("exec_cmd1 execve cmd_one");
	free_cmd(cmd_one, cmd_arg);
	exit (-1);
}

//execute la commande 2 dans enfant 2
int	exec_cmd2(char **argv, char **envp, int *pipe_child)
{
	int		fd2;
	char	**cmd_arg;
	char	*cmd_two;

	cmd_two = NULL;
	close (pipe_child[1]);
	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00777);
	if (fd2 == -1)
		free1(argv[4], pipe_child[0], 1);
	cmd_two = create_cmd (envp, argv[3], fd2, pipe_child[0]);
	if (!cmd_two)
		free2b(argv[3], pipe_child[0], fd2, 127);
	if (access(cmd_two, X_OK) == -1)
		free5(fd2, pipe_child[0], argv[3], cmd_two);
	if (dup2(pipe_child[0], STDIN_FILENO) == -1)
		return (free3(fd2, pipe_child[0], cmd_two, "dup2"), -1);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		return (free3(fd2, pipe_child[0], cmd_two, "dup2"), -1);
	cmd_arg = ft_split(argv[3], ' ');
	close (fd2);
	close (pipe_child[0]);
	if (execve(cmd_two, cmd_arg, envp) == -1)
		error_errno("execve_cmd2");
	free_cmd(cmd_two, cmd_arg);
	exit (-1);
}

static int	wait_for_child(pid_t child2)
{
	int	status;
	int	exit_status;

	exit_status = 0;
	status = 0;
	while (errno != ECHILD)
	{
		if (wait(&status) == child2)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	return (exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_child[2];
	pid_t	child1;
	pid_t	child2;
	int		exit_status;

	exit_status = 0;
	if (argc != 5)
		ft_error(1);
	if (pipe(pipe_child) == -1)
		return (perror("pipe_pipe_child1"), -1);
	child1 = fork();
	if (child1 == -1)
		return (f_err_ch(pipe_child[0], pipe_child[1], "main fork1"), -1);
	else if (child1 == 0)
		exec_cmd1(argv, envp, pipe_child);
	child2 = fork();
	if (child2 == -1)
		return (f_err_ch(pipe_child[0], pipe_child[1], "main fork2"), -1);
	else if (child2 == 0)
		exec_cmd2(argv, envp, pipe_child);
	close_pipe(pipe_child[1], pipe_child[0]);
	exit_status = wait_for_child(child2);
	return (exit_status);
}
