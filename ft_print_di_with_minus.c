/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:44:43 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:01:08 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_di_with_minus_case_d2(t_flag *flags, long long width, \
	char *heap, long long len)
{
	long long	i;

	i = 0;
	if (flags->conv_specifier == 6 || flags->conv_specifier == 7)
		ft_putstr(heap);
	else
	{
		while (i++ < flags->acc - len)
			write(1, "0", 1);
		ft_putstr(&heap[width - len]);
		ft_putstr_till_i(heap, width - flags->acc);
	}
}

static void	ft_print_di_with_minus_case_d(t_flag *flags, char *n_str, \
	long long width, char *heap)
{
	long long	len;

	len = ft_strlen(n_str);
	if (width)
	{
		if (flags->acc_is_zero)
			while (width--)
				write(1, " ", 1);
		else if (len < flags->acc && flags->acc < width)
			ft_print_di_with_minus_case_d2(flags, width, heap, len);
		else if (len == flags->acc && flags->acc < width && \
			(flags->conv_specifier == 6 || flags->conv_specifier == 7))
			ft_putstr(heap);
		else if (flags->acc < width)
		{
			ft_putstr(&heap[width - len]);
			while (width - len)
			{
				write(1, " ", 1);
				width--;
			}
		}
		else if (flags->acc >= width)
			ft_putstr(heap);
	}
}

void	ft_print_di_with_minus(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (flags->dot_exists && flags->n_zero)
		ft_print_di_with_minus_case_d(flags, n_str, width, heap);
	else
	{
		if (!(flags->acc_exists) && flags->mfw)
			ft_print_di_with_minus_case_a(flags, heap, n_str, width);
		if (flags->acc_exists && !(flags->mfw))
			ft_print_di_with_minus_case_b(flags, heap, n_str);
		if (flags->acc_exists && flags->mfw)
			ft_print_di_with_minus_case_c(flags, heap, n_str, width);
		if (!(flags->acc_exists) && !(flags->mfw))
			ft_putstr(n_str);
	}
}
