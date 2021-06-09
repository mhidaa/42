/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_with_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:21:03 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:02:17 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_s_acc_exists(t_flag *flags, char *heap, \
	char *s, long long width)
{
	long long	len;

	len = ft_strlen(s);
	if (flags->acc >= len)
	{
		ft_putstr(s);
		ft_putstr_till_i(heap, (width - len));
	}
	else if (flags->acc_is_zero)
		ft_putstr(heap);
	else
	{
		if (flags->acc_star_minus)
		{
			ft_putstr(s);
			ft_putstr_till_i(heap, width - len);
		}
		else if (flags->acc == width)
			ft_putstr(heap);
		else
		{
			ft_putstr(&heap[width - flags->acc]);
			ft_putstr_till_i(heap, width - flags->acc);
		}
	}
}

void	ft_print_s_with_minus(t_flag *flags, char *heap, \
	char *s, long long width)
{
	long long	len;

	len = ft_strlen(s);
	if (flags->acc_exists)
		ft_print_s_acc_exists(flags, heap, s, width);
	else if (flags->dot_exists)
		ft_putstr(heap);
	else
	{
		ft_putstr(s);
		ft_putstr_till_i(heap, (width - len));
	}
}
