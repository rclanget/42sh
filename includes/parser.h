/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:12:01 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/19 22:03:03 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define PARENTHESES_VAL 9

# define C_SPACE 		 1
# define C_CMD 			 2
# define C_ARG 			 3
# define C_FILE 		 4
# define C_CHEV_R 		 5
# define C_CHEV_L 		 6
# define C_PARENTHESE 	 7
# define C_BRACKET 		 8
# define C_PIPE 		 9
# define C_AMP 			 10
# define C_SEMICOL 		 11

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

char					*clean_parentheses(char *str, int *value);
char					*clean_backslash(char *str);

int						is_operator(char cmd);
void					skip_space(char *cmd, int *i);
int						*definition_code(char *cmd);

int						*get_operator(char *cmd);
int						*get_cmd(char *cmd, int *codes);
int						*get_arg(char *cmd, int *codes);
int						*get_file(char *cmd, int *codes);
int						*get_quote(char *cmd, int *codes);

extern t_parse g_parse[];

#endif
