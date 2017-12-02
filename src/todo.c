/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:45:18 by adaly             #+#    #+#             */
/*   Updated: 2017/12/02 13:01:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

/*
**FT_RAYCAST
**
**MAKE A RAYCASTING FUNCTION THAT TAKES IN THE COORDINATES OF AN ORIGIN POINT,
**AND THE DIRECTION TO SHOOT THE RAY IN, AND RETURN AN ARRAY OF ALL THE OBJS
**INTERSECTED UNTIL THE RAY EITHER HITS A WALL OR SOMETHING TOTALLY OPAQUE.
**THE ARRAY SHOULD ALSO CONTAIN THE RELEVANT INFORMATION ABOUT WHERE EACH OBJ
**WAS HIT, FOR TEXTURING PURPOSES. THIS CAN BE DONE BY USING THE T_RAY STRUCT.
**
**
**FT_RAYDRAW
**
**THIS FUNCTION SHOULD BE MODIFIED TO TAKE IN THE ARRAY OF INTERSECTIONS,
**WHICH SHOULD BE INCLUDED IN THE T_RAY STRUCT, AND REPEAT THE DRAWING
**PROCESS FOR EACH INTERSECTION. FOR PERSPECTIVE ACCURACY, THE RESULTS OF
**THE RAYCASTING PROCEDURE, WHICH FIND THE DISTANCE AND LINEHIGHT FOR EACH
**RAY, WILL NEED TO BE DONE FOR EACH INTERSECTION, AND EVERY VALUE WILL NEED
**TO BE STORED INDIVIDUALLY SO THAT EACH OBJECT'S SIZE ON SCREEN IS STILL
**CONSISTENT WITH THE DISTANCE FROM THE PLAYER, EVEN IF MULTIPLE TRANSLUCENT
**OBJECTS ARE ALIGNED.
*/
