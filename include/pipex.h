/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:02:11 by smolines          #+#    #+#             */
/*   Updated: 2024/08/01 15:17:49 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>  

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define ERR_INFILE "no such file or directory"
# define ERR_OUTFILE "permission denied"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipe
{
	int		pipe_child[2];
	pid_t	child1;
	pid_t	child2;
	int		status;
	int		exit_status;
}	t_pipe;

// Libft
char	*ft_strdup(char *s);
char	**ft_split(char const *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strrchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strndup(const char *src, int size);

//Pipex
char	*recup_path(char **envp);
void	*verif_path(char **path_split, char *cmd);

//error
void	ft_error(int error);
void	error_errno(char *nom_fonction);
void	error_cmd(char *nom_fonction);
void	error_cmd_exec(char *nom_fonction);
void	close_pipe(int pipe_one, int pipe_two);

// free
void	free_tab(char **tab);
void	free_cmd(char *cmd_free, char **tab);
void	free1(char *argv, int pipe_child, int exit_nb);
void	free2(char *argv, int pipe_child, int fd);
void	free3(int fd, int pipe_child, char *cmd_free, char *fct_errno);
void	free_all_cmd(char *cmd_one, char *cmd_two);
void	free_cmd_only(char *arg, int fd, int pipe_child);
void	free4(int fd, int pipe_child, char *cmd_free, char *fct_errno);
void	f_err_ch(int pipe_one, int pipe_two, char *nom_fonction);
void	free2b(char *argv, int pipe_child, int fd, int exit_nb);
void	free5(int fd, int pipe_child, char *fct_errno, char *cmd);

//cmd
char	*recup_path(char **envp);
void	*verif_path(char **path_split, char *cmd);
char	**cmd_arg(char *arg);
char	*create_cmd(char **envp, char *arg, int fd, int pipe_child);

#endif
