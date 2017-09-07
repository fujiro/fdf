/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:37:23 by elcarrei          #+#    #+#             */
/*   Updated: 2017/08/14 02:57:27 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					*ft_range(int min, int max);
int					ft_abs(int n);
int					ft_atoi(char *str);
int					ft_ascii_value(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					get_next_line(int const fd, char **line);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
int					ft_strnequ(const char *s1, const char *s2, int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(char *src);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strmap(const char *str, char (*f) (char));
char				*ft_strmapi\
					(const char *str, char (*f) (unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr\
					(const char *str, const char *to_find, size_t size);
char				*ft_strrev(char *str);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strtrim(const char *str);
char				**ft_strsplit(char const *str, char c);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_strclr(char *str);
void				ft_strdel(char **ap);
void				ft_striter(char *str, void (*f) (char *));
void				ft_striteri(char *str, void (*f) (unsigned int, char *));
void				ft_sort_params(int ac, char **av);
void				ft_swap(int *a, int *b);

#endif
