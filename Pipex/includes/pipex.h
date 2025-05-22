#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/includes/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

//PIPEX_UTILS
char	*get_command_path(char *cmd, char **envp);
char	*exec_command(char *command, char **envp);

#endif
