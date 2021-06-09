/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:59:32 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:59 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_a(char *heap, char *s, long long width)
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