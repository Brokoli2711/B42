/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:56 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:36:28 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/types.h>

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	write_all_path(char *full_path, char *path, char *cmd)
{
	ft_strlcpy(full_path, path, 1000);
	ft_strlcat(full_path, "/", 1000);
	ft_strlcat(full_path, cmd, 1000);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*env_path;
	char	*full_path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	env_path = get_env_path(envp);
	paths = ft_split(env_path, ':');
	if (!paths || !env_path)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		write_all_path(full_path, paths[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
		i++;
	}
	return (ft_free_split(paths), NULL);
}

void	close_and_wait(int *pipefd, pid_t *pid, int fdin, int fdout)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fdin);
	close(fdout);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	free(pid);
	free(pipefd);
}

int	show_errors(int *pipefd, int fdin, int fdout, char **argv)
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
