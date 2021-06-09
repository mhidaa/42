/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c_c.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:03:30 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:24 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_c_c(t_flag *flags, long long width, \
	char *heap, char *s)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (flags->acc < 0 || flags->acc_is_zero)
	{
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
	else
	{
		while (i < width - flags->acc)
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
}
