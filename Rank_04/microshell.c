/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:39:07 by jalcausa          #+#    #+#             */
/*   Updated: 2025/06/15 18:59:31 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int p_err(const char *src)
{
	
}

int cd(char **argv, int i)
{
	
}

int exec(char **argv, char **env, int i)
{
	
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	int status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			// Procesamos los comandos de uno en uno, es decir, hasta que se encuentre
			// un |, un ; o se acaba la entrada del usuario
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				++i;
			if (!strmcp(*argv, "cd")) // Returns 0 if they are equal
				status = cd(av, i);
			else if (i)
				status = exec(argv, env, i);
		}
	}
	return(status);
}