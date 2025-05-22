#include "../includes/pipex.h"
#include <sys/types.h>

//This function gives you the root path of the environment.
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

//We use this function to write all the path along with the '/' character and with the command at the end.
void	write_all_path(char *full_path, char *path, char *cmd)
{
	ft_strlcpy(full_path, path, 1000);
	ft_strlcat(full_path, "/", 1000);
	ft_strlcat(full_path, cmd, 1000);
}

//We will get the original path of the command we want to use, using the functions above this one.
char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*env_path;
	char	*full_path;
	int	i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	env_path = get_env_path(envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		write_all_path(full_path, paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}
