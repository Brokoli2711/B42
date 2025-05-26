/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:59:50 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/26 15:13:42 by egelma-b         ###   ########.fr       */
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
	exec_command(command, envp);
}

static void	child2(int *pipefd, int fdout, char *command, char **envp)
{
	dup2(pipefd[0], 0);
	dup2(fdout, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_command(command, envp);
}

static int	show_errors(int *pipefd, int fdin, int fdout, char **argv)
{
	if (fdin == -1)
		printf("%s: %s\n", argv[1], strerror(errno));
	else if (access(argv[1], R_OK) == 0)
		printf("%s is accessable in read mode\n", argv[1]);
	if (fdout == -1)
	{
		free(pipefd);
		return (perror("failed to open outfile"), 1);
	}
	else if (access(argv[4], W_OK) == 0)
		printf("%s is accessable in write mode\n", argv[4]);
	if (pipe(pipefd) == -1)
	{
		free(pipefd);
		return (perror("pipe"), 1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		*pipefd;
	pid_t	pid1;
	pid_t	pid2;
	int		fdin;
	int		fdout;

	pipefd = malloc(sizeof(int) * 2);
	if (!pipefd || argc != 5)
	{
		free(pipefd);
		return (0);
	}
	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (show_errors(pipefd, fdin, fdout, argv) != 0)
		return (0);
	pid1 = fork();
	if (pid1 == 0)
		child1(pipefd, fdin, argv[2], envp);
	else if (pid1 < 0)
	{
		perror("fork");
		free(pipefd);
		exit (1);
	}
	pid2 = fork();
	if (pid2 == 0)
		child2(pipefd, fdout, argv[4], envp);
	else if (pid2 < 0)
	{
		perror("fork");
		free(pipefd);
		exit (1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(fdin);
	close(fdout);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(pipefd);
	return (0);
}
