/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_xX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:45:58 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:28 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_xX(t_flag *flags, long long width, char *heap, char *n_str)
{
	if (flags->acc_exists || flags->mfw)
	{
		if (!(flags->acc_exists) && flags->mfw)
			ft_set_heap_xX_case_a(flags, width, heap, n_str);
		else if (flags->acc_exists && !(flags->mfw))
			ft_set_heap_xX_case_b(flags, width, heap, n_str);
		else if (flags->acc_exists && flags->mfw)
		{
			if (flags->acc > flags->mfw)
				ft_set_heap_xX_case_c(flags, width, heap, n_str);
			else if (flags->acc == flags->mfw)
				ft_set_heap_xX_case_g(flags, width, heap, n_str);
			else if (flags->acc < flags->mfw)
			{
				if (flags->acc >= (long long)ft_strlen(n_str))
					ft_set_heap_xX_case_d(flags, width, heap, n_str);
				else
					ft_set_heap_xX_case_e(flags, width, heap, n_str);
			}
		}
	}
	else
		ft_set_heap_xX_case_f(flags, width, heap, n_str);
}
