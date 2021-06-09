/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p_case_e.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:08:52 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:42 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_p_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long		i;
	long long		j;
	long long		len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->mfw > len)
	{
		while (i < (width - len))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
	}
	else
		while (i < width)
			heap[i++] = n_str[j++];
	heap[i] = '\0';
}
