/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p_case_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:09:46 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:49 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_p_case_f(long long width, char *heap, char *n_str)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}
