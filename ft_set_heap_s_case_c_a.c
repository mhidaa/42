/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:52:47 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:11 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_c_a(long long width, char *heap, char *s)
{
	long long	i;

	i = 0;
	while (i < width)
	{
		heap[i] = s[i];
		i++;
	}
	heap[i] = '\0';
}
