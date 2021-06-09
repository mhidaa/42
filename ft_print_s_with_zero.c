/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_with_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:21:09 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:02:21 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_s_with_zero2(t_flag *flags, char *heap, long long width)
{
	if (flags->dot_exists && !(flags->acc_exists))
	{
		ft_bzero_char_till_i(heap, width);
		ft_putstr(heap);
	}
	else
		ft_putstr(heap);
}

static void	ft_print_s_acc_exists(t_flag *flags, char *heap, \
	char *s, long long width)
{
	long long	len;

	len = ft_strlen(s);
	if (width <= len)
		ft_putstr(heap);
	else if (len <= flags->acc)
	{
		if (width >= flags->acc)
		{
			ft_bzero_char_till_i(heap, (width - len));
			ft_putstr_till_i(heap, (width - len));
			if (len > 0)
				ft_putstr_till_i(s, flags->acc);
		}
		else
		{
			ft_bzero_char_till_i(heap, width);
			ft_putstr(heap);
		}
	}
	else
		ft_putstr(heap);
}

void	ft_print_s_with_zero(t_flag *flags, char *heap, \
	char *s, long long width)
{
	long long	len;

	len = ft_strlen(s);
	if (flags->acc_exists)
		ft_print_s_acc_exists(flags, heap, s, width);
	else
	{
		if (width <= len)
			ft_print_s_with_zero2(flags, heap, width);
		else if (flags->dot_exists && !(flags->acc_exists))
		{
			ft_bzero_char_till_i(heap, width);
			ft_putstr(heap);
		}
		else
		{
			ft_bzero_char_till_i(heap, (width - len));
			ft_putstr_till_i(heap, (width - len));
			ft_putstr(s);
		}
	}
}
