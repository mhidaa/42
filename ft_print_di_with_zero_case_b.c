/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_zero_case_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:55:29 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:01:17 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di_with_zero_case_b(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if (flags->acc >= len)
	{
		if (flags->n_minus)
			ft_putstr(heap);
		else
		{
			ft_putstr_till_i(heap, (width - len));
			ft_putstr(n_str);
		}
	}
	else
		ft_putstr(heap);
}
