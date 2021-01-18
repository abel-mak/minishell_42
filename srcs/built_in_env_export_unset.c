/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env_export_unset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <asaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:34:10 by asaadi            #+#    #+#             */
/*   Updated: 2021/01/18 19:12:26 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	count_vars_env(char **env_list)
{
	int count;

	count = 0;
	if (!env_list)
		return (0);
	while (env_list[count])
		count++;
	return (count);
}

char	**unset_function(char **envp, char *var_to_remove)
{
	char **new_envp;
	char **equ_split;
	int	len;
	int i;
	int j;

	len = count_vars_env(envp);
	i = 0;
	j = 0;
	if (!(new_envp = (char **)malloc(sizeof(char*) * len - 1)))
		return (NULL);
	while (envp[i])
	{
		equ_split = ft_split(envp[i], '=');
		if (strncmp(equ_split[0], var_to_remove, ft_strlen(equ_split[0])) != 0)
			new_envp[j++] = envp[i];
		i++;
		ft_free_2dem_arr(equ_split);
	}
	new_envp[j] = NULL;
	return (new_envp);
}