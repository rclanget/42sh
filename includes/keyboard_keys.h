/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:34:55 by zipo              #+#    #+#             */
/*   Updated: 2016/11/15 14:55:07 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_KEYS_H
# define KEYBOARD_KEYS_H

# define MYKEY_RIGHT		4414235
# define MYKEY_LEFT			4479771

# define CTRL_A				1
# define CTRL_E				5

# ifdef __APPLE__
#  define KEY_END			4610843
#  define KEY_START			4741915
# endif

# ifdef __linux__
#  define KEY_END			4607771
#  define KEY_START			4738843
# endif

# define KEY_DEL			127
# define KEY_SUPP			2117294875

# define CTRL_U				21
# define CTRL_L				12
# define CTRL_K				11

# define CTRL_R				18

# ifdef __APPLE__
/*
** Apple Control replaced by the combinaison of alt+shift
*/
#  define CTRL_UP			18348861490813723
#  define CTRL_DOWN			18630336467524379
#  define CTRL_RIGHT		18911811444235035
#  define CTRL_LEFT			19193286420945691
# endif

# ifdef __linux__
#  define CTRL_UP			71696882162459
#  define CTRL_DOWN			72796393790235
#  define CTRL_RIGHT		73895905418011
#  define CTRL_LEFT			74995417045787
# endif

# ifdef __APPLE__
#  define CTRL_I				8948194
#  define CTRL_O				42947
#  define CTRL_P				10127586
# endif

# ifdef __linux__
#  define CTRL_I				8948194
#  define CTRL_O				42947
#  define CTRL_P				10127586
# endif

# define KEY_UP				4283163
# define KEY_DOWN			4348699

# define TAB				9

#endif
