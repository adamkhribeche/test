/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:55:55 by nkhribec          #+#    #+#             */
/*   Updated: 2019/05/25 05:41:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "get_next_line.h"

typedef struct		s_tetrimino
{
	char 			tab[17];
	int				height;
	int				width;
	int				nbr_of_block;
	int				nbr_of_contact;
}					t_tetrimino;


#endif
