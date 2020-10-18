/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:48:07 by torange           #+#    #+#             */
/*   Updated: 2020/10/18 17:41:04 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

void	render_figure_color(SDL_Rect figure, int r, int g, int b, int a, size_t type)
{
	SDL_SetRenderDrawColor(g_Renderer, r, g , b, a);
	if (type == 1)
		SDL_RenderDrawRect(g_Renderer, &figure);
	else if (type == 2)
		SDL_RenderFillRect(g_Renderer, &figure);
}

int		change_window_size(int resize)
{
	if (resize > 0)
	{
			g_width += 1920 * 0.009;
			g_height += 1080 * 0.009;
	}
	else if (resize < 0)
	{
			g_width -= 1920 * 0.009;
			g_height -= 1080 * 0.009;
	}
	SDL_SetWindowSize(g_Window, g_width, g_height);
	SDL_SetWindowPosition(g_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	return 0;
}

void	playersColor(int playerNum, SDL_Rect *cwArena, int num)
{
	switch (playerNum)
	{
	case 1:
		render_figure_color(cwArena[num], MEMORY_1, FULL);
		break;
	case 2:
		render_figure_color(cwArena[num], MEMORY_2, FULL);
		break;
	case 3:
		render_figure_color(cwArena[num], MEMORY_3, FULL);
		break;
	case 4:
		render_figure_color(cwArena[num], MEMORY_4, FULL);
		break;
	default:
		break;
	}
}

void	initCwArena()
{
	int num = 0;
	int currentChampStart = 0;
	int currentChampSize = 0;
	int currentPlayerNum = 1;

	SDL_Rect cwArena[4096];
	for (int i = 0; i < 64; ++i)
	{
		for (int j = 0; j < 64; ++j, ++num)
		{
			cwArena[num].w = SCREEN_WIDTH / 100 * 0.5;
			cwArena[num].h = cwArena[num].w;
			cwArena[num].x = SCREEN_WIDTH * 0.164 + (i * 13);
			cwArena[num].y = SCREEN_HEIGHT * 0.1165 + (j * 13);
			if (currentChampStart >= num && currentChampSize > num - currentChampStart)
				playersColor(currentPlayerNum, cwArena, num);
			else if ()
				playersColor(0, cwArena, num);
		}
	}

	// while (i < vm->players_num)
	// {
	// 	location = MEM_SIZE / vm->players_num * i;
	// 	vm->players[i]->location = location;
	// 	ft_memcpy(&vm->arena[location], &vm->players[i]->instr, \
	// 			vm->players[i]->isntr_size);
	// 	i++;
	// }

}

void	paint_window()
{
	SDL_SetRenderDrawColor(g_Renderer, RIGHT);
	SDL_RenderClear(g_Renderer);


	SDL_SetRenderDrawColor(g_Renderer, MEMORY_3);
	initCwArena();
	SDL_Rect outlineRect = {SCREEN_WIDTH * 0.163, SCREEN_HEIGHT * 0.1143, SCREEN_WIDTH / 100 * 43.38, SCREEN_WIDTH / 100 * 43.38};
	render_figure_color(outlineRect, OUTLINE_RECT, EMPTY);

	SDL_Rect line = {SCREEN_WIDTH * 0.75, 0, SCREEN_WIDTH * 0.25, SCREEN_HEIGHT};
	render_figure_color(line, LEFT, FULL);

	SDL_Rect menu_rect = {SCREEN_WIDTH * 0.76, SCREEN_HEIGHT * 0.7, SCREEN_WIDTH * 0.23, SCREEN_WIDTH * 0.1595};
	render_figure_color(menu_rect, OUTLINE_RECT, EMPTY);

	SDL_Rect info_rect = {SCREEN_WIDTH * 0.76, SCREEN_HEIGHT * 0.018, SCREEN_WIDTH * 0.23, SCREEN_WIDTH * 0.373};
	render_figure_color(info_rect, OUTLINE_RECT, EMPTY);
	loadText();
	SDL_RenderPresent(g_Renderer);
}
