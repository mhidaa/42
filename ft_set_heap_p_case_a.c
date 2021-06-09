/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p_case_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:58:49 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:19 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_p_case_a(long long width, char *heap, char *n_str)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i < (width - (long long)ft_strlen(n_str)))
		heap[i++] = ' ';
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}
