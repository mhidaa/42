/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c_e.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:11:17 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:32 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_c_e(long long width, char *heap, char *s)
{
	long long		i;
	long long		j;
	long long		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i < (width - len))
		heap[i++] = ' ';
	while (i < width)
		heap[i++] = s[j++];
	heap[i] = '\0';
}
