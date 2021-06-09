/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:53:19 by mhida             #+#    #+#             */
/*   Updated: 2021/06/07 03:59:10 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_flag
{
	int			flag_zero;
	int			flag_minus;
	long long	mfw;
	long long	acc;
	int			acc_exists;
	int			conv_specifier;
	int			n_minus;
	int			n_zero;
	int			dot_exists;
	int			acc_is_zero;
	int			null;
	int			acc_star_minus;
	int			acc_star_exists;
	int			space_perc_to_next;
	int			error;
}	t_flag;

int			ft_printf(const char *format, ...);
const char	*ft_judge_successive_percent(const char *format, ssize_t *put_cnt);
void		ft_init_flags(t_flag *flags);
size_t		ft_judge_flag(t_flag *flags, const char *format, size_t fmt_i);
size_t		ft_judge_mfw(t_flag *flags, const char *format, \
	size_t fmt_i, va_list *ap);
size_t		ft_judge_acc(t_flag *flags, const char *format, \
	size_t fmt_i, va_list *ap);
size_t		ft_judge_conv_specifier(t_flag *flags, const char *format, \
	size_t fmt_i);
void		ft_diverge_case(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_c(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_s(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_p(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_di(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_u(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_xX(t_flag *flags, va_list *ap, ssize_t *put_cnt);
void		ft_case_percent(t_flag *flags, ssize_t *put_cnt);
void		ft_case_o(t_flag *flags, va_list *ap, ssize_t *put_cnt);
long long	ft_set_width(t_flag *flags, long long width);
long long	ft_set_width_for_di(t_flag *flags, long long width, long long len);
void		ft_set_heap_s(t_flag *flags, long long width, char *heap, char *s);
void		ft_set_heap_s_case_a(char *heap, char *s, long long width);
void		ft_set_heap_s_case_b(t_flag *flags, long long width, \
	char *heap, char *s);
void		ft_set_heap_s_case_c(t_flag *flags, long long width, \
	char *heap, char *s);
void		ft_set_heap_s_case_c_a(long long width, char *heap, char *s);
void		ft_set_heap_s_case_c_b(t_flag *flags, long long width, \
	char *heap, char *s);
void		ft_set_heap_s_case_c_c(t_flag *flags, long long width, \
	char *heap, char *s);
void		ft_set_heap_s_case_c_d(long long width, char *heap, char *s);
void		ft_set_heap_s_case_c_e(long long width, char *heap, char *s);
void		ft_set_heap_s_case_c_f(long long width, char *heap, char *s);
void		ft_set_heap_s_case_c_g(t_flag *flags, char *heap, char *s);
void		ft_set_heap_s_case_d(char *heap, char *s, long long width);
void		ft_set_heap_n(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_a(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_b(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_c(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_f(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_print_c_with_minus(char *heap, char c);
void		ft_print_c_with_zero(long long width, char c);
void		ft_print_c_with_no_flag(char *heap, char c);
void		ft_print_s_with_minus(t_flag *flags, char *heap, \
	char *s, long long width);
void		ft_print_s_with_zero(t_flag *flags, char *heap, \
	char *s, long long width);
void		ft_print_di_with_minus(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_di_with_minus_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_di_with_minus_case_b(t_flag *flags, char *heap, \
	char *n_str);
void		ft_print_di_with_minus_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_di_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_di_with_zero_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_di_with_zero_case_b(t_flag *flags, char *heap, \
	char *n_str, long long width);
char		*ft_uitooct_str(unsigned int ui, t_flag *flags);
char		*ft_uitohex_str(unsigned int ui, t_flag *flags);
char		*ft_ulltohex_str(unsigned long long ull, t_flag *flags);
long long	ft_set_width_for_p(t_flag *flags, long long width, long long len);
void		ft_set_heap_p(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_p_case_a(long long width, char *heap, char *n_str);
void		ft_set_heap_p_case_b(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_p_case_c(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_p_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_p_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_p_case_f(long long width, char *heap, char *n_str);
void		ft_set_heap_c(char *heap, long long width);
void		ft_set_heap_n_case_g(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_n_case_h(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_print_percent_with_no_flag(char *heap);
void		ft_print_percent_with_minus(char *heap);
void		ft_print_percent_with_zero(long long width);
void		ft_print_p_with_minus(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_p_with_minus_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_p_with_minus_case_b(t_flag *flags, char *heap, \
	char *n_str);
void		ft_print_p_with_minus_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_p_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_p_with_zero_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_p_with_zero_case_b(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_set_heap_u(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_a(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_b(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_c(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_f(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_u_case_g(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_print_u_with_minus(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_u_with_minus_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_u_with_minus_case_b(t_flag *flags, char *heap, \
	char *n_str);
void		ft_print_u_with_minus_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_u_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_u_with_zero_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_print_u_with_zero_case_b(t_flag *flags, char *heap, \
	char *n_str, long long width);
void		ft_set_heap_xX(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_a(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_b(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_c(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_f(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_set_heap_xX_case_g(t_flag *flags, long long width, \
	char *heap, char *n_str);
void		ft_bzero_char_till_i(char *s, size_t i);
int			ft_isdigit(int n);
char		*ft_itoa(int n);
void		ft_putstr_till_i(char *s, size_t i);
void		ft_putstr(char *s);
size_t		ft_strlen(const char *str);
int			ft_toupper(int n);
char		*ft_uitoa(unsigned int ui);
char		*ft_strtoupper(char *s);
ssize_t		ft_strchr_i(const char *str, char c);

#endif
