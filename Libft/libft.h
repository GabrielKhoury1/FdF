/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:07:47 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 13:23:30 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_list_gnl
{
	char				content;
	struct s_list_gnl	*next;
}t_list_gnl;

int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(char const *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(char const *s1, char const *s2, unsigned int n);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_lstsize(t_list *lst);
int			ft_lstsize_gnl(t_list_gnl *lst);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*get_next_line(int fd);
char		*lst_to_str(t_list_gnl **lst, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list_gnl	*ft_lst_new_char(char content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_back_gnl(t_list_gnl **lst, t_list_gnl *new_node);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstclear_gnl(t_list_gnl **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));

#endif
