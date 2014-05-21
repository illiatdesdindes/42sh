/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:28:09 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:05:01 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_taylor_sin(double angle)
{
	int			step;
	double		fact;
	double		square_angle;
	double		ret;

	square_angle = angle * angle;
	ret = angle;
	step = 0;
	fact = 1;
	while (step++ < 10)
	{
		angle = -angle * square_angle;
		fact = (fact + fact) * step * (step + step + 1);
		ret = ret + angle / fact;
	}
	return (ret);
}

double			ft_sin(double angle)
{
	int			sign;
	double		pi;

	pi = 3.141592653589793;
	sign = 1;
	if (angle < 0)
	{
		angle = -angle;
		sign = -1;
	}
	if (angle == 0)
		return (0);
	else if (angle == pi / 2)
		return (1);
	else if (angle > pi / 2)
		angle = pi - angle;
	return (sign * ft_taylor_sin(angle));
}
