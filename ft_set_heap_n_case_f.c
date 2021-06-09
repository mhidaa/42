/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n_case_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:04:35 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:49 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_n_case_f(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;

	i = 0;
	if (flags->space_perc_to_next)
		heap[i++] = ' ';
	while (i < width)
	{
		heap[i] = n_str[i];
		i++;
	}
	heap[i] = '\0';
}
