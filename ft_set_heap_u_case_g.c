/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_u_case_g.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:43:03 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:06:39 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_u_case_g(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long		i;
	long long		j;
	long long		len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->space_perc_to_next)
		heap[i++] = ' ';
	if (flags->n_minus)
	{
		heap[i++] = '-';
		j++;
	}
	if (flags->acc >= len)
		while (i < width - len)
			heap[i++] = '0';
	if (!(flags->n_zero))
		while (i < width)
			heap[i++] = n_str[j++];
	else
		while (i < width)
			heap[i++] = '0';
	heap[i] = '\0';
}
