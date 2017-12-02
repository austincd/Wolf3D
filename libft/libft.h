/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:33:01 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 17:25:25 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_numcount(const char *s);
int				ft_strclen(const char *s, char c);
void			ft_swap(int *a, int *b);
int				*ft_atoi_array(char *s);
uintmax_t		ft_diff(intmax_t alpha, intmax_t beta);
intmax_t		ft_mean(intmax_t alpha, intmax_t beta);
uintmax_t		ft_ihighest_ju(uintmax_t *array, uintmax_t array_size);
uintmax_t		ft_highest_ju(uintmax_t *array, uintmax_t array_size);
uintmax_t		ft_ilowest_ju(uintmax_t *array, uintmax_t array_size);
uintmax_t		ft_lowest_ju(uintmax_t *array, uintmax_t array_size);
uintmax_t		ft_charcount(char *str, char c);
void			**ft_arraydup(void **input);
void			ft_arraytrim(void ***array);
char			**ft_check_strs(char **input_strs, \
void *(*alpha)(char *str), int *(*beta)(void *ret_val));
uintmax_t		ft_replacebyte(void *mem, uintmax_t size, \
unsigned char alpha, unsigned char beta);
uintmax_t		ft_replacechar(char *str, unsigned char alpha, \
unsigned char beta);
uintmax_t		ft_factorial(uintmax_t num);
void			ft_uintmax_rotate(uintmax_t *array, uintmax_t size, \
uintmax_t num_rots);
void			ft_uintmax_revrotate(uintmax_t *array, uintmax_t size, \
uintmax_t num_rots);
void			ft_parraycat(void **array, void *ptr);
int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memrchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(char *str);
uintmax_t		ft_wstrlen(wchar_t *wstr);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strnchr(const char *s, int c, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putcutf8_fd(char *c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
int				ft_utf8width(unsigned char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void(*f)(char*));
void			ft_striteri(char *s, void(*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char(*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
char			*ft_ntoa(uintmax_t val, unsigned int base, short sign);
char			*ft_itoa_base(intmax_t val, int base);
char			*ft_itoa_float(long double num, int base);
void			ft_putchar(unsigned int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(unsigned int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_passchr(char *str, unsigned char c);
int				ft_delimstrlen(char *str, char c);
int				ft_numlen(int num);
int				ft_delimcount(char *str, unsigned char c);
char			*ft_delimcountto(char *str, unsigned char c, int index);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list*new);
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
void			ft_foreach(int *tab, int length, void (*f)(int));
int				ft_str_is_alpha(char *str);
int				ft_isthere_var(char *str, char var, int (*f)(char, char), \
int n);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_restrcat(char **dst, char *src);
char			*ft_restrccat(char **dst, char *src, char c);
char			*ft_restrsub(char **str, char *strtwo, \
unsigned int start, size_t len);
long long		*ft_longlongcat(long long *array, long long val);
int				ft_open_file(char *file_path);
int				get_next_line(int fd, char **line);
long long		ft_next_square(long long number);
long long		ft_next_sqrt(long long number);
long long		ft_how_many_char(char *str, char c);
int				ft_strequ_multi(char *str, char **table, int num);
int				ft_find_replace(char **p_big, char *p_little, char *p_new);
char			ft_lowercase(char c);
void			*ft_read_file(int fd, long long offset, long long size);
char			*ft_strndup(char *str, long long len);
char			*ft_strcdup(char *str, char c);
int				ft_get_next_n_lines(int fd, int n, char **line);
void			ft_shift_data(long long fd, long long offset, long long size, \
long long shift);
void			ft_make_room(long long fd, long long to_add, long long offset);
int				ft_create_file(char *filename);
void			ft_write_file(int fd, void *data, long long size);
unsigned long	ft_char_expand(unsigned long c);
void			ft_charcat(char *str, char c);
char			*ft_utoa_base(unsigned long long num, unsigned int base);
char			*ft_strtcdup(char *str, char c);
long double		ft_power(long long power, long long base);
long double		ft_floatmod(long double alpha, long double beta);
char			*ft_basefloat(long double num, int base);
char			*ft_ftoa(long double num);
char			*ft_strichr(const char *s, int c);
void			ft_strdel_plus(char **str);
intmax_t		ft_rememcat(void **dst, void *src, uintmax_t \
dstsz, uintmax_t srcsz);
uintmax_t		ft_absval(intmax_t num);
void			**ft_combine_arrays(void ***arrays);
uintmax_t		ft_arraysize(void **array);
char			**ft_uniq_strs(char **set, uintmax_t size);
void			ft_copy_uniq_strs(char **dst, char **src, uintmax_t size);
void			**ft_arraymap(void **input, void *(*f)(void *ptr));
void			**ft_arraymapin(void **input, void *(*f)(void *ptr));
char			**ft_strsmap(char **input, char *(*f)(char *ptr));
char			**ft_strsmapin(char **input, char *(*f)(char *ptr));

#endif
