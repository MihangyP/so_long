/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:17:58 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/11 11:06:14 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	int	pos;

	pos = (y * img->size_len) + (x * (img->bpp / 8));
	*(unsigned int *)(pos + img->addr) = color;
}

void	draw_rect(t_data *data, int pos_x, int pos_y, int width, int height, int color)
{
	int	i;
	int	j;

	i = pos_y;
	while (i < pos_y + height)
	{
		j = pos_x;
		while (j < pos_x + width)
		{
			draw_pixel(&data->img, j, i, color);
			++j;
		}
		++i;
	}
}

void	draw_circle(t_data *data, int center_x, int center_y, float radius, int color)
{
	int x, y;

  // Loop through pixels along the circumference
  	for (float theta = 0; theta < 2 * M_PI; theta += 0.01) {
    // Calculate pixel coordinates based on center, radius, and angle
    x = round(center_x + radius * cos(theta));
    y = round(center_y + radius * sin(theta));

    // Check if pixel is within image boundaries (avoid out-of-bounds access)
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
      // Set pixel color at the calculated coordinates
		draw_pixel(&data->img, x, y, color);
    }
  }
}

void	draw_filled_circle(t_data *data, int center_x, int center_y, float radius, int color) 
{
  int x, y;

  // Loop through pixels within the circle's bounding box
  for (x = center_x - round(radius); x <= center_x + round(radius); x++) {
    for (y = center_y - round(radius); y <= center_y + round(radius); y++) {
      // Calculate distance from center
      float distance = sqrt(pow(x - center_x, 2) + pow(y - center_y, 2));

      // Check if pixel is within the circle (based on distance)
      if (distance <= radius) {
        // Check if pixel is within image boundaries
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
          // Set pixel color at the calculated coordinates
			draw_pixel(&data->img, x, y, color);
        }
      }
    }
  }
}
