/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_zero.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:44:40 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:20:38 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_xX_with_zero_case_c2(char *heap, long long width, \
	long long len)
{
	long long	i;

	i = 0;
	write(1, "-", 1);
	while (i < width - len)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr(&heap[i + 1]);
}

static void	ft_print_xX_with_zero_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;
	long long	i;

	len = ft_strlen(n_str);
	i = 0;
	if (len >= flags->acc && flags->acc < 0)
	{
		if (flags->flag_zero)
		{
			ft_bzero_char_till_i(heap, width - len);
			ft_putstr(heap);
		}
		else
			ft_putstr(heap);
	}
	else if (flags->n_minus)
		ft_print_xX_with_zero_case_c2(heap, width, len);
	else if (flags->acc_is_zero && flags->n_zero)
	{
		while (i++ < width)
			write(1, " ", 1);
	}
	else
		ft_putstr(heap);
}

static void	ft_print_di_with_zero_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;
	long long	i;

	len = ft_strlen(n_str);
	i = 0;
	if (flags->acc_is_zero)
		ft_putstr(heap);
	else if (len >= flags->acc && flags->acc > 0)
		ft_putstr(heap);
	else if (flags->acc <= len && len < width)
	{
		write(1, "-", 1);
		while (i++ < width - len)
			write(1, "0", 1);
		ft_putstr(&n_str[1]);
	}
	else
		ft_putstr(heap);
}

void	ft_print_di_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (flags->dot_exists && flags->n_zero && \
		!(flags->conv_specifier == 6 || flags->conv_specifier == 7))
		ft_putstr(heap);
	else
	{
		if (!(flags->acc_exists) && flags->mfw)
			ft_print_di_with_zero_case_a(flags, heap, n_str, width);
		else if (flags->acc_exists && !(flags->mfw))
			ft_print_di_with_zero_case_b(flags, heap, n_str, width);
		else if (flags->acc_exists && flags->mfw && flags->n_minus)
			ft_print_di_with_zero_case_c(flags, heap, n_str, width);
		else if ((flags->acc_exists && flags->mfw) && \
			(flags->conv_specifier == 6 || flags->conv_specifier == 7))
			ft_print_xX_with_zero_case_c(flags, heap, n_str, width);
		else if (flags->acc_exists && flags->mfw)
			ft_putstr(heap);
		else if (!(flags->acc_exists) && !(flags->mfw))
			ft_putstr(n_str);
	}
}
