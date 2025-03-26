/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabehar <nrabehar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:12:28 by grasoani          #+#    #+#             */
/*   Updated: 2025/03/27 00:15:07 by nrabehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*get_scene(void)
{
	static t_scene	scene;

	return (&scene);
}

int	init_scene(int w, int h, char *win_title)
{
	t_scene	*scene;

	scene = get_scene();
	if (init_win(w, h, win_title))
		return (-1);
	scene->win = get_win();
	return (0);
}

void	destroy_scene(void)
{
	destroy_win();
}
