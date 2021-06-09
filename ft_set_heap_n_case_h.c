/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n_case_h.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 04:53:13 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:59 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_n_case_h2(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->space_perc_to_next)
		heap[i++] = ' ';
	if (flags->n_zero && flags->acc_is_zero)
		len = 0;
	heap[i++] = '-';
	j++;
	heap[i++] = '0';
	while (i < len + 1)
		heap[i++] = n_str[j++];
	while (i < width)
		heap[i++] = ' ';
	heap[i] = '\0';
}

void	ft_set_heap_n_case_h(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->flag_minus && flags->n_minus)
		ft_set_heap_n_case_h2(flags, width, heap, n_str);
	else
	{
		if (flags->space_perc_to_next)
			heap[i++] = ' ';
		if (flags->n_zero && flags->acc_is_zero)
			len = 0;
		while (i < (width - (len + 1)))
			heap[i++] = ' ';
		heap[i++] = '-';
		j++;
		while (i < (width - (len - 1)))
			heap[i++] = '0';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}
