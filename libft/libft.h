#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long long	ft_atoi(const char *str);
void		ft_bzero(void *a, size_t lenght);
void		*ft_calloc(size_t number, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memccpy(void *a, const void *b, int c, size_t lenght);
void		*ft_memchr(void *a, int c, size_t lenght);
int			ft_memcmp(const void *a, const void *b, size_t lenght);
void		*ft_memcpy(void *a, const void *b, size_t lenght);
void		*ft_memmove(void *a, const void *b, size_t lenght);
void		*ft_memset(void *a, int b, size_t lenght);
char		*ft_strchr(const char *str, int a);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t lenght);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t lenght);
char		*ft_strnstr(const char *big, const char *little, size_t lenght);
char		*ft_strrchr(const char *str, int a);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, int len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_sign(double num);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char const *ss, char c);
//bonus function
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

#endif 
