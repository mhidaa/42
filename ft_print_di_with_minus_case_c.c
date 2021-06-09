/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_minus_case_c.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:39:51 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:22:37 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_di_with_minus_case_c3(t_flag *flags, char *heap, \
	long long width)
{
	if (!(flags->n_minus))
	{
		ft_putstr(&heap[width - flags->acc]);
		ft_putstr_till_i(heap, width - flags->acc);
	}
	else
		ft_putstr(heap);
}

static void	ft_print_di_with_minus_case_c2(t_flag *flags, char *n_str, \
	char *heap, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if ((flags->conv_specifier == 2 || flags->conv_specifier == 3 || \
		flags->conv_specifier == 4) && (flags->acc != width))
	{
		if (len <= flags->acc && flags->acc < width && flags->flag_zero)
			ft_print_di_with_minus_case_c3(flags, heap, width);
		else if (len < flags->acc && flags->acc < width && !(flags->n_minus))
		{
			ft_putstr(&heap[width - flags->acc]);
			ft_putstr_till_i(heap, width - flags->acc);
		}
		else if (flags->n_minus && (len <= flags->acc) && \
			(flags->acc <= flags->mfw))
			ft_putstr(heap);
		else
		{
			ft_putstr(n_str);
			ft_putstr_till_i(heap, width - len);
		}
	}
	else
		ft_putstr(heap);
}

void	ft_print_di_with_minus_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if (flags->n_zero && flags->acc_is_zero)
		ft_putstr(heap);
	else if (len <= flags->acc && flags->acc <= flags->mfw)
		ft_print_di_with_minus_case_c2(flags, n_str, heap, width);
	else if (flags->acc == len && len == flags->mfw)
		ft_putstr(n_str);
	else if (flags->acc <= len && len <= flags->mfw)
	{
		ft_putstr(n_str);
		while (width - len)
		{
			write(1, " ", 1);
			width--;
		}
	}
	else if (flags->acc <= flags->mfw && flags->mfw <= len)
		ft_putstr(n_str);
	else
		ft_putstr(heap);
}
