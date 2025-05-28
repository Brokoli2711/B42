/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:56 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/28 13:38:49 by egelma-b         ###   ########.fr       */
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
	size_t	len;

	if (!full_path || !path || !cmd)
		return ;
	if (full_path)
		full_path[0] = '\0';
	len = ft_strlen(path) + ft_strlen(cmd) + 2;
	ft_strlcpy(full_path, path, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, cmd, len);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*env_path;
	char	*full_path;
	int		i;

	env_path = get_env_path(envp);
	if (!cmd || cmd[0] == '\0' || !env_path)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (ft_free_split(paths), NULL);
		write_all_path(full_path, paths[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
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
}

int	show_errors(int *pipefd, int fdin, int fdout, char **argv)
{
	if (fdin == -1)
	{
		printf("%s: %s\n", argv[1], strerror(errno));
	}
	if (fdout == -1)
		return (perror("failed to open outfile"), 1);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	return (0);
}
