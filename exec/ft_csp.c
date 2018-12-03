/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 14:22:53 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

char	*ft_char(t_data *data)
{
	printf("ft_char\n");
	return (data->prs->tmp);
}

char	*ft_string(t_data *data)
{
	printf("ft_string\n");
	return (data->prs->tmp);
}

char	*ft_ptr(t_data *data)
{
	printf("ft_ptr\n");
	return (data->prs->tmp);
}