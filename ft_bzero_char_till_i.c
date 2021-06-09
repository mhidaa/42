/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_char_till_i.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:54:48 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:58:27 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero_char_till_i(char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		s[j++] = '0';
}