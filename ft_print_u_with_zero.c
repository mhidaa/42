/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_with_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:44:40 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:29:38 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_u_with_zero_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;
	long long	i;

	i = 0;
	len = ft_strlen(n_str);
	if (flags->acc_star_minus)
	{
		ft_bzero_char_till_i(heap, (width - len));
		ft_putstr(heap);
	}
	else if (flags->acc_is_zero && flags->n_zero)
	{
		while (i++ < width)
			write(1, " ", 1);
	}
	else
		ft_putstr(heap);
}

void	ft_print_u_with_zero(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	if (!(flags->acc_exists) && flags->mfw)
		ft_print_u_with_zero_case_a(flags, heap, n_str, width);
	if (flags->acc_exists && !(flags->mfw))
		ft_print_u_with_zero_case_b(flags, heap, n_str, width);
	if (flags->acc_exists && flags->mfw)
		ft_print_u_with_zero_case_c(flags, heap, n_str, width);
	if (!(flags->acc_exists) && !(flags->mfw))
		ft_putstr(n_str);
}
