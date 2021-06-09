/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_with_zero_case_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:48:57 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:01:46 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_with_zero_case_a(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if (!(flags->n_minus))
	{
		if (flags->mfw > len)
			ft_putstr(heap);
		else
			ft_putstr(n_str);
	}
	else
	{
		if (flags->mfw > len)
		{
			ft_putstr_till_i(heap, (width - len + 1));
			ft_putstr(&n_str[1]);
		}
		else
			ft_putstr(n_str);
	}
}
