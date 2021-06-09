/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p_case_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:01:50 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:29 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_p_case_c(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long		i;
	long long		j;
	long long		len;

	i = 0;
	j = 2;
	len = ft_strlen(n_str);
	heap[i++] = '0';
	heap[i++] = 'x';
	if (flags->acc + 2 > len)
	{
		while (i < (width - (len - 2)))
			heap[i++] = '0';
		while (i < width)
			heap[i++] = n_str[j++];
	}
	else
	{
		while (i < width)
			heap[i++] = n_str[j++];
	}
	heap[i] = '\0';
}
