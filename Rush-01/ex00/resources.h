/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:38:30 by agarbacz          #+#    #+#             */
/*   Updated: 2024/09/01 22:27:52 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int	**grid;
	int	**requirements;
	int	n;
	int	found_valid_grid;
}		t_grid_data;

// mallocs
int		count_nums(char *str);
int		get_inp_size(int res);
int		**alloc_grid(int arr_size);
int		**alloc_req(int arr_size);
void	export_req(char *input, t_grid_data *data);

// grid population
void	print_grid(t_grid_data *data);
int		is_grid_valid(t_grid_data *data);

// permutation
bool	check_line_dups(t_grid_data *data, int row, int col, int num);
void	generate_permutations(t_grid_data *data, int row, int col);

// check validity
bool	check_duplicates(int *line, int n);
bool	check_visibility(int *line, int requirement, int n);
int		check_upper_side(t_grid_data *data, int id_of_line, int id_of_side);
int		check_lower_side(t_grid_data *data, int id_of_line, int id_of_side);
int		check_left_side(t_grid_data *data, int id_of_line, int id_of_side);
int		check_right_side(t_grid_data *data, int id_of_line, int id_of_side);
int		check_all_sides(t_grid_data *data, int id_of_line, int id_of_side);
int		check_side(t_grid_data *data, int id_of_line, int id_of_side);
int		solve_grid(t_grid_data *data);
void	handle_grid(t_grid_data *data, int row, int col);

#endif