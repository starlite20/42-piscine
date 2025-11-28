/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:50:18 by khassan           #+#    #+#             */
/*   Updated: 2025/07/13 21:18:49 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUPPORT_H
# define FT_SUPPORT_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_VAL 4

int		**allocate_array(void);
int		**split_input(char *str);
int		is_row_left_good(int **res, int **input, int row);
int		is_row_right_good(int **res, int **input, int row);
int		is_col_up_good(int **res, int **input, int col);
int		is_col_down_good(int **res, int **input, int col);
int		check_all_input_vals(int **res, int **input);
void	ft_putstr(char *str);
void	print_result_array(int **result_arr);
int		ft_strlen(char *str);
int		is_valid_numeric(char c);
int		check_input_validity(char *input_str);

#endif
