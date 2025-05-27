/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:58:01 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 12:59:46 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

//PIPEX_UTILS
char	*get_command_path(char *cmd, char **envp);
char	*exec_command(char *command, char **envp);
int		show_errors(int *pipefd, int fdin, int fdout, char **argv);
void	close_and_wait(int *pipefd, pid_t *pid, int fdin, int fdout);

#endif
