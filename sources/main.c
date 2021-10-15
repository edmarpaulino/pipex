#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER 256

int	main(void)
{
	int		fd[2]; // File descriptors pro Pipe
	pid_t	pid; // Variávels para armazenar o PID

	// Criando nosso Pipe
	if (pipe(fd) < 0)
	{
		perror("pipe");
		return (-1);
	}

	// Criando o processo filho
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}

	// Processo pai
	if (pid > 0)
	{
		// No pai, vamos ESCREVER, então vamos fechar a LEITURA
		// do pipe neste lado
		close(fd[0]);

		char	str[BUFFER] = "Aprendi a usar Pipes em C!";
		printf("String enviada pelo pai no Pipe: '%s'\n", str);

		// Escrevendo a string no pipe
		printf("%lu\n", sizeof(str));
		write(fd[1], str, sizeof(str));
		exit(0);
	}
	else // Processo filho
	{
		char	str_recebida[BUFFER];

		// No filho, vamos ler. Então vamos fechar a entrada de ESCRITA do pipe
		close(fd[1]);

		// Lendo o que foi escrito no pipe, e armazenando isso em 'str_recebida'
		read(fd[0], str_recebida, sizeof(str_recebida));

		printf("String lida pelo filho no Pipe: '%s'\n\n", str_recebida);
		exit(0);
	}
	return (0);
}
