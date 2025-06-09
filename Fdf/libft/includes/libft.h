/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:43:57 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/09 14:29:04 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2097152
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, int base);
int		ft_lstsize(t_list *lst);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new_list);
void	ft_lstadd_back(t_list **lst, t_list *new_list);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(void	*str, int c, size_t n);
void	*ft_calloc(size_t nmb, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char	*dest, const char *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *src, const char	*str, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	**ft_split(const char *s, char c);
void	ft_free_split(char **ptr);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Printf
int		ft_printf(const char *str, ...);	
int		ft_print_char(int c);
int		ft_print_int(int c);
int		ft_print_hex_pointer(void *ptr);
int		ft_print_mhex_num(unsigned int num);
int		ft_print_mayorhex_num(unsigned int num);
int		ft_print_percent(void);
int		ft_print_string(char *str);
int		ft_print_unsigned_int(int c);
//Printf utils
int		len_hex(unsigned long long iptr);
int		point_to_hex(unsigned long long iptr);
int		num_to_hex(unsigned int num);

//Get_next_line
char	*get_next_line(int fd);
void	end_node(t_list **list, t_list *last_node, int i);
int		make_list(t_list **list, int fd);
void	add_node(t_list **list, char *str);
//Get_next_line_utils
t_list	*find_last_node(t_list *list);
bool	check_newline(t_list **list);
char	*extract_line(t_list *head);
//frees Get_next_line
char	*ft_free_strjoin(char *sline, char *tmp);
void	free_list(t_list **list);
#endif
