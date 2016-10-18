/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:12:01 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 13:00:14 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct			s_tree
{
	int					type;
	char				*elem;
	char				**cmd;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

typedef struct			s_parse
{
	int					type;
	int					(*check)(char *);
	char				**(*parse)(char *, int pos);
}						t_parse;

t_tree					*parser_cmd(char *cmd);

char					*ft_strtrimb(char *s);
char					*ft_strndup(char *str, int len);
int						check_hightest(char *cmd, int type);
char					**split_on(char *cmd, int pos, int type);

int						check_op_comma(char *str);
char					**parse_op_comma(char *str, int pos);

int						check_op_parentheses(char *str);
char					**parse_op_parentheses(char *str, int pos);

int						check_op_right(char *str);
char					**parse_op_right(char *str, int pos);
int						check_op_dright(char *str);
char					**parse_op_dright(char *str, int pos);

int						check_op_left(char *str);
char					**parse_op_left(char *str, int pos);
int						check_op_dleft(char *str);
char					**parse_op_dleft(char *str, int pos);

int						check_op_and(char *str);
char					**parse_op_and(char *str, int pos);
int						check_op_or(char *str);
char					**parse_op_or(char *str, int pos);

int						check_op_pipe(char *str);
char					**parse_op_pipe(char *str, int pos);

int						check_op_rightfd(char *str);
char					**parse_op_rightfd(char *str, int pos);

void					*parser_free_cmd(t_tree *cmd);

extern t_parse g_parse[];

#endif
