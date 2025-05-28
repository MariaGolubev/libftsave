/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:38:48 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:44:16 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/select.h>
# include <unistd.h>

# ifndef MAX_FD
#  define MAX_FD	1024
# endif

typedef struct s_ptrlist
{
	void				*ptr;
	struct s_ptrlist	*next;
}						t_ptrlist;

typedef struct s_ctx
{
	t_ptrlist			*ptrs;
	int					fds[MAX_FD];
	int					allocated;
}						t_ctx;

char					**ft_ctxsplit(t_ctx *ctx, const char *src, char c);
char					**ft_split(const char *src, char c);
char					*ft_ctxitoa(t_ctx *ctx, int n);
char					*ft_ctxstrdup(t_ctx *ctx, const char *s1);
char					*ft_ctxstrjoin(t_ctx *ctx, const char *s1,
							const char *s2);
char					*ft_ctxstrmapi(t_ctx *ctx, const char *s,
							char (*f)(unsigned int, char));
char					*ft_ctxstrtrim(t_ctx *ctx, const char *src,
							const char *set);
char					*ft_ctxsubstr(t_ctx *ctx, const char *src,
							unsigned int start, size_t len);
char					*ft_itoa(int n);
char					*ft_itoa_str(char *str, int n, size_t len);
char					*ft_strdup(const char *s1);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strmapi(const char *s, char (*f)(unsigned int,
								char));
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char					*ft_strrchr(const char *s, int c);
char					*ft_strtrim(const char *src, const char *set);
char					*ft_substr(const char *src, unsigned int start,
							size_t len);
int						ft_atoi(const char *str);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_open(const char *path, int flags, mode_t mode);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_toupper(int c);
int						ft_tolower(int c);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlen(const char *s);
ssize_t					ft_putchar_fd(char c, int fd);
ssize_t					ft_putendl_fd(const char *s, int fd);
ssize_t					ft_putnbr_fd(int n, int fd);
ssize_t					ft_putstr_fd(const char *s, int fd);
t_ctx					*ft_ctx(void);
t_ptrlist				*ft_ptrlist_new(void *ptr);
void					*ft_calloc(size_t count, size_t size);
void					*ft_ctxcalloc(t_ctx *ctx, size_t count, size_t size);
void					*ft_ctxmalloc(t_ctx *ctx, size_t size);
void					*ft_malloc(size_t size);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					ft_close(int fd);
void					ft_ctxdestroy(t_ctx *ctx);
void					ft_destroy(void);
void					ft_ctxpanic(t_ctx *ctx, const char *msg);
void					ft_ctxclose(t_ctx *ctx, int fd);
void					ft_ctxexit(t_ctx *ctx, int status);
void					ft_ctxfree(t_ctx *ctx, void *ptr);
void					ft_exit(int status);
void					ft_free(void *ptr);
void					ft_panic(const char *msg);
void					ft_ptrlist_dellone(t_ptrlist **ptrlist, void *ptr);
void					ft_ptrlist_destroy(t_ptrlist *ptrlist);
void					ft_striteri(char *str, void (*fn)(unsigned int,
								char *));
int						ft_ptrlist_prepend(t_ptrlist **ptrlist, void *ptr);
int						ft_memcmp(const void *src1, const void *src2, size_t n);
void					*ft_memchr(const void *src, int c, size_t n);
int						ft_ctxpipe(t_ctx *ctx, int *fds);
int						ft_pipe(int *fds);
int						ft_ctxdup(t_ctx *ctx, int fd);
int						ft_ctxdup2(t_ctx *ctx, int fd, int fd2);
int						ft_dup(int fd);
int						ft_dup2(int fd, int fd2);

#endif
