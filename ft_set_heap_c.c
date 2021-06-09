/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:00:12 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:21 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_c(char *heap, long long width)
{
	long long	i;

	i = 0;
	if (width == 0)
		heap[i] = '\0';
	else
	{
		while (i < width - 1)
			heap[i++] = ' ';
		heap[i] = '\0';
	}
}
