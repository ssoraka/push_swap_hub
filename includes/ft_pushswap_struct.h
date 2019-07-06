/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:13:28 by ssoraka           #+#    #+#             */
/*   Updated: 2019/05/22 13:13:28 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_STRUCT_H
# define FT_PUSHSWAP_STRUCT_H

typedef struct		s_elem
{
	int				value;
	int				medium_value;
	int				min_value;
	int				max_value;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

#endif
