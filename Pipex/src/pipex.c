#include "../includes/pipex.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Execute the command that is passed by parameter.
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
	printf("Ejecutando: %s\n", full_path);
	execve(full_path, args, envp);
	perror("execve");
	free(full_path);
	ft_free_split(args);
	exit(1);
}

//If the file does not exist, this function will be called to create it using the bin command 'touch'.
int	create_file(char *file_name, char **envp)
{
	pid_t pid;
	char **args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
	{
		free(args);
		return (0);
	}
	args[0] = "touch";
	args[1] = file_name;
	args[2] = NULL;

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/touch", args, envp);
		perror("execve");
		free(args);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork");
	free(args);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	*pipefd;
	pid_t	pid1;
	pid_t	pid2;
	int	fdin;
	int	fdout;

	pipefd = malloc(sizeof(int) * 2);
	if (!pipefd)
	{
		free(pipefd);
		return (0);
	}
	if (argc != 5)
	{
		free(pipefd);
		return (0);
	}
	fdin = open(argv[1], O_RDONLY);
	if(fdin == -1)
			printf("%s: %s\n", argv[1], strerror(errno));	
	else if(access(argv[1], R_OK) == 0)
		printf("%s is accessable in read mode\n", argv[1]);
	fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	if(fdout == -1)
	{
		create_file(argv[4], envp);
		fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
		if (fdout == -1)
		{
			free(pipefd);
			return (perror("failed to open outfile"), 1);
		}
	}
	else if(access(argv[4], W_OK) == 0)
		printf("%s is accessable in write mode\n", argv[4]);
	if(pipe(pipefd) == -1)
	{
		free(pipefd);
		return (perror("pipe"), 1);
	}

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fdin, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fdin);
		close(fdout);
		exec_command(argv[2], envp);
	}
	else if (pid1 < 0)
	{
		perror("fork");
		free(pipefd);
		exit (1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fdin);
		close(fdout);
		exec_command(argv[3], envp);
	}
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
//waitpid epera a que la fork haya acabado antes de acabar el programa.
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(pipefd);
	return (0);
}

