/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:39:07 by jalcausa          #+#    #+#             */
/*   Updated: 2025/06/16 13:33:50 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int p_err(const char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int cd(char **argv, int i)
{
	if (i != 2)
		return (p_err("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (p_err("error: cd: cannot change directory to "), p_err(argv[1]), p_err("\n"));
	return (0);
}

int exec(char **argv, char **env, int i)
{
	int status;
	int fd[2];
	int has_pipe;

	if (argv[i] && !strcmp(argv[i], "|"))
		has_pipe = 1;
	else
		has_pipe = 0;
	
	if (has_pipe && pipe(fd) == -1) // Se crea el pipe y si falla se devuelve error
		return p_err("error: fatal\n");
	
	int pid = fork();

	if (pid == -1)
		return p_err("error: fatal\n");

	if (!pid ) // Código que ejecuta el hijo
	{
		// Ponemos a null la última pos porque execve espera un array acabado en null
		// En esa posición es donde estaba el | o el ;, si es el último comando ya estaba a null
		argv[i] = 0; 
		// Cambiamos el fd de salida estándar al extremo de escritura del pipe para que execve
		// escriba la salida del comando en el pipe en lugar de hacerlo en la salida estándar
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1 ))
			return p_err("error: fatal\n");
		execve(argv[0], argv, env);
		return (p_err("error: cannot execute "), p_err(argv[0]), p_err("\n")); // Solo se ejecuta si falla el execve
	}
	waitpid(pid, &status, 0); // Esperamos a que termine el hijo
	// Desde el padre ahora cambiamos el fd de lectura estándar para que el próximo comando lea la salida del comando
	// anterior del pipe
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1 ))
		return p_err("error: fatal\n");
	// 
	if (WIFEXITED(status)) // verifica que el proceso hijo terminó normalmente
		return(WEXITSTATUS(status)); // extrae el código de salida del proceso hijo
	else
		return (1);
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
			if (!strcmp(*argv, "cd")) // Returns 0 if they are equal
				status = cd(argv, i);
			else if (i)
				status = exec(argv, env, i);
		}
	}
	return(status);
}