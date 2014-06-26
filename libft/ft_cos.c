/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:21:48 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 16:58:37 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_taylor_cos(double angle)
{
	int			step;
	double		fact;
	double		square_angle;
	double		ret;

	square_angle = angle * angle;
	angle = 1;
	step = 0;
	fact = 1;
	ret = 1;
	while (step++ < 10)
	{
		angle = -angle * square_angle;
		fact = (fact + fact) * step * (step + step - 1);
		ret = ret + angle / fact;
	}
	return (ret);
}

double			ft_cos(double angle)
{
	int			sign;
	double		pi;

	pi = 3.141592653589793;
	sign = 1;
	if (angle < 0)
		angle = -angle;
	if (angle == 0)
		return (1);
	else if (angle == pi / 2)
		return (0);
	else if (angle > pi / 2)
	{
		angle = pi - angle;
		sign = -1;
	}
	return (sign * ft_taylor_cos(angle));
}
