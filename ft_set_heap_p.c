/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:43:01 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:53 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_p_case_g(long long width, char *heap)
{
	long long	i;

	i = 0;
	while (i < width - 2)
		heap[i++] = ' ';
	heap[i++] = '0';
	heap[i++] = 'x';
	heap[i] = '\0';
}

void	ft_set_heap_p(t_flag *flags, long long width, char *heap, char *n_str)
{
	if (flags->null && flags->acc_is_zero)
		ft_set_heap_p_case_g(width, heap);
	else if (flags->acc_exists || flags->mfw)
	{
		if (!(flags->acc_exists) && flags->mfw)
			ft_set_heap_p_case_a(width, heap, n_str);
		else if (flags->acc_exists && !(flags->mfw))
			ft_set_heap_p_case_b(flags, width, heap, n_str);
		else if (flags->acc_exists && flags->mfw)
		{
			if (flags->acc >= flags->mfw)
				ft_set_heap_p_case_c(flags, width, heap, n_str);
			else
			{
				if (flags->acc + 2 > (long long)ft_strlen(n_str))
					ft_set_heap_p_case_d(flags, width, heap, n_str);
				else
					ft_set_heap_p_case_e(flags, width, heap, n_str);
			}
		}
	}
	else
		ft_set_heap_p_case_f(width, heap, n_str);
}
