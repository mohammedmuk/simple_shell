#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - main function
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return: 0 it is always success
 */

int main(int argc, char **argv)
{
	char *str = NULL;
	size_t len = 0;
	char *strtk;
	pid_t my_pid;
	int status;
	struct stat sm;
	char *args[50];

	if (argc == 1)
	{
		while (1)
		{
		printf("$ ");
		getline(&str, &len, stdin);
		strtk = strtok(str, "\n");

		 args[0] = strtk;
		 args[1] = NULL;
		if (stat(strtk, &sm) == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				perror("Error\n");
				return (1);
			}
			else if (my_pid == 0)
				execve(args[0], args, NULL);
			else
				wait(&status);

		}
		else
			printf("%s: No such file or directory\n", argv[0]);

	}
	}
	return (0);
}
