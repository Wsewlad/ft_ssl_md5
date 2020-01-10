/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:48:13 by vfil              #+#    #+#             */
/*   Updated: 2018/02/12 13:10:53 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft.h"
# include <stdarg.h>

# define BUF_SIZE_PF 64

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
}					t_flags;

typedef struct		s_clr
{
	char			*tmp;
	char			*code;
}					t_clr;

typedef struct		s_spec_elem
{
	t_flags			flags;
	int				fwidth;
	int				precision;
	char			smod[3];
	char			cletter;
}					t_spec_elem;

typedef void		(*t_convert)(t_list **res, t_spec_elem spec, va_list ap);

typedef struct		s_conv
{
	char			letter;
	t_convert		make;
}					t_conv;

int					ft_printf(const char *restrict format, ...);
int					prntf_parse(t_list **res, char *format, va_list ap);
int					check_init_specification(char *format, t_spec_elem \
											*spec, va_list ap);
void				init_spec2zero(t_spec_elem *spec);
void				check_init_flags(char *format, int *step, \
										t_spec_elem *spec);
void				check_init_fwidth(char *format, int *step, \
										t_spec_elem *spec, va_list ap);
void				check_init_precision(char *format, int *step, \
										t_spec_elem *spec, va_list ap);
void				check_init_modifiers(char *format, int *step, \
										t_spec_elem *spec);
void				check_init_specifier(char *format, int *step, \
										t_spec_elem *spec);
int					is_specifier(char c);
int					is_flag(char c);
int					is_modifier(char c);
void				convert_chr(t_list **res, t_spec_elem spec, va_list ap);
void				convert_str(t_list **res, t_spec_elem spec, va_list ap);
void				convert_dibd(t_list **res, t_spec_elem spec, va_list ap);
void				convert_unsigned(t_list **res, t_spec_elem spec, \
									va_list ap);
void				convert_bou(t_list **res, t_spec_elem spec, va_list ap);
void				convert_ptr(t_list **res, t_spec_elem spec, va_list ap);
void				convert_unichr(t_list **res, t_spec_elem spec, va_list ap);
void				convert_unistr(t_list **res, t_spec_elem spec, va_list ap);
int					count_bytes(unsigned int n);
void				get_symbol(t_list **res, unsigned int numb);
void				fill_buf_str(t_list **res, char *str, t_spec_elem spec);
void				fill_buf_chr(t_list **res, char chr);
int					print_buf(t_list **res, int fd);
void				push_str(t_list **head, int len, char *str);
void				push_padding(t_list **head, int len, t_spec_elem spec, \
								int zero);
int					find_ulen(unsigned long long un, int base);
void				push_unumb(t_list **res, int *base_caps, \
								unsigned long long un, t_spec_elem spec);
void				ulltoa_base_buf(t_list **res, unsigned long long un, \
									int *base_caps, t_spec_elem spec);
void				lltoa_buf(t_list **res, long long n, t_spec_elem spec);
int					check_color(t_list **res, char *format, int *fd, \
								va_list ap);

#endif
