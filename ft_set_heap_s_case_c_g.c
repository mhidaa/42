/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c_g.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:17:34 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:43 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_c_g(t_flag *flags, char *heap, char *s)
{
	long long	i;

	i = 0;
	while (i < flags->acc)
	{
		heap[i] = s[i];
		i++;
	}
	heap[i] = '\0';
}
