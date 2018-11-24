#ifndef HEADER_H
# define HEADER_H

void	ft_bzero(void *s, size_t n);
void	ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t n);
char	*ft_strcpy(char *dst,const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif

