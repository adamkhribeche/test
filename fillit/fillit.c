/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:54:17 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/18 18:49:15 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_rm_tetri_from_board(t_board *board, t_tetrimino tetrimino, int position)
{
	int k;
	int i;
	int j;

	i = position / board->size;
	j = position % board->size;
	k = -1;
	while (++k < 4)
		board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] = '.';
}
//---------------------------
void	ft_free_board(t_board **board)// pour que je puiss mettre le pointeur a NULL
{
	int i;

	i = 0;
	while ((*board)->size--)
		free((*board)->board[i++]);
	free((*board)->board);
	free(*board);
	*board = NULL;
}
//-------------------
int		ft_add_tetri_to_board(t_tetrimino tetrimino, t_board *board, int position)// pour qu'on puiss modifier board
{
	int		i;
	int		j;
	int		k;

	i = position / board->size;
	j = position % board->size;
	k = -1;
	while (++k < 4)
	{
		if ((tetrimino.tab[k].x + j < board->size) && (tetrimino.tab[k].y + i < board->size) &&
				board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] == '.')
			continue ;
		else
			return (0);
	}
	k = -1;
	while (++k < 4)
		board->board[i + tetrimino.tab[k].y][j + tetrimino.tab[k].x] = 65 + tetrimino.order;
	return (1);
}
//------------------
/*int		ft_is_all_tetri_exist(int *is_order_exist, int nbr_of_tetris)
{
	int i;

	i = 0;
	while (i < nbr_of_tetris)
	{
		if (!is_order_exist[i])
			return (0);
		i++;
	}
	return (1);
}*/

int		ft_fill_is_done(t_tetrimino *tetris_tab, int nbr_of_tetris, int order, t_board *board)
{
	int			pt_nbr;
	int			pt_max;

	pt_nbr = 0;
	//order = 0;
	if (order == nbr_of_tetris)
		return (1);
	pt_max = board->size * board->size;
	while (pt_nbr < pt_max)// there is at lest one tetris no in board 
	{
		//printf("----------\n");
		if (ft_add_tetri_to_board(tetris_tab[order], board, pt_nbr))
		{
			system("clear");//-------------------
			ft_display_board(*board);//-------------------------------
			ft_putchar('\n');
			usleep(1000);//-------------------------------
			if (ft_fill_is_done(tetris_tab, nbr_of_tetris, order + 1,  board))
				return (1);
			ft_rm_tetri_from_board(board, tetris_tab[order], pt_nbr);
		}
		pt_nbr++;
	}
	return (0);
}
//---------------------------------
void	ft_display_in_small_board(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	t_board	*board;
	int		size;

	size = 2;
	while (size * size < nbr_of_tetris * 4)
		size++;
	ft_shift_all_tetriminos(tetris_tab, nbr_of_tetris);
	board = ft_creat_new_board (size);
	while (!(ft_fill_is_done(tetris_tab, nbr_of_tetris, 0, board))) // 0 == order
	{
		ft_free_board(&board);
		board = ft_creat_new_board(++size);
	}
	ft_display_board(*board);
}
//---------------------------
int		ft_minx(t_tetrimino tetrimino)
{
	int min;
	int i;

	min = 3;
	i = -1;
	while (++i < 4)
	{
		if (tetrimino.tab[i].x < min)
			min = tetrimino.tab[i].x;
	}
	return (min);
}
//--------------------------------
int		ft_miny(t_tetrimino tetrimino)
{
	int min;
	int i;

	min = 3;
	i = -1;
	while (++i < 4)
	{
		if (tetrimino.tab[i].y < min)
			min = tetrimino.tab[i].y;
	}
	return (min);
}
//--------------------------------
void	ft_subtract_from_coord(t_tetrimino *tetrimino, int i, int j)
{
	int index;

	index = -1;
	while (++index < 4)
	{
		(*tetrimino).tab[index].x -= i;
		(*tetrimino).tab[index].y -= j;
	}
}
//---------------------------------------
void	ft_shift_all_tetriminos(t_tetrimino *tetris_tab, int nbr_of_tetris)
{
	int i;
	int j;
	int index;

	index = 0;
	while (nbr_of_tetris--)
	{
		i = ft_minx(tetris_tab[index]);
		j = ft_miny(tetris_tab[index]);
		ft_subtract_from_coord(&tetris_tab[index], i, j);
		index++;
	}
}
//----------------------------------------
t_board		*ft_creat_new_board(int size)//sinc I want to assigne a value to **board
{
	int		i;
	int		j;
	t_board *board;

	board = (t_board*) ft_memalloc(sizeof(*board));
	board->board = (char**) ft_memalloc(size * sizeof(char*));
	i = 0;
	while (i < size)
	{
		board->board[i] = (char*) ft_memalloc(size * sizeof(char));
		j = 0;
		while (j < size)
		{
			board->board[i][j] = '.';
			j++;
		}
		i++;
	}
	board->size = size;
	return (board);
}
//----------------------------------------
void	ft_display_board(t_board board)
{
	int		i;
	int		j;

	i = 0;
	while (i < board.size)
	{
		j = 0;
		while (j < board.size)
		{
			ft_putchar(board.board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
//---------------------------------------------
int		ft_check_input(char *buff)
{
	int		i;
	int		contact;
	int		point;

	contact = 0;
	point = 0;
	i = -1;
	if (!buff)
		return (0);
	while (++i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else
		{
			if (buff[i] == '.')
				point++;
			else if (buff[i] == '#')
			{
				if (i > 0 && buff[i - 1] == '#')
					contact++;
				if (i < 19 && buff[i + 1] == '#')
					contact++;
				if (i < 14 && buff[i + 5] == '#')
					contact++;
				if (i > 4 && buff[i - 5] == '#')
					contact++;
			}
			else
				return (0);
		}
	}
	return (point == 12 && (contact == 6 || contact == 8) && (buff[20] == '\n' || buff[20] == '\0'));
}
//-----------------------------------------------
void	ft_add_to_tab(t_tetrimino *tetri_tab, int order, char *buff)
{
	int		position;
	int		i;

	i = 0;
	position = -1;
	while (buff[++position])
	{
		if (buff[position] == '#')
		{
			tetri_tab[order].tab[i].x = position % 5;
			tetri_tab[order].tab[i].y = position / 5;
			tetri_tab[order].order = order;
			i++;
		}
	}
}

int		ft_receive_in_tab(int fd, t_tetrimino *tetri_tab)
{
	char			buff[22];
	ssize_t			ret;
	int				order;

	order = -1;
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		order++;
		if (order > 25)
			return (0);
		buff[ret] = '\0';
		if (!ft_check_input(buff))
			return (0);
		ft_add_to_tab(tetri_tab, order, buff);
	}
	if (ret == 0 && buff[20] != '\0') //gerer le dernier ligne
		return (0);
	return (order + 1);
}

int		main(int ac, char **av)
{
	int				fd;
	t_tetrimino		tetris_tab[26];
	int				nbr_of_tetris;

	if (ac != 2)
		ft_putstr("usage: fillit file_name\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(nbr_of_tetris = ft_receive_in_tab(fd, tetris_tab)))
			ft_putstr("error\n");
		else 
			ft_display_in_small_board(tetris_tab, nbr_of_tetris);
	}
	return (0);
}
