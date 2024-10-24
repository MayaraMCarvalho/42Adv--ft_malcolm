/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:56 by macarval          #+#    #+#             */
/*   Updated: 2024/10/24 17:17:44 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	valid_args(t_data	*data)
{
	if (!valid_ip(data->source_ip) || !valid_ip(data->target_ip)
		|| !valid_mac(data->source_mac) || !valid_mac(data->target_mac))
		return (false);
	return (true);
}

int	valid_ip(const char *ip)
{
	char	**list;
	int		i;
	int		num;

	list = ft_split(ip, '.');
	if (counter(list) < 4)
		return (ip_error(ip));
	i = -1;
	while (list[++i])
	{
		num = ft_atoi(list[i]);
		if (num < 0 || num > 255)
			return (ip_error(ip));
	}
	return (true);
}

int	valid_mac(const char *mac)
{
	char	**list;
	int		i;

	i = 0;
	if (ft_strlen(mac) != 17)
		return (mac_error(mac));
	list = ft_split(mac, ':');
	if (counter(list) < 6)
		return (mac_error(mac));
	while (list[++i])
	{
		if (ft_strlen(list[i]) != 2)
			return (mac_error(mac));
	}
	return (true);
}
