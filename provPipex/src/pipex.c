/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:59:50 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 14:12:31 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char	*exec_command(char *command, char **envp)
{
	char	**args;
	char	*full_path;

	args = ft_split(command, ' ');
	if (!args)
	{
		ft_free_split(args);
		return (NULL);
	}
	full_path = (char *)get_command_path(args[0], envp);
	if (!full_path)
	{
		perror("command not found");
		ft_free_split(args);
		return (NULL);
	}
	printf("Executing: %s\n", full_path);
	execve(full_path, args, envp);
	perror("execve");
	free(full_path);
	ft_free_split(args);
	exit(1);
}

static void	child1(int *pipefd, int fdin, char *command, char **envp)
{
	dup2(fdin, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fdin);
	exec_command(command, envp);
}

static	void	fork_error(int *pid, int n, int *pipefd)
{
	if (pid[n] < 0)
	{
		perror("fork");
		free(pipefd);
		free(pid);
		exit (1);
	}
}

static void	child2(int *pipefd, int fdout, char *command, char **envp)
{
	dup2(pipefd[0], 0);
	dup2(fdout, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fdout);
	exec_command(command, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		*pipefd;
	pid_t	*pid;
	int		fdin;
	int		fdout;

	pipefd = malloc(sizeof(int) * 2);
	pid = malloc(sizeof(pid_t) * 2);
	if (!pipefd || argc != 5)
		return (free(pipefd), free(pid), 1);
	if (!pid)
		return (free(pid), free(pipefd), 1);
	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (show_errors(pipefd, fdin, fdout, argv) != 0)
		return (free(pid), 1);
	pid[0] = fork();
	if (pid[0] == 0)
		child1(pipefd, fdin, argv[2], envp);
	fork_error(pid, 0, pipefd);
	pid[1] = fork();
	if (pid[1] == 0)
		child2(pipefd, fdout, argv[3], envp);
	fork_error(pid, 1, pipefd);
	return (close_and_wait(pipefd, pid, fdin, fdout), 0);
}
