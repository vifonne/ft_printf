/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:52:38 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/13 19:05:24 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_f_width(t_data *data, int size)
{
	char	*s;
	int i;
	int ac;

	ac = data->accu - size;
	i = data->f_width - size;
	if (i > 0)
		s = ft_strnew(i);
	else
		return ;
	if (data->flags->zero == 1 && data->accu == -1 && data->flags->minus == 0)
		ft_memset(s, 48, i);
	else
		ft_memset(s, 32, i);
	if (data->flags->zero == 1 && ac > 0)
		while (ac-- > 0)
			s[i--] = '0';
	if (data->f_width != 0)
	{
		if (data->flags->minus == 1)
			data->prs->tmp = ft_strdjoin(data->prs->tmp, s);
		else
			data->prs->tmp = ft_strjoind(s, data->prs->tmp);
	}
}

void	ft_accuracy(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = data->prs->tmp;
	while (tmp[i])
	{
		if (i == data->accu)
		{
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_accu_int(t_data *data)
{
	char	*zero;
	size_t	len;

	zero = NULL;
	len = ft_strlen(data->prs->tmp);
	if (data->accu > -1 && len < (size_t)data->accu)
	{
		if (!(zero = ft_strnew(data->accu)))
			exit(0);
		ft_memset((void*)zero, 48, data->accu - len);
		if (!(data->prs->tmp = ft_strdjoind(zero, data->prs->tmp)))
			exit(0);
	}
}
