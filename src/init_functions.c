/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:58:07 by wanton            #+#    #+#             */
/*   Updated: 2020/07/29 15:25:18 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/*
**This function init struct t_map
**
** player - symbol which we will play, default value is 'O'. Later can be
** replace on 'X'
*/

t_map		*init_map()
{
	t_map	*tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	tmp->player = 'O';
	tmp->m = 0;
	tmp->n = 0;
	tmp->map = NULL;
	return (tmp);
}

/*
**This function init struct t_token
*/

t_token		*init_token()
{
	t_token		*tmp;
	
	if (!(tmp = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	tmp->m = 0;
	tmp->n = 0;
	tmp->token = NULL;
	return (tmp);
}