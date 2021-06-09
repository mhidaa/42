/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:50:47 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:58:51 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(ssize_t *put_cnt, long long width, \
	char *n_str, char *heap)
{
	*put_cnt += width;
	free(n_str);
	free(heap);
}

static void	ft_print_di(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (flags->flag_minus)
		ft_print_di_with_minus(flags, heap, n_str, width);
	else if (flags->flag_zero && !(flags->flag_minus))
		ft_print_di_with_zero(flags, heap, n_str, width);
	else if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_putstr(heap);
}

static void	ft_set(int n, t_flag *flags, char *n_str, long long *width)
{
	if (n < 0)
		flags->n_minus = 1;
	if (n == 0)
		flags->n_zero = 1;
	*width = 0;
	*width = ft_set_width_for_di(flags, *width, (long long)ft_strlen(n_str));
	if (flags->space_perc_to_next)
		*width += 1;
}

static void	ft_set_heap_n_with_n_minus(t_flag *flags, long long width, \
char *heap, char *n_str)
{
	if (flags->acc_exists || flags->mfw)
	{
		if (!(flags->acc_exists) && flags->mfw)
			ft_set_heap_n_case_a(flags, width, heap, n_str);
		else if (flags->acc_exists && !(flags->mfw))
			ft_set_heap_n_case_b(flags, width, heap, n_str);
		else if (flags->acc_exists && flags->mfw)
		{
			if (flags->acc > flags->mfw)
				ft_set_heap_n_case_c(flags, width, heap, n_str);
			else if (flags->acc < flags->mfw)
			{
				if (flags->acc > (long long)ft_strlen(n_str))
					ft_set_heap_n_case_d(flags, width, heap, n_str);
				else if (flags->acc < (long long)ft_strlen(n_str))
					ft_set_heap_n_case_e(flags, width, heap, n_str);
				else
					ft_set_heap_n_case_h(flags, width, heap, n_str);
			}
			else if (flags->acc == flags->mfw)
				ft_set_heap_n_case_g(flags, width, heap, n_str);
		}
	}
	else
		ft_set_heap_n_case_f(flags, width, heap, n_str);
}

void	ft_case_di(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	int			n;
	char		*heap;
	char		*n_str;
	long long	width;

	n = (int)va_arg(*ap, int);
	n_str = ft_itoa(n);
	if (n_str == NULL || flags->acc == INT_MAX)
		flags->error = 1;
	if (flags->error)
		return ;
	ft_set(n, flags, n_str, &width);
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
	{
		free(n_str);
		flags->error = 1;
		return ;
	}
	if (!(flags->n_minus))
		ft_set_heap_n(flags, width, heap, n_str);
	else
		ft_set_heap_n_with_n_minus(flags, width, heap, n_str);
	ft_print_di(flags, heap, n_str, width);
	ft_free(put_cnt, width, n_str, heap);
}
