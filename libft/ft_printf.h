/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:48:57 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 18:59:39 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct		s_printf_conv
{
	int						length;
	int						precision;
	int						width;
	int						capitalized;
	char					type;
	char					import_type;
	int						base;
	int						parameter;
	int						*flags;
	unsigned int			conv_length;
	char					*string;
	char					*orig;
	int						chars;
	char					*exponent;
	char					*widthstr;
	char					*final;
	char					*prefix;
}					t_pfconv;

typedef struct		s_string_list
{
	unsigned long long			size;
	char						type;
	char						*string;
	struct s_string_list		*next;
	t_pfconv					*conversion;
}					t_slist;

int					ft_printf(char *str, ...);
t_pfconv			*ft_new_pfconv(void);
t_pfconv			*ft_conversion_parsing(char **str);
char				*ft_parse_parameter(char *str, t_pfconv *new);
char				*ft_parse_flags(char *str, t_pfconv *new);
char				*ft_parse_width(char *str, t_pfconv *new);
char				*ft_parse_precision(char *str, t_pfconv *new);
char				*ft_parse_length(char *str, t_pfconv *new, char **options);
char				*ft_parse_type(char *str, t_pfconv *new, char **types);
char				**ft_build_types(void);
char				**ft_build_lengths(void);
void				ft_eval_unum(t_pfconv *current, unsigned long long num);
void				ft_eval_num(t_pfconv *current, long long num);
void				ft_eval_float(t_pfconv *current, long double num);
void				ft_eval_str(t_pfconv *current, char *str);
void				ft_eval_char(t_pfconv *current, unsigned int c);
char				*ft_float_standard(t_pfconv *current, \
long double num, int base);
char				*ft_float_normal(t_pfconv *current, \
long double num, int base);
char				**ft_float_build_invalids(int capitalized);
char				*ft_itoa_float(long double num, int base);
void				ft_import_type(t_pfconv *current);
void				ft_printf_int(t_pfconv *current, va_list args);
void				ft_printf_double(t_pfconv *current, va_list args);
void				ft_printf_other(t_pfconv *current, va_list args);
void				ft_precision(t_pfconv *current);
void				ft_precision_string(t_pfconv *current);
void				ft_precision_integer(t_pfconv *current);
void				ft_precision_float(t_pfconv *current, \
unsigned int precision);
void				ft_width(t_pfconv *current);
t_slist				*ft_new_tslist(t_slist *previous, void *content, \
unsigned long long size);
void				ft_parse_for_conversions(char *str, t_slist **first);
int					ft_evaluate_conversions(t_slist *first, va_list args);
void				ft_signed_integer_types(t_pfconv *current, va_list args);
void				ft_unsigned_integer_types(t_pfconv *current, va_list args);
void				ft_floating_types(t_pfconv *current, va_list args);
int					ft_other_types(t_pfconv *current, va_list args);
int					ft_ptr(t_pfconv *current, va_list args);
void				ft_flags(t_pfconv *current);
void				ft_mod(t_pfconv *current);
void				ft_plus(t_pfconv *current);
void				ft_hash(t_pfconv *current);
void				ft_zero(t_pfconv *current);
void				ft_space(t_pfconv *current);
void				ft_minus(t_pfconv *current);
void				ft_e(t_pfconv *current, long double num);
char				**ft_build_types_alt(void);
char				**ft_build_types_two(void);
void				ft_free_types(char **types);
void				ft_free_types_alt(char **types);
void				ft_free_types_two(char **types);
void				ft_free_lengths(char **lengths);
void				ft_finalize(t_pfconv *current);
void				ft_finalize_c(t_pfconv *current);
void				ft_finalize_special(t_pfconv *current);
void				ft_finalize_wstr(t_pfconv *current);
void				ft_import_options(t_pfconv *current, va_list args);
void				ft_freeconv(t_pfconv *current);

#endif
