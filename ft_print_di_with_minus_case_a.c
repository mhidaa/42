/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_with_minus_case_a.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:31:24 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:50 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di_with_minus_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if (flags->mfw > len)
	{
		ft_putstr(n_str);
		ft_putstr_till_i(heap, (width - len));
	}
	else
		ft_putstr(heap);
}
